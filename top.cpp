#include <stdlib.h> 
#include <math.h> 
#include <stdio.h> 
#include <cstdlib>
#include <cmath>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define ESC 27
#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)
#include <string>
#include <iostream>

class Top{

	public:

		void drawTop(int topAngle){
			glPushMatrix();
			glScalef(2,2,2);
			glRotatef(topAngle,0,0,1);
			
			glColor3f(7.0/244, 89.0/244, 26.0/244);
			glutSolidTorus( 0.2,0.3, 100,100);

			/*glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(0,0,1);
			glEnd();*/

			glPushMatrix();
				glTranslatef(0,0,-0.3);
				glRotatef(180,0,1,0);
				glutSolidCone(0.5, 0.8, 10, 2);
			glPopMatrix();

			glColor3f(1.0, 0.5, 0.0);
			glutWireTorus( 0.2,0.5, 25, 20);
			glColor3f(1.0, 0.5, 0.0);
			glTranslatef(0,0,-0.3);
			glutSolidTorus( 0.05,0.7, 25, 30);
			glColor3f(0,0,0);	
		glPopMatrix();
		}

		//display power bar
		void drawBar(float velocity){
			glScalef(2,2,2);
			glTranslatef(32,0,25);
			glRotatef(90,0,0,0);
			for ( float i = 0; i < velocity; i++)
			{
				glColor3f(1.0, 1-i/velocity, 0.0);
				glTranslatef(0, 0, -0.5);
				drawCylinder(0.7);
			}
		}

		void drawCylinder(float rad){

			for (int i = 0; i < 20; ++i)
			{
				glTranslatef(0,0,-0.05);
			   	glutSolidTorus( 0.3,0.5, 10,10);
			}
		}

		int checkBoundary(float x, float z){

			if (x > 2 && x < 60 && z > 2 && z < 60)
				return 1;
			else
				return 0;
		}

		void drawArrow(int angle){

			glPushMatrix();
			glColor3f(188.0/244, 188.0/244, 188.0/244);
			glTranslatef(-8,0,40);
			glRotatef(180, 1, 0 , 0);
			glRotatef(angle, 0, 1, 0);
			glutSolidCone(1.5, 8, 10, 2);
			drawCylinder(2);
			glPopMatrix();

		}

		int getTarget(){

			int a = rand()%45 + 5;
			//printf("%d\n", a);
			return a;

		}

		void drawTarget(int x, int y, int z){

			glPushMatrix();
			glRotatef(90, 1, 0, 0);
			glTranslatef(x, z, (-1*y)-2);
			glColor3f(7.0/244, 36.0/244, 87.0/244);
			glutSolidTorus( 0.3,2, 100,10);
			glPopMatrix();
		}

		int checkTarget(float x, float y, float a, float b){

			if((x-a)*(x-a) + (y-b)*(y-b) <= 1)
				return 1;
			else 
				return 0;

		}

};