#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
	if(x1 == x2) x1++;
	if(y1 == y2) y1++;
	cout << 2 * ((abs(x1-x2) + 1) + (abs(y1-y2) + 1));
}