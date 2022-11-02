// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define INF 514514514
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[N],dp[N][N];
int go( int x, int y ) {
	if ( dp[x][y]!=-1 ) return dp[x][y];
	if ( x==n ) return dp[x][y]=0;
	if ( y==n ) return dp[x][y]=a[x];
	if ( y==n-1 ) return dp[x][y]=max(a[x],a[y]);
	int ret=INF;
	ret=min(ret,go(y+1,y+2)+max(a[x],a[y]));
	ret=min(ret,go(y,y+2)+max(a[x],a[y+1]));
	ret=min(ret,go(x,y+2)+max(a[y],a[y+1]));
	return dp[x][y]=ret;
}
void trace( int x, int y ) {
	if ( x==n ) return;
	if ( y==n ) printf("%d\n",x+1);
	else if ( y==n-1 ) printf("%d %d\n",x+1,y+1);
	else if ( dp[x][y]==dp[y+1][y+2]+max(a[x],a[y]) ) { printf("%d %d\n",x+1,y+1); trace(y+1,y+2); }
	else if ( dp[x][y]==dp[y][y+2]+max(a[x],a[y+1]) ) { printf("%d %d\n",x+1,y+2); trace(y,y+2); }
	else if ( dp[x][y]==dp[x][y+2]+max(a[y],a[y+1]) ) { printf("%d %d\n",y+1,y+2); trace(x,y+2); }
}
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",go(0,1));
	trace(0,1);
	return 0;
}