// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 55
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N][N];
bool v[N][N];
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m;
bool out( int x, int y ) { return x<0 || x>=n || y<0 | y>=m; }
void go( int x, int y ) {
	v[x][y]=1;
	for ( int i=0; i<4; i++ ) {
		int nx=x+dx[i],ny=y+dy[i];
		if ( !out(nx,ny) && !v[nx][ny] && s[nx][ny]=='#' ) go(nx,ny);
	}
}
bool chk( int x, int y ) {
	s[x][y]='.';
	memset(v,0,sizeof(v));
	int c=0;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( s[i][j]=='#' && !v[i][j] ) c++,go(i,j);
	s[x][y]='#';
	return c>1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
	int cnt=0;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( s[i][j]=='#' ) cnt++;
	if ( cnt<=2 ) return puts("-1"),0;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( s[i][j]=='#' && chk(i,j) ) return puts("1"),0;
	puts("2");
	return 0;
}