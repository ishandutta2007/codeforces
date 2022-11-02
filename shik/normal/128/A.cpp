// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define N 10
#define T 100
using namespace std;
char tbl[N][N];
int die[N][N][T],vis[N][N][T];
bool valid( int x, int y ) { return x>=0&&x<8&&y>=0&&y<8; }
bool go( int x, int y, int t ) {
	vis[x][y][t]=1;
	if ( x==0 && y==7 ) return 1;
	if ( t+1==T ) return 0;
	for ( int i=-1; i<=1; i++ ) for ( int j=-1; j<=1; j++ ) {
		int nx=x+i;
		int ny=y+j;
		if ( !valid(nx,ny) || vis[nx][ny][t+1] || die[nx][ny][t] || die[nx][ny][t+1] ) continue;
		if ( go(nx,ny,t+1) ) return 1;
	}
	return 0;
}
int main()
{
	for ( int i=0; i<8; i++ ) scanf("%s",tbl[i]);
	for ( int i=0; i<8; i++ ) for ( int j=0; j<8; j++ ) if ( tbl[i][j]=='S' ) for ( int k=0; i+k<8; k++ ) die[i+k][j][k]=1;
	puts(go(7,0,0)?"WIN":"LOSE");
	return 0;
}