// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 10010
using namespace std;
const double eps=1e-9;
double sqr( double x ) { return x*x; }
struct P {
	double x,y,z;
	P(){}
	P( double _x, double _y, double _z ):x(_x),y(_y),z(_z){}
	void read() { scanf("%lf%lf%lf",&x,&y,&z); }
	double len2() { return sqr(x)+sqr(y)+sqr(z); }
	double len() { return sqrt(len2()); }
	void print() { printf("%.9f %.9f %.9f\n",x,y,z); }
} p[N],q,now,vec,tmt;
P operator +( P a, P b ) { return P(a.x+b.x,a.y+b.y,a.z+b.z); }
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y,a.z-b.z); }
P operator *( double a, P b ) { return P(a*b.x,a*b.y,a*b.z); }
double dis( P a, P b ) { return (a-b).len(); }
int main()
{
	int n,i;
	double vp,vq,t1=0,t2,L,M,R;
	scanf("%d",&n);
	for ( i=0; i<=n; i++ ) p[i].read();	
	scanf("%lf%lf",&vq,&vp);
	q.read();
	for ( i=1; i<=n; i++ ) {
		t1+=dis(p[i-1],p[i])/vp;
		if ( dis(q,p[i])/vq <= t1+eps ) break;
	}
	if ( i>n ) { puts("NO"); return 0; }
	t1-=dis(p[i-1],p[i])/vp;
	vec=p[i]-p[i-1];
	L=0; R=1;
	while ( R-L>1e-14 ) {
		M=(L+R)/2;
		tmt=p[i-1]+M*vec;
		t2=dis(p[i-1],tmt)/vp;
		if ( dis(q,tmt)/vq <= t1+t2 ) R=M;
		else L=M;
	}
	M=(L+R)/2;
	tmt=p[i-1]+M*vec;
	t2=dis(p[i-1],tmt)/vp;
	puts("YES");
	printf("%.9f\n",t1+t2);
	tmt.print();
	return 0;
}