// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct P {
	double x,y;
	P( double _x=0, double _y=0 ):x(_x),y(_y){}
	bool read() { return scanf("%lf%lf",&x,&y)!=EOF; }
	double len2() { return x*x+y*y; }
	double len() { return sqrt(len2()); }
};
P operator +( P a, P b ) { return P(a.x+b.x,a.y+b.y); }
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
P operator *( double a, P b ) { return P(a*b.x,a*b.y); }
P operator /( P a, double b ) { return P(a.x/b,a.y/b); }
double dis( P a, P b ) { return (a-b).len(); }
struct C {
	P o; double r;
	bool read() { return o.read() && scanf("%lf",&r)!=EOF; }
} c[3];
double sqr( double x ) { return x*x; }
double cal( P p ) {
	double ret=0,ang[3],avg;
	for ( int i=0; i<3; i++ ) ang[i]=dis(p,c[i].o)/c[i].r;
	avg=(ang[0]+ang[1]+ang[2])/3;
	for ( int i=0; i<3; i++ ) ret+=abs(ang[i]-avg);
	return ret;	
}
const P dp[]={P(1,0),P(-1,0),P(0,1),P(0,-1)};
bool input() {
	for ( int i=0; i<3; i++ )
		if ( !c[i].read() ) return 0;
	return 1;
}
bool solve( P &p ) {
	p=(c[0].o+c[1].o+c[2].o)/3;
	double now=cal(p),d=1;
	while ( d>1e-8 ) {
		//printf("(%f,%f) now = %.9f\n",p.x,p.y,now);
		bool flg=0;
		for ( int i=0; i<10; i++ ) {
			double da=rand();
			P np=p+d*P(cos(da),sin(da));
			double tmp=cal(np);
			if ( tmp+1e-12<now ) {
				p=np;
				now=tmp;
				flg=1;
			}
		}
		if ( !flg ) d*=0.9;
	}		
	return now<1e-6;
}
int main()
{
	while ( input() ) {
		P p,sum;
		int cnt=0,tmt=30;
		while ( tmt-- ) {
			if ( solve(p) ) {
				cnt++;
				sum=sum+p;
			}
		}
		if ( cnt>0 ) {
			sum=sum/cnt;
			printf("%.5f %.5f\n",sum.x,sum.y);
		}
	}
	return 0;
}