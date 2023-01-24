/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  io_control("set3=0");
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:

  delay(1);  // delay in between reads for stability
}

void io_control(char *data) {
  Serial.println("inside io control");
  if (strcmp(data, "set") > 0) {
    Serial.println("got set");
    String inString = "";
    bool out_type = LOW;
    if (isDigit(data[3])) { inString += (char)data[3]; }
    if (isDigit(data[4])) {
      inString += (char)data[4];
      if (data[6] == '1') {
        out_type = HIGH;
        Serial.println("set high");
      }else {
        Serial.println("set low");
      }
    } else {
      if (data[5] == '1') {
        out_type = HIGH;
        Serial.println("set high");
      } else {
        Serial.println("set low");
      }
    }
    int a = inString.toInt();
    pinMode(a, OUTPUT);
    digitalWrite(a, out_type);
    Serial.println(a);

  } else {
    Serial.println("wrong command");
  }
}