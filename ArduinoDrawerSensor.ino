//int Door_Led_Pin = 13;   // choose the pin for the LED
int Door_Sensor_Pin = 6; // choose the Door_Sensor_Pin
int val = 0;   // variable for reading the Door_Sensor_Pin status
int delaying = 0;

//Play melody
int speakerPin = 13;

int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 200;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
 
void setup() {
  //pinMode(Door_Led_Pin, OUTPUT);    // declare Door_Led_Pin as output
  pinMode(Door_Sensor_Pin, INPUT);  // declare Door_Sensor_Pin as input
  pinMode(speakerPin, OUTPUT); // declare speakerPin as output
}
 
void loop()
{
  val = digitalRead(Door_Sensor_Pin);  // read Door_Sensor_Pin
  if (val == HIGH) 
  {
    if (delaying == 0)
    {
      delay(10000);
      delaying = 1;
    }
    else if (delaying != 0)
    {
      //do nothing....
    }
        
        for (int i = 0; i < length; i++) {
        if (notes[i] == ' ') {
          delay(beats[i] * tempo); // rest
        } else {
          playNote(notes[i], beats[i] * tempo);
        }

        // pause between notes
        delay(tempo / 2);
        }
  }
  else 
  {
    digitalWrite(speakerPin, LOW);  //Set Door_Led high
    delaying = 0;
  }
}
