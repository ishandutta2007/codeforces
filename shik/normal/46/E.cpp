// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1510
#define INF (1LL<<60);
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int a[N][N];
LL dp[N][N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) scanf("%d",a[i]+j);
	for ( int i=1; i<=n; i++ ) {
		if ( i&1 ) {
			LL s=0,big=-INF;
			for ( int j=1; j<=m; j++ ) {
				s+=a[i][j];
				dp[i][j]=s+big;
				big=max(big,dp[i-1][j]);
			}
		} else {
			LL s=0,big=-INF;
			for ( int j=1; j<=m; j++ ) s+=a[i][j];
			for ( int j=m; j>0; j-- ) {
				dp[i][j]=s+big;
				s-=a[i][j];
				big=max(big,dp[i-1][j]);
			}
		}
	}
	LL ans=-INF;
	for ( int i=1; i<=m; i++ ) ans=max(ans,dp[n][i]);
	printf("%I64d\n",ans);
	return 0;
}