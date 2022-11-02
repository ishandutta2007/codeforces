// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 514
#define INF 1234567890
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,a[N][N],s[N][N];
bool out( int x, int y ) { return x<1 || x>n || y<1 || y>m; }
int get( int x1, int y1, int x2, int y2 ) {
	if ( x1>x2 ) swap(x1,x2);
	if ( y1>y2 ) swap(y1,y2);
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
int sol_1( int x, int y ) {
	int now=a[x][y],ret=-INF,len=2;
	while ( 1 ) {
		if ( out(x,y+len) ) break;
		now+=get(x,y+1,x,y+len);
		y+=len;
		if ( out(x-len,y) ) break;
		now+=get(x-1,y,x-len,y);
		x-=len;
		if ( out(x,y-len) ) break;
		now+=get(x,y-1,x,y-len);
		y-=len;
		ret=max(ret,now);
		if ( out(x,y-2) ) break;
		now+=get(x,y-1,x,y-2);
		y-=2;
		if ( out(x+len+2,y) ) break;
		now+=get(x+1,y,x+len+2,y);
		x+=len+2;
		len+=4;
	}
	return ret;
}
int sol_2( int x, int y ) {
	int now=a[x][y],ret=-INF,len=4;
	if ( out(x,y-2) ) return ret;
	now+=get(x,y-1,x,y-2);
	y-=2;
	if ( out(x+2,y) ) return ret;
	now+=get(x+1,y,x+2,y);
	x+=2;
	while ( 1 ) {
		if ( out(x,y+len) ) break;
		now+=get(x,y+1,x,y+len);
		y+=len;
		if ( out(x-len,y) ) break;
		now+=get(x-1,y,x-len,y);
		x-=len;
		if ( out(x,y-len) ) break;
		now+=get(x,y-1,x,y-len);
		y-=len;
		ret=max(ret,now);
		if ( out(x,y-2) ) break;
		now+=get(x,y-1,x,y-2);
		y-=2;
		if ( out(x+len+2,y) ) break;
		now+=get(x+1,y,x+len+2,y);
		x+=len+2;
		len+=4;
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) scanf("%d",a[i]+j);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	int ans=-INF;
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) ans=max(ans,sol_1(i,j));
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) ans=max(ans,sol_2(i,j));
	printf("%d\n",ans);
	return 0;
}