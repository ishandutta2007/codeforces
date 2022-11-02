// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 20
using namespace std;
struct P {
	int l,x,y;	
	P(){}
	P( int _l, int _x, int _y ):l(_l),x(_x),y(_y){}
} p;
queue<P> q;
char tbl[N][N][N];
bool vis[N][N][N];
int s,n,m;
bool valid( int l, int x, int y ) { return l>=1&&l<=s&&x>=1&&x<=n&&y>=1&&y<=m; }
const int dx[]={1,0,-1,0,0,0},dy[]={0,1,0,-1,0,0},dl[]={0,0,0,0,1,-1};
int main()
{
	int x,y,i,j,k,ans;
	scanf("%d%d%d",&s,&n,&m);
	for ( i=1; i<=s; i++ ) {
		for ( j=1; j<=n; j++ )
			for ( k=1; k<=m; k++ )
				scanf(" %c",&tbl[i][j][k]);
	}
	scanf("%d%d",&x,&y);
	q.push(P(1,x,y)); vis[1][x][y]=1; ans=1;
	while ( !q.empty() ) {
		p=q.front(); q.pop();
		for ( i=0; i<6; i++ ) {
			int nl=p.l+dl[i];
			int nx=p.x+dx[i];
			int ny=p.y+dy[i];
			if ( !valid(nl,nx,ny) || tbl[nl][nx][ny]!='.' || vis[nl][nx][ny] ) continue;
			vis[nl][nx][ny]=1;
			ans++;
			q.push(P(nl,nx,ny));
		}	
	}
	printf("%d\n",ans);
	return 0;
}