// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 30
using namespace std;
int tbl[N][N],s[N][N];
bool chk( int x1, int y1, int x2, int y2 ) {
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]==0;
}
int main()
{
	int n,m,i,j,x1,y1,x2,y2,ans=0;
	scanf("%d%d",&n,&m);
	for ( i=1; i<=n; i++ )
		for ( j=1; j<=m; j++ )
			scanf("%1d",tbl[i]+j);
	for ( i=1; i<=n; i++ )
		for ( j=1; j<=m; j++ )
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+tbl[i][j];
	for ( x1=1; x1<=n; x1++ )
		for ( y1=1; y1<=m; y1++ )
			for ( x2=x1; x2<=n; x2++ )
				for ( y2=y1; y2<=m; y2++ )
					if ( chk(x1,y1,x2,y2) )
						ans=max(ans,2*((x2-x1+1)+(y2-y1+1)));
	printf("%d\n",ans);
	return 0;
}