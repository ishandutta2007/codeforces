// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 2010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct DJS {
	int fa[N*N];
	void init( int n ) { for ( int i=0; i<n; i++ ) fa[i]=i; }
	inline int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
	inline void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} djs;
const int dx0[8]={-1,-1,-1,0,0,1,1,1},dy0[8]={-1,0,1,-1,1,-1,0,1};
const int dx1[4]={1,0,-1,0},dy1[4]={0,1,0,-1};
int n,m;
bool valid( int x, int y ) { return x>=1 && x<=n && y>=1 && y<=m; }
char tbl[N][N];
int v0[N][N],v1[N][N],ucs;
int idx[N][N],sx[N*N],sy[N*N],ns;
bool is_cyc() {
	djs.init(ns);
	for ( int i=0; i<ns; i++ ) idx[sx[i]][sy[i]]=i;
	for ( int i=0; i<ns; i++ ) {
		int cnt=0;
		for ( int j=0; j<4; j++ ) {
			int nx=sx[i]+dx1[j];
			int ny=sy[i]+dy1[j];
			if ( !valid(nx,ny) || tbl[nx][ny]!='1' ) continue;
			if ( v1[nx][ny]==ucs ) {
				cnt++;
				djs.Union(i,idx[nx][ny]);
			}
		}
		if ( cnt!=2 ) return 0;
	}
	for ( int i=0; i<ns; i++ ) if ( djs.Find(i)!=djs.Find(0) ) return 0;
	return 1;
}
int check( int x, int y ) {
	int flg=0;
	ucs++;
	ns=0;
	queue<int> q;
	q.push(x); q.push(y); v0[x][y]=1;
	while ( !q.empty() ) {
		x=q.front(); q.pop();
		y=q.front(); q.pop();
		for ( int i=0; i<8; i++ ) {
			int nx=x+dx0[i];
			int ny=y+dy0[i];
			if ( !valid(nx,ny) ) {
				flg=1;
				continue;
			}
			if ( tbl[nx][ny]=='0' && !v0[nx][ny] ) {
				v0[nx][ny]=1;
				q.push(nx); q.push(ny);
			} else if ( tbl[nx][ny]=='1' && v1[nx][ny]!=ucs ) {
				v1[nx][ny]=ucs;
				sx[ns]=nx;
				sy[ns]=ny;
				ns++;
			}
		}
	}
	if ( !flg && is_cyc() ) return ns;
	else return 0;
}
int main()
{
	int ans=0;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%s",tbl[i]+1);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) if ( !v0[i][j] && tbl[i][j]=='0' ) ans=max(ans,check(i,j));
	for ( int i=1; i<n; i++ ) for ( int j=1; j<m; j++ )
		if ( tbl[i][j]=='1' && tbl[i][j+1]=='1' && tbl[i+1][j]=='1' && tbl[i+1][j+1]=='1' ) ans=max(ans,4);
	printf("%d\n",ans);
	return 0;
}