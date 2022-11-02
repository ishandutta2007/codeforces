// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int MOD,tmt;
LL Q( LL st, LL ed, LL a, LL d, LL n, LL l, LL r, LL u, LL v ) {
	if ( r<st || l>ed ) return 0;
	if ( v<a || u>a+(n-1)*d ) return 0;
	if ( l<=st && ed<=r ) {
		LL x,y;
		if ( u<a ) x=a;
		else {
			x=a+(u-a)/d*d;
			while ( x<u ) x+=d;
		}
		if ( v>a+(n-1)*d ) y=a+(n-1)*d;
		else {
			y=a+(v-a)/d*d;
			while ( y>v ) y-=d;
		}
		if ( x>y || x>a+(n-1)*d || y<a ) return 0;
		LL h=(y-x)/d+1;
		if ( (x+y)%2==0 ) return (x+y)/2%MOD*(h%MOD)%MOD;
		else if ( h%2==0 ) return (x+y)%MOD*(h/2%MOD)%MOD;
		else {
			fprintf(stderr,"QQ\n");
			return 0;
		}
	}
	LL mid=(st+ed)/2;
	return (Q(st,mid,a,2*d,(n+1)/2,l,r,u,v)+Q(mid+1,ed,a+d,2*d,n/2,l,r,u,v))%MOD;
}
int main()
{
	LL n,l,r,u,v;
	int m;
	scanf("%I64d%d%d",&n,&m,&MOD);
	while ( m-- ) {
		scanf("%I64d%I64d%I64d%I64d",&l,&r,&u,&v);
		printf("%I64d\n",Q(1,n,1,1,n,l,r,u,v)%MOD);
	}
	return 0;
}