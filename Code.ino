/*
Automatic Gun Practic Target 1.0.0 for Arduino UNO.
Copyright (c) 2023, Sourceduty

This software is free and open-source; anyone can redistribute it and/or modify it.
*/

#include <VarSpeedServo.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin

VarSpeedServo servo; // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
int Speed = 160;
void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object

  servo.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if(angle == 0)
      angle = 90;


    // control servo motor arccoding to the angle
    servo.write(angle,Speed/2);  
    delay(100);  
    servo.wait();    
    servo.wait();    
    servo.wait();    
    servo.wait();
  }  
  if(lastButtonState == LOW && currentButtonState == HIGH) {
    delay(100); 
    
    Serial.println("The button is released");
    // change angle of servo motor

    if(angle == 90)
      angle = 0;

    // control servo motor arccoding to the angle
    servo.write(angle,Speed);
  }

}
