// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const double pi=acos(-1);
const double eps=1e-9;
double sqr( double x ) { return x*x; }
int main()
{
	int n,r,R;
	scanf("%d%d%d",&n,&R,&r);
	if ( r>R ) { puts("NO"); return 0; }
	if ( n==1 ) { puts("YES"); return 0; }
	if ( 2*r>R ) { puts("NO"); return 0; }
	double x1,y1,x2,y2;
	x1=R-r;
	y1=0;
	x2=(R-r)*cos(2*pi/n);
	y2=(R-r)*sin(2*pi/n);
	if ( sqr(x1-x2)+sqr(y1-y2)+eps>=4*r*r ) puts("YES");
	else puts("NO");
	return 0;
}