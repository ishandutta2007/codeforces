// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int main()
{
	int n,d,m,l;
	scanf("%d%d%d%d",&n,&d,&m,&l);
	LL ub=1LL*(n-1)*m+l;
	for ( LL i=0; i<m; i++ ) if ( i*d%m>l || i*d>ub ) return printf("%I64d\n",i*d),0;
	LL x=ub/d*d;
	while ( x<=ub ) x+=d;
	printf("%I64d\n",x);
	return 0;
}