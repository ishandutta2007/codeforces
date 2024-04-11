// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 210
#define INF 514514514
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,r,nh[N],nt[N],mh[N],mt[N];
int dis[N][N],inq[N][N];
bool chk_win( int x, int y ) {
	for ( int i=0; i<N; i++ ) for ( int j=0; j<N; j++ ) dis[i][j]=INF;
	queue<int> q;
	dis[x][y]=0; q.push(x); q.push(y);
	while ( !q.empty() ) {
		x=q.front(); q.pop();
		y=q.front(); q.pop();
		inq[x][y]=0;
		//printf("%d,%d: %d\n",x,y,dis[x][y]);
		//if ( x==0 && y<=m ) dis[0][0]=min(dis[0][0],dis[x][y]+1);
		//if ( x<=n && y==0 ) dis[0][0]=min(dis[0][0],dis[x][y]+1);
		for ( int i=1; i<=n&&i<=x; i++ ) {
			int nx=x-i+nh[i];
			int ny=y+nt[i];
			if ( nx+ny>r || dis[x][y]+1>=dis[nx][ny] ) continue;
			dis[nx][ny]=dis[x][y]+1;
			if ( inq[nx][ny] ) continue;
			inq[nx][ny]=1;
			q.push(nx); q.push(ny);
		}
		for ( int i=1; i<=m&&i<=y; i++ ) {
			int nx=x+mh[i];
			int ny=y-i+mt[i];
			if ( nx+ny>r || dis[x][y]+1>=dis[nx][ny] ) continue;
			dis[nx][ny]=dis[x][y]+1;
			if ( inq[nx][ny] ) continue;
			inq[nx][ny]=1;
			q.push(nx); q.push(ny);
		}
	}
	if ( dis[0][0]==INF ) return 0;
	printf("Ivan\n%d\n",dis[0][0]);
	return 1;
}
int dp[N][N],in[N][N];
int go( int x, int y ) {
	if ( x+y>r ) return 0;
	if ( dp[x][y]!=-1 ) return dp[x][y];
	if ( in[x][y] ) return INF;
	in[x][y]=1;
	int ret=0;
	for ( int i=1; i<=n&&i<=x; i++ ) {
		int nx=x-i+nh[i];
		int ny=y+nt[i];
		ret=max(ret,go(nx,ny)+1);
	}
	for ( int i=1; i<=m&&i<=y; i++ ) {
		int nx=x+mh[i];
		int ny=y-i+mt[i];
		ret=max(ret,go(nx,ny)+1);
	}
	in[x][y]=0;
	return dp[x][y]=ret;
}
bool chk_lose( int x, int y ) {
	memset(dp,-1,sizeof(dp));
	int ret=go(x,y);
	if ( ret>=INF ) return 0;
	printf("Zmey\n%d\n",ret);
	return 1;
}
int main()
{
	int h,t;
	scanf("%d%d%d",&h,&t,&r);
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d%d",nh+i,nt+i);
	scanf("%d",&m);
	for ( int i=1; i<=m; i++ ) scanf("%d%d",mh+i,mt+i);
	if ( chk_win(h,t) ) return 0;
	if ( chk_lose(h,t) ) return 0;
	puts("Draw");
	return 0;
}