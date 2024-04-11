// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,a,b,c,d,dp[1010]={};
	scanf("%d%d%d%d",&n,&m,&c,&d);
	for ( int i=c; i<=n; i++ ) dp[i]=dp[i-c]+d;
	while ( m-- ) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for ( int i=0; i<a/b; i++ )
			for ( int j=n; j>=c; j-- ) dp[j]=max(dp[j],dp[j-c]+d);
	}
	printf("%d\n",dp[n]);
	return 0;
}