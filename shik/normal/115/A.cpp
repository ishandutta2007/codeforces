// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
using namespace std;
int dp[N],fa[N];
int go( int p ) {
	if ( dp[p] ) return dp[p];
	if ( fa[p]==-1 ) return 1;
	return dp[p]=go(fa[p])+1;
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",fa+i);
	for ( int i=1; i<=n; i++ ) ans=max(ans,go(i));
	printf("%d\n",ans);
	return 0;
}