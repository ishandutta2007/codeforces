// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 60
using namespace std;
int s[N][N];
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ )
			scanf("%d",s[i]+j);
	scanf("%d%d",&a,&b);
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ )
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	int ans=n*m;
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ ) {
			if ( i>=a && j>=b ) ans=min(ans,s[i][j]-s[i-a][j]-s[i][j-b]+s[i-a][j-b]);
			if ( i>=b && j>=a ) ans=min(ans,s[i][j]-s[i-b][j]-s[i][j-a]+s[i-b][j-a]);
		}
	printf("%d\n",ans);
	return 0;
}