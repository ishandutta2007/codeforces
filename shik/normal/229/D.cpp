// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int h[N],dp[N][N],s[N][N];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",h+i);
	for ( int i=1; i<=n; i++ ) for ( int j=i; j<=n; j++ ) s[i][j]=s[i][j-1]+h[j];
	for ( int i=1; i<=n; i++ ) dp[1][i]=i-1;
	for ( int i=2; i<=n; i++ ) for ( int j=i,k=i,t=N; j<=n; j++ ) {
		while ( k>1 && s[i][j]>=s[k-1][i-1] ) {
			k--;
			t=min(t,dp[k][i-1]);
		}
		dp[i][j]=t+j-i;
	}
	int ans=N;
	for ( int i=1; i<=n; i++ ) ans=min(ans,dp[i][n]);
	printf("%d\n",ans);
	return 0;
}