// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N (1<<22)
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
long long l[N],ln;
void go( long long p ) {
	if ( p>0 ) l[ln++]=p;
	if ( p<=1000000000LL ) go(p*10+4),go(p*10+7);
}
int main()
{
	go(0);
	sort(l,l+ln); l[ln]=-1;
	long long x,y; long long ans=0;
	scanf("%I64d%I64d",&x,&y);
	while ( x<=y ) {
		long long n=*lower_bound(l,l+ln,x);
		ans+=(min(n,y)-x+1LL)*n;
		x=n+1;
	}
	printf("%I64d\n",ans);
	return 0;
}