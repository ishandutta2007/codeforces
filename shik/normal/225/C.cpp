// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 514514514
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }
int c[N][2],dp[N][N][2];
char s[N][N];
int main()
{
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) c[j][0]+=(s[i][j]=='#');
	for ( int i=0; i<m; i++ ) c[i][1]=n-c[i][0];
	for ( int i=0; i<N; i++ ) for ( int j=0; j<N; j++ ) for ( int k=0; k<2; k++ ) dp[i][j][k]=INF;
	dp[0][0][0]=dp[0][0][1]=0;
	for ( int i=0; i<m; i++ ) for ( int j=0; j<m; j++ ) for ( int k=0; k<2; k++ ) {
		chkmin(dp[i+1][j+1][k],dp[i][j][k]+c[i][k]);
		if ( x<=j && j<=y ) chkmin(dp[i+1][1][k^1],dp[i][j][k]+c[i][k^1]);
	}
	int ans=INF;
	for ( int i=x; i<=y; i++ ) for ( int j=0; j<2; j++ ) chkmin(ans,dp[m][i][j]);
	printf("%d\n",ans);
	return 0;
}