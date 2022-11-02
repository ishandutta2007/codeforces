// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5010
using namespace std;
int n,w[N],h[N],dp[N],to[N];
int go( int p ) {
	if ( dp[p]!=-1 ) return dp[p];
	int r=0;
	for ( int i=1; i<=n; i++ )
		if ( w[p]<w[i] && h[p]<h[i] && go(i)+1>r ) r=go(to[p]=i)+1;
	return dp[p]=r;
}
int main()
{
	scanf("%d%d%d",&n,&w[0],&h[0]);
	for ( int i=1; i<=n; i++ ) scanf("%d%d",w+i,h+i);
	memset(dp,-1,sizeof(dp));
	memset(to,-1,sizeof(to));
	printf("%d\n",go(0));
	if ( dp[0] ) for ( int i=to[0]; i!=-1; i=to[i] ) printf("%d%c",i,to[i]==-1?'\n':' ');
	return 0;
}