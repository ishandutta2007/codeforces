// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct P {
	int x,y;
	P( int _x=0, int _y=0 ):x(_x),y(_y){}
	void read() { scanf("%d%d",&x,&y); }
	int len2() { return x*x+y*y; }
	double len() { return sqrt(len2()); }
} p[3];
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
P operator +( P a, P b ) { return P(a.x+b.x,a.y+b.y); }
double dis( P a, P b ) { return (a-b).len(); }
double sqr( double x ) { return x*x; }
const double eps=1e-6;
bool eq( double a, double b ) { return fabs(a-b)<eps; }
bool is_right() {
	double a[3];
	for ( int i=0; i<3; i++ ) a[i]=dis(p[i],p[(i+1)%3]);
	sort(a,a+3);
	return !eq(a[0]+a[1],a[2]) && eq(sqr(a[0])+sqr(a[1]),sqr(a[2]));
}
int main()
{
	for ( int i=0; i<3; i++ ) p[i].read();
	if ( is_right() ) {
		puts("RIGHT");
		return 0;
	} else {
		for ( int i=0; i<3; i++ ) {
			for ( int dx=-1; dx<=1; dx++ )
				for ( int dy=-1; dy<=1; dy++ ) if ( !(dx&&dy) ) {
					p[i]=p[i]+P(dx,dy);
					if ( is_right() ) {
						puts("ALMOST");
						return 0;
					}
					p[i]=p[i]-P(dx,dy);
				}
		}
	}
	puts("NEITHER");
	return 0;
}