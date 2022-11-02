// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int dp[1010][1010];
int go( int n, int k ) {
	int &r=dp[n][k];
	if ( r!=-1 ) return r;
	if ( k==0 ) return r=1;
	r=0;
	for ( int i=2*k-1; i<=n-2; i++ ) r=(r+(long long)(n-i-1)*go(i,k-1))%MOD;
	return r;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	printf("%d\n",(int)(1LL*go(n,k)*go(m,k)%MOD));
	return 0;
}