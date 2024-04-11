// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define K 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
const char ds[]="SENW";
char s[N][N],dir[K];
int n,m,k,len[K],tmt[N][N];
bool valid( int x, int y ) { return 1<=x && x<=n && 1<=y && y<=m; }
bool get( int x1, int y1, int x2, int y2 ) {
	if ( x1>x2 ) swap(x1,x2);
	if ( y1>y2 ) swap(y1,y2);
	return tmt[x2][y2]-tmt[x1-1][y2]-tmt[x2][y1-1]+tmt[x1-1][y1-1];
}
bool chk( char c ) {
	int x=-1,y=-1;
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) if ( s[i][j]==c ) x=i,y=j;
	if ( x==-1 ) return 0;
	for ( int i=0; i<k; i++ ) {
		int d=strchr(ds,dir[i])-ds;
		int nx=x+dx[d]*len[i];
		int ny=y+dy[d]*len[i];
		if ( !valid(nx,ny) ) return 0;
		if ( get(x,y,nx,ny) ) return 0;
		x=nx; y=ny;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%s",s[i]+1);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) tmt[i][j]=tmt[i-1][j]+tmt[i][j-1]-tmt[i-1][j-1]+(s[i][j]=='#');
	scanf("%d",&k);
	for ( int i=0; i<k; i++ ) scanf(" %c %d",dir+i,len+i);
	int sn=0;
	for ( char c='A'; c<='Z'; c++ ) if ( chk(c) ) putchar(c),sn++;
	if ( sn ) puts("");
	else puts("no solution");
	return 0;
}