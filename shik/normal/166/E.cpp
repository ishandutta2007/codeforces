// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int dp[2][10000010];
int main()
{
	dp[0][0]=1;
	int n;
	const int MOD=1000000007;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		dp[0][i]=dp[1][i-1];
		dp[1][i]=(dp[0][i-1]*3LL+dp[1][i-1]*2LL)%MOD;
	}
	printf("%d\n",dp[0][n]);
	return 0;
}