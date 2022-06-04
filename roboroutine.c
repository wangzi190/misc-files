#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port6,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           servoMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)

//NOTE: The left motor is configured in a way where setting its speed to negative will cause it to go forward and vice versa.

/************************************** Function Definitions **************************************/
void swingTurns() { //Robot performs a series of swing turns
	motor[rightMotor] = 0;
	motor[leftMotor]  = 127; //Reverse left motor
	wait1Msec(750); //750 millisecond turn

  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //Pause for 500 milliseconds

	motor[rightMotor] = 127; //Right motor spins forward
	motor[leftMotor]  = 0;
	wait1Msec(750); //750 millisecond turn

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //Pause for 500 milliseconds

	motor[rightMotor] = -127; //Reverse right motor
	motor[leftMotor]  = 0;
	wait1Msec(750); //750 millisecond turn

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //Pause for 500 milliseconds

	motor[rightMotor] = 0;
	motor[leftMotor]  = -127; //Left motor spins forward
	wait1Msec(750); //750 millisecond turn

  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //Pause for 500 milliseconds
}

void turnRight() { //Robot turns right
	motor[rightMotor] = -127;
	motor[leftMotor]  = -127;
	wait1Msec(750);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //500 millisecond pause after turn
}

void turnLeft() { //Robot turns left
	motor[rightMotor] = 127;
	motor[leftMotor]  = 127;
	wait1Msec(750);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //500 millisecond pause after turn
}

void moveForward() { //Robot moves foward
	motor[rightMotor] = 127;
	motor[leftMotor]  = -127;
	wait1Msec(1000);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //500 millisecond pause after turn
}

void moveBackward() { //Robot moves backward
	motor[rightMotor] = -127;
	motor[leftMotor]  = 127;
	wait1Msec(1000);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //500 millisecond pause after turn
}

void backForth() { //Robot scoots forward three times, and then back three times
	int a = 0;
	int b = 0;
	int c = 0; //Lines 84 through 86 declare variables a, b, & c, and assign a value of 0 to each variable
	while (a < 2) { //Statements in the brackets are iterated until a < 2

		while (b < 3) { //Statements within the brackets are iterated until b < 3
			motor[rightMotor] = 90;
			motor[leftMotor]  = -90;
			wait1Msec(220); //Robot moves forwards for 220 milliseconds

			motor[rightMotor] = 0;
			motor[leftMotor]  = 0;
			wait1Msec(140); //Robot stops for 140 milliseconds
			b++; //Increases b by 1 at the end of the loop
		}

		wait1Msec(200);

		while (c < 3) { //Statements in the brackets are iterated until c < 3
			motor[rightMotor] = -90;
			motor[leftMotor]  = 90;
			wait1Msec(220); //Robot moves backwards for 220 milliseconds

			motor[rightMotor] = 0;
			motor[leftMotor]  = 0;
			wait1Msec(140); //Robot stops for 140 milliseconds
			c++; //Increases c by 1 at the end of the loop
		}

		a++; //Increases a by 1 at the end of the loop
	}
}

void sequenceA() { //Steps in the routine I have called "Sequence A"
	int a = 0;
	while (a < 2) {
		motor[servoMotor] = -40 - 10*a; //This usage of variable a in speed setting sets the servo motor's speed 10 units less per iteration
		motor[claw] = -70; //Setting motor speeds and then calling function moveFoward allows the servo and claw motors to be moving while the robot moves forward

		moveForward();

		motor[servoMotor] = 40;
		motor[claw] = 70; //Reverse claw and servo motors

		moveBackward();

		motor[servoMotor] = 0;
		motor[claw] = 0; //Pause claw and servo motors

		turnLeft();
		a++;
	}
	int b = 0;
	while (b < 2) {
		motor[servoMotor] = -40 - 10*b; //This usage of variable a in speed setting sets the servo motor's speed 10 units less per iteration
		motor[claw] = -70; //Setting motor speeds and then calling function moveBackward allows the servo and claw motors to be moving while the robot moves backwards

		moveBackward();

		motor[servoMotor] = 40;
		motor[claw] = 70; //Reverse claw and servo motors

		moveForward();

		motor[servoMotor] = 0;
		motor[claw] = 0; //Pause claw and servo motors

		turnRight();
		b++;
	}
}

void sequenceB() { //Steps in the routine I have called "Sequence B"
	motor[servoMotor] = -75;
	motor[claw] = -70;
	wait1Msec(1500); //Takes 1500 milliseconds to open the claw and raise the arm

	motor[servoMotor] = 0;
	motor[claw] = 0; //Sets claw and servo motors to zero before performing swing turns

	swingTurns();

	motor[rightMotor] = -127;
	motor[leftMotor]  = -127;
	wait1Msec(2*1825); //Performs point turn to the right for 2*1825 milliseconds

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //Pauses 500 milliseconds

	motor[claw] = 70; //Closes the claw

	motor[rightMotor] = 127;
	motor[leftMotor]  = 127;
	wait1Msec(1825); //Performs point turn to the left for 1825 milliseconds

	motor[claw] = 0; //Pauses claw motor after left point turn

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500); //Pauses 500 milliseconds
}

/************************************** Main Program **************************************/

task main() {
	repeat(2) {
		motor[claw] = 70; //Closes claw

		repeat(3) { //Moves the robot back and forth three times
			backForth();
			wait1Msec(210);
		}
		motor[claw] = 0; //Sets claw motor speed to zero once it is closed

		sequenceA();
		sequenceB(); //Performing Sequence B involves the robot moving its arm up

		motor[servoMotor] = 40; //Moves arm down from its upwards position

		repeat(2) { //Moves the robot back and forth two times
			backForth();
			wait1Msec(210);
		}
		motor[servoMotor] = 0; //Sets servo motor to zero

		sequenceA();
	}
}
