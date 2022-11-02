// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int pw( int x, int n ) {
	int r=1;
	while ( n ) {
		if ( n&1 ) r=1LL*r*x%MOD;
		x=1LL*x*x%MOD;
		n>>=1;
	}
	return r;
}
int main()
{
	int n,m[41]={1, 2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011};
	scanf("%d",&n);
	int ans=pw(2,m[n]-1)-1;
	if ( ans<0 ) ans+=MOD;
	printf("%d\n",ans);
	return 0;
}