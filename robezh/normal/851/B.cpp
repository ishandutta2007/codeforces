#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;


bool sameslope(int x1, int y1, int x2, int y2, int x3, int y3){
	long long tmp = (long long)(y2-y1) * (x3-x2) - (long long)(y3-y2) * (x2-x1);
	return tmp == 0;
}

bool samedis(int x1, int y1, int x2, int y2, int x3, int y3){
	long long tmp1 = (long long)(x2-x1) * (x2-x1) + (long long)(y2-y1) * (y2-y1) - ((long long)(x3-x2) * (x3-x2) + (long long)(y3-y2) * (y3-y2));
	//cout<<tmp1<<" "<<endl;
	return tmp1 == 0;
}

int main(){
	int xa,ya,xb,yb,xc,yc;
	scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
	//cout<<samedis(xa,ya,xb,yb,xc,yc)<<endl; 
	if(!sameslope(xa,ya,xb,yb,xc,yc) && samedis(xa,ya,xb,yb,xc,yc)){
		printf("Yes");
	}
	else{
		printf("No");
	}
}