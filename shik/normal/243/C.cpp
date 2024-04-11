// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#define N 3140
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL L=(LL)(1e10);
struct P {
	char d;
	int l;
	void read() { scanf(" %c %d",&d,&l); }
	void move( LL &x, LL &y ) {
		if ( d=='L' ) x-=l;
		else if ( d=='R' ) x+=l;
		else if ( d=='D' ) y-=l;
		else if ( d=='U' ) y+=l;
		else puts("QQ");
	}
	void move2(LL&,LL&);
} p[N];
LL lx[N],ly[N],nx,ny,sx[N],sy[N],sz[N][N];
int gx( LL x ) { return lower_bound(lx,lx+nx,x)-lx; }
int gy( LL y ) { return lower_bound(ly,ly+ny,y)-ly; }
int al,ar,am;
void get_x( LL x1, LL x2, LL y ) {
	if ( x1>x2 ) swap(x1,x2);
	al=gx(x1);
	ar=gx(x2);
	am=gy(y);
}
void get_y( LL x, LL y1, LL y2 ) {
	if ( y1>y2 ) swap(y1,y2);
	al=gy(y1);
	ar=gy(y2);
	am=gx(x);
}
bool bye[N][N];
void P::move2( LL &x, LL &y ) {
	LL xx=x,yy=y;
	move(xx,yy);
	if ( y==yy ) {
		get_x(x,xx,y);
		for ( int i=al; i<=ar; i++ ) bye[i][am]=1;
	} else if ( x==xx ) {
		get_y(x,y,yy);
		for ( int i=al; i<=ar; i++ ) bye[am][i]=1;
	} else puts("QQ");
	x=xx; y=yy;
}
LL ans;
queue<int> q;
bool vis[N][N];
inline bool out( int x, int y ) { return x<0 || x>=nx || y<0 || y>=ny; }
inline void chk( int x, int y ) {
	if ( out(x,y) ) return;
	if ( vis[x][y] || bye[x][y] ) return;
	ans+=sz[x][y];
	vis[x][y]=1;
	q.push(x); q.push(y);
}
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
void BFS() {
	while ( !q.empty() ) {
		int x=q.front(); q.pop();
		int y=q.front(); q.pop();
		for ( int i=0; i<4; i++ ) chk(x+dx[i],y+dy[i]);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read();
	lx[nx++]=0; lx[nx++]=1; lx[nx++]=L-1; lx[nx++]=L;
	ly[ny++]=0; ly[ny++]=1; ly[ny++]=L-1; ly[ny++]=L;
	LL x=L/2,y=L/2;
	for ( int j=-1; j<=1; j++ ) lx[nx++]=x+j;
	for ( int j=-1; j<=1; j++ ) ly[ny++]=y+j;
	for ( int i=0; i<n; i++ ) {
		p[i].move(x,y);
		for ( int j=-1; j<=1; j++ ) lx[nx++]=x+j;
		for ( int j=-1; j<=1; j++ ) ly[ny++]=y+j;
	}
	sort(lx,lx+nx); nx=unique(lx,lx+nx)-lx;
	sort(ly,ly+ny); ny=unique(ly,ly+ny)-ly;
	lx[nx]=ly[ny]=L+1;
	for ( int i=0; i<nx; i++ ) sx[i]=lx[i+1]-lx[i];
	for ( int i=0; i<ny; i++ ) sy[i]=ly[i+1]-ly[i];
	for ( int i=0; i<nx; i++ ) for ( int j=0; j<ny; j++ ) sz[i][j]=sx[i]*sy[j];
	x=L/2; y=L/2;
	for ( int i=0; i<n; i++ ) p[i].move2(x,y);
	get_x(0,L,0);
	for ( int i=al; i<=ar; i++ ) chk(i,am);
	get_x(0,L,L);
	for ( int i=al; i<=ar; i++ ) chk(i,am);
	get_y(0,0,L);
	for ( int i=al; i<=ar; i++ ) chk(am,i);
	get_y(L,0,L);
	for ( int i=al; i<=ar; i++ ) chk(am,i);
	BFS();
	ans=(L+1)*(L+1)-ans;
	cout<<ans<<endl;
	return 0;
}