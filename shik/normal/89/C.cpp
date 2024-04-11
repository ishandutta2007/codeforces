// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5010
using namespace std;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int n,m;
char tbl[5010][5010];
int dir[5010][5010];
int lnk[N][4];
int h( int x, int y ) { return x*m+y+1; }
int cal_x( int p ) { return (p-1)/m; }
int cal_y( int p ) { return (p-1)%m; }
bool valid( int x, int y ) { return x>=0 && x<n && y>=0 && y<m; }
void del( int x, int y ) {
	for ( int i=0; i<4; i++ ) {
		lnk[lnk[h(x,y)][i]][i^1]=lnk[h(x,y)][i^1];
	}
}
void add( int x, int y ) {
	for ( int i=0; i<4; i++ ) {
		lnk[lnk[h(x,y)][i]][i^1]=h(x,y);
	}
}
int go( int p ) {
	if ( p==0 ) return 0;
	int x=cal_x(p);
	int y=cal_y(p);
	//printf("%d (%d,%d)\n",p,x,y);
	int d=dir[x][y];
	if ( d==-1 ) return 0;
	del(x,y);
	int ret=go(lnk[h(x,y)][d])+1;
	add(x,y);
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%s",tbl[i]);
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ ) {
			dir[i][j]=-1;
			if ( tbl[i][j]=='U' ) dir[i][j]=0;
			if ( tbl[i][j]=='D' ) dir[i][j]=1;
			if ( tbl[i][j]=='L' ) dir[i][j]=2;
			if ( tbl[i][j]=='R' ) dir[i][j]=3;
		}
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ ) {
			for ( int k=0; k<4; k++ ) {
				int nx=i+dx[k];
				int ny=j+dy[k];
				if ( !valid(nx,ny) ) continue;
				lnk[h(i,j)][k]=h(nx,ny);
			}
		}
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			if ( dir[i][j]==-1 ) del(i,j);
	int ans=-1,cnt=-1;
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ ) {
			if ( dir[i][j]==-1 ) continue;
			//printf("=======%d,%d\n",i,j);
			int now=go(h(i,j));
			if ( now>ans ) {
				ans=now;
				cnt=1;
			} else if ( now==ans ) cnt++;
		}
	printf("%d %d\n",ans,cnt);
	return 0;
}