#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-6
long long a,b,c;
long long sx,sy,tx,ty;
double work_1(){
	double x_1,y_1,x_2,y_2;
	y_1=sy;
	y_2=ty;
	x_1=-(b*1.0/a)*y_1-(c*1.0/a);
	x_2=-(b*1.0/a)*y_2-(c*1.0/a);
	double dist=sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
	return fabs(x_1-sx)+fabs(x_2-tx)+dist;
}
double work_2(){
	double x_1,y_1,x_2,y_2;
	y_1=sy;
	x_2=tx;
	x_1=-(b*1.0/a)*y_1-(c*1.0/a);
	y_2=-(a*1.0/b)*x_2-(c*1.0/b);
	double dist=sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
	return fabs(x_1-sx)+fabs(y_2-ty)+dist;
}
double work_3(){
	double x_1,y_1,x_2,y_2;
	x_1=sx;
	y_2=ty;
	y_1=-(a*1.0/b)*x_1-(c*1.0/b);
	x_2=-(b*1.0/a)*y_2-(c*1.0/a);
	double dist=sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
	return fabs(y_1-sy)+fabs(x_2-tx)+dist;
}
double work_4(){
	double x_1,y_1,x_2,y_2;
	x_1=sx;
	x_2=tx;
	y_1=-(a*1.0/b)*x_1-(c*1.0/b);
	y_2=-(a*1.0/b)*x_2-(c*1.0/b);
	double dist=sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
	return fabs(y_1-sy)+fabs(y_2-ty)+dist;
}
int main(){
	cin>>a>>b>>c;
	cin>>sx>>sy>>tx>>ty;
	if(sx==tx){
		cout<<abs(sy-ty)<<endl;
		return 0;
	}
	if(sy==ty){
		cout<<abs(sx-tx)<<endl;
		return 0;
	}
	if(sx>tx){
		swap(sx,tx);
		swap(sy,ty);
	}
	double ans=1e16;
	ans=min(ans,work_1());
	ans=min(ans,work_2());
	ans=min(ans,work_3());
	ans=min(ans,work_4());
	ans=min(ans,fabs(sy-ty)+fabs(sx-tx));
	printf("%.9lf\n",ans);
	return 0;
}
/*
ax+by+c=0
by=-ax-c
y=-(a/b)x-(c/b)
ax=-by-c
x=-(b/a)y-(c/a)
*/