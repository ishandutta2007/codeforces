// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 305
#define INF 514514514
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[N][N],dp[N+N][N][N];
int go( int s, int x1, int x2 ) {
	int y1=s-x1,y2=s-x2;
	if ( x1>n || y1>n || x2>n || y2>n ) return -INF;
	if ( s==n+n ) return a[n][n];
	if ( dp[s][x1][x2]!=INF ) return dp[s][x1][x2];
	int r=-INF,now=a[x1][y1];
	if ( x1!=x2 ) now+=a[x2][y2];
	for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) r=max(r,go(s+1,x1+i,x2+j));
	return dp[s][x1][x2]=r+now;
}
int main()
{
	for ( int i=0; i<N+N; i++ ) for ( int j=0; j<N; j++ ) for ( int k=0; k<N; k++ ) dp[i][j][k]=INF;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) scanf("%d",a[i]+j);
	int ans=go(2,1,1);
	printf("%d\n",ans);
	return 0;
}