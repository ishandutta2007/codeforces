// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define N 60
using namespace std;
char tbl[N][N];
int n,m,k,sx,sy,gx,gy;
void input() {
	scanf("%d%d%d",&n,&m,&k);
	for ( int i=0; i<n; i++ ) scanf("%s",tbl[i]);
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			if ( tbl[i][j]=='S' ) {
				sx=i;
				sy=j;
			} else if ( tbl[i][j]=='T' ) {
				gx=i;
				gy=j;
			}
}
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
bool ok[130];
int dis[N][N],vis[N][N],fx[N][N],fy[N][N];
inline bool valid( int x, int y ) { return x>=0&&x<n&&y>=0&&y<m&&ok[(int)tbl[x][y]]; }
bool cmp( int x1, int y1, int x2, int y2 ) {
	if ( tbl[x1][y1]!=tbl[x2][y2] ) return tbl[x1][y1]<tbl[x2][y2];
	if ( x1==y1 && x2==y2 ) return 0;
	return cmp(fx[x1][y1],fy[x1][y1],fx[x2][y2],fy[x2][y2]);
}
string go( int a, int b, int c, int d ) {
	static int tmt=0;
	tmt++;
	ok[a]=ok[b]=ok[c]=ok[d]=1;
	queue<int> q;
	vis[gx][gy]=tmt;
	dis[gx][gy]=0;
	q.push(gx); q.push(gy);
	while ( !q.empty() ) {
		int x=q.front(); q.pop();
		int y=q.front(); q.pop();
		//if ( x==sx && y==sy ) 
		//printf("(%d,%d) from (%d,%d)\n",x,y,fx[x][y],fy[x][y]);
		for ( int i=0; i<4; i++ ) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if ( !valid(nx,ny) ) continue;
			if ( vis[nx][ny]!=tmt ) {
				vis[nx][ny]=tmt;
				dis[nx][ny]=dis[x][y]+1;
				fx[nx][ny]=x;
				fy[nx][ny]=y;
				q.push(nx);
				q.push(ny);
			} else if ( dis[nx][ny]==dis[x][y]+1 ) {
				if ( cmp(x,y,fx[nx][ny],fy[nx][ny]) ) {
					//printf("%d,%d,%c\n",x,y,tbl[x][y]);
					fx[nx][ny]=x;
					fy[nx][ny]=y;
				}
			}
		}
	}
	//puts("XD");
	ok[a]=ok[b]=ok[c]=ok[d]=0;
	if ( vis[sx][sy]!=tmt ) return "!";
	else {
		string ret;
		int x=fx[sx][sy],y=fy[sx][sy],xx,yy;
		while ( x!=gx || y!=gy ) {
			ret+=tbl[x][y];
			//printf("%d,%d,%s\n",x,y,ret.c_str());
			xx=fx[x][y];
			yy=fy[x][y];
			x=xx;
			y=yy;
		}
		return ret;
	}
}
int len=10000;
string ans;
void chk( int a, int b, int c, int d ) {
	string now=go(a,b,c,d);
	if ( now=="!" ) return;
	//printf("now = %s\n",now.c_str());
	if ( (int)now.size()<len || ((int)now.size()==len && now<ans) ) {
		ans=now;
		len=now.size();
	}
}
void solve() {
	for ( int a='a'; a<='z'; a++ )
		if ( k==1 ) chk(a,0,0,0);
		else for ( int b=a+1; b<='z'; b++ )
			if ( k==2 ) chk(a,b,0,0);
			else for ( int c=b+1; c<='z'; c++ )
				if ( k==3 ) chk(a,b,c,0);
				else for ( int d=c+1; d<='z'; d++ )
					chk(a,b,c,d);
	if ( len==10000 ) puts("-1");
	else printf("%s\n",ans.c_str());
}
int main()
{
	ok[(int)'S']=ok[(int)'T']=1;
	input();
	solve();
	return 0;
}