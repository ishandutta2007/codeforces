// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char tbl[20][20];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%s",tbl[i]+1);
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ )
			if ( tbl[i][j]=='P' )
				for ( int k=0; k<4; k++ ) {
					int nx=i+dx[k];
					int ny=j+dy[k];
					if ( tbl[nx][ny]=='W' ) {
						ans++;
						tbl[i][j]=tbl[nx][ny]=' ';
					}
				}
	printf("%d\n",ans);
	return 0;
}