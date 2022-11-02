// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL gcd( LL a, LL b, LL &x, LL &y ) {
	if ( b==0 ) {
		x=1; y=0;
		return a;
	}
	LL r=gcd(b,a%b,y,x);
	// yb + x*(a%b) = g
	// yb + x*(a-[a/b]*b) = g
	// yb + xa - x*[a/b]*b = g
	// xa + (y-x*[a/b])*b = g
	y-=a/b*x;
	return r;
}
int main()
{
	LL a,b,c,x,y;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	LL g=gcd(a,b,x,y);
	if ( c%g!=0 ) { puts("-1"); return 0; }
	x*=-c/g; y*=-c/g;
	printf("%I64d %I64d\n",x,y);
	return 0;
}