// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) (int)((x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int n,a[N];
LL dp[N][3],ans;
int main()
{
	scanf("%d",&n); n--;
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=n; i++ ) {
		if ( a[i]==1 ) {
			dp[i][0]=dp[i][2]=0;
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
		} else {
			dp[i][0]=dp[i-1][0]+a[i]-(a[i]%2==1);
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i]-(a[i]%2==0);
			dp[i][2]=max(dp[i-1][1],dp[i-1][2])+a[i]-(a[i]%2==1);
		}
		for ( int j=0; j<3; j++ ) ans=max(ans,dp[i][j]);
	}
	printf("%I64d\n",ans);
	return 0;
}