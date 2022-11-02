// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmin( int &a, int b ) { if ( a==-1 || (b!=-1&&b<a) ) a=b; }
int h[N],s[N],dp[N][N*N][2];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for ( int i=0; i<n; i++ ) scanf("%d",h+i);
	for ( int i=0; i<n; i++ ) s[i+1]=s[i]+h[i];
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=dp[0][0][1]=0;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<=a; j++ ) for ( int k=0; k<2; k++ ) {
		int w=dp[i][j][k];
		if ( w==-1 ) continue;
		int x=a-j,y=b-(s[i]-j);
		if ( h[i]<=x ) chkmin(dp[i+1][j+h[i]][0],w+(i==0||k==0?0:min(h[i],h[i-1])));
		if ( h[i]<=y ) chkmin(dp[i+1][j][1],w+(i==0||k==1?0:min(h[i],h[i-1])));
	}
	int ans=-1;
	for ( int i=0; i<=a; i++ ) for ( int j=0; j<2; j++ ) chkmin(ans,dp[n][i][j]);
	printf("%d\n",ans);
	return 0;
}