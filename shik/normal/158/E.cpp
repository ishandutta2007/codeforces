// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 4010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int t[N],d[N],dp[N][N];
int go( int n, int m ) {
	int &r=dp[n][m];
	if ( r!=-1 ) return r;
	if ( n==0 || m>=n ) return r=0;
	r=max(t[n],go(n-1,m))+d[n];
	if ( m>0 ) r=min(r,go(n-1,m-1));
	return r;
}
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k); t[n+1]=86400;
	for ( int i=1; i<=n; i++ ) { scanf("%d%d",t+i,d+i); t[i]--; }
	memset(dp,-1,sizeof(dp));
	for ( int i=0; i<=n; i++ ) ans=max(ans,t[i+1]-go(i,k));
	printf("%d\n",ans);
	return 0;
}