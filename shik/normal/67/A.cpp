// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
int main()
{
	int n,ans[N],i,j;
	char s[N];
	scanf("%d %s",&n,s);
	for ( i=0; i<n; i++ ) ans[i]=1;
	for ( j=0; j<N; j++ )
		for ( i=0; i<n-1; i++ )
			if ( s[i]=='L' ) ans[i]=max(ans[i],ans[i+1]+1);
			else if ( s[i]=='R' ) ans[i+1]=max(ans[i+1],ans[i]+1);
			else if ( s[i]=='=' ) ans[i]=ans[i+1]=max(ans[i],ans[i+1]);
			else puts("QQ");
	for ( i=0; i<n; i++ ) printf("%d%c",ans[i],i==n-1?'\n':' ');
	return 0;
}