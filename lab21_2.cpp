#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *A,Rect *B){
	Rect coor;
	if((A->x+A->w) > B->x){
		coor.x = B->x;
		coor.w = (A->x+A->w) - B->x;
		if(A->x+A->w>B->x+B->w){
			coor.w = B->w;
		}
	}else if((A->x+A->w) <= B->x){
		coor.w = 0;
		coor.x = 0;
	}

	if(B->y > A->y-A->h){
		coor.y = A->y;
		coor.h = A->y-(B->y-B->h);
		if((A->y-A->h)<(B->y-B->h) && A->y > B->y){
			coor.y = B->y;
			coor.h = B->h;
		}
	}else if((A->x+A->w) <= B->x){
		coor.y = 0;
		coor.h = 0;
	}
	return coor.w*coor.h;
}
