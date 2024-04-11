// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double pi=acos(-1);
const double eps=1e-6;
int sgn( double x ) { return /*printf("x=%.20f\n",x),*/(x>eps)-(x<-eps); }
int cmp( double a, double b ) { return sgn(a-b); }
bool eq( double a, double b ) { return sgn(a-b)==0; }
struct P {
	double x,y;
	P(){}
	P( double _x, double _y ):x(_x),y(_y){}
	void read() { scanf("%lf%lf",&x,&y); }	
	double len2() { return x*x+y*y; }
	void print() { printf("(%f,%f)\n",x,y); }
};
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
double operator *( P a, P b ) { return a.x*b.y-a.y*b.x; }
double operator ^( P a, P b ) { return a.x*b.x+a.y*b.y; }
P operator /( P a, double b ) { return P(a.x/b,a.y/b); }
double X( P o, P a, P b ) { return (a-o)*(b-o); }
double dis2( P a, P b ) { return (a-b).len2(); }
double ang( P a ) { return atan2(a.y,a.x); }
double adj_ang( double a ) {
	while ( a<0 ) a+=2*pi;
	while ( a>=2*pi ) a-=2*pi;
	if ( a>pi ) a=2*pi-a;
	return a;
}
double ang_dis( P o, P a, P b ) { return adj_ang(ang(a-o)-ang(b-o)); }
struct Tri {
	P a,b,c;
	void read() { a.read(); b.read(); c.read(); }
	double area() { return X(a,b,c)/2; }
	P c_center() {
		double i,j,k;
		i=(b-c).len2()*((a-b)^(a-c));
		j=(a-c).len2()*((b-c)^(b-a));
		k=(a-b).len2()*((c-a)^(c-b));
		return P(i*a.x+j*b.x+k*c.x,i*a.y+j*b.y+k*c.y)/(8*area()*area());
	}	
} tri;
bool fdiv( double a, double b ) { return eq(fmod(b,a),0) || eq(fmod(b,a),a); }
bool chk( P o, Tri t, int n ) {
	double d=2*pi/n;
	double d1=ang_dis(o,t.a,t.b);
	double d2=ang_dis(o,t.b,t.c);
	double d3=ang_dis(o,t.c,t.a);
	//printf("%d: %f,%f,%f,%f\n",n,d,d1,d2,d3);
	return fdiv(d,d1) && fdiv(d,d2) && fdiv(d,d3);
}
double cal( double r2, int n ) { return n*0.5*r2*sin(2*pi/n); }
int main()
{
	tri.read();
	P o=tri.c_center();
	//o.print();
	for ( int i=3; i<=100; i++ )
		if ( chk(o,tri,i) ) {
			printf("%.10f\n",cal(dis2(o,tri.a),i));
			break;
		}
	return 0;
}