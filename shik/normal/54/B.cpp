// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 30
#define H 124567
#define HH 27
using namespace std;
char tbl[N][N];
typedef long long LL;
set<LL> vis;
LL hsh_1( int x1, int y1, int x2, int y2 ) {
	LL r=0;
	for ( int i=x1; i<x2; i++ ) {
		for ( int j=y1; j<y2; j++ )
			r=r*H+(tbl[i][j]-'A'+514);
		r*=HH+3214567;
	}
	return r;
}
LL hsh_2( int x1, int y1, int x2, int y2 ) {
	LL r=0;
	for ( int i=y1; i<y2; i++ ) {
		for ( int j=x2-1; j>=x1; j-- )
			r=r*H+(tbl[j][i]-'A'+514);
		r*=HH+3214567;
	}
	return r;
}
LL hsh_3( int x1, int y1, int x2, int y2 ) {
	LL r=0;
	for ( int i=x2-1; i>=x1; i-- ) {
		for ( int j=y2-1; j>=y1; j-- )
			r=r*H+(tbl[i][j]-'A'+514);
		r*=HH+3214567;
	}
	return r;
}
LL hsh_4( int x1, int y1, int x2, int y2 ) {
	LL r=0;
	for ( int i=y2-1; i>=y1; i-- ) {
		for ( int j=x1; j<x2; j++ )
			r=r*H+(tbl[j][i]-'A'+514);
		r*=HH+3214567;
	}
	return r;
}
int n,m;
bool tmt( LL h ) {
	//printf("h = %lld\n",h);
	if ( vis.find(h)!=vis.end() ) return 1;
	return 0;
}
bool ins( int x1, int y1, int x2, int y2 ) {
	if ( tmt(hsh_1(x1,y1,x2,y2)) ) return 1;
	if ( tmt(hsh_2(x1,y1,x2,y2)) ) return 1;
	if ( tmt(hsh_3(x1,y1,x2,y2)) ) return 1;
	if ( tmt(hsh_4(x1,y1,x2,y2)) ) return 1;
	vis.insert(hsh_1(x1,y1,x2,y2));
	vis.insert(hsh_2(x1,y1,x2,y2));
	vis.insert(hsh_3(x1,y1,x2,y2));
	vis.insert(hsh_4(x1,y1,x2,y2));
	return 0;
}
bool chk( int a, int b ) {
	//printf("(%d,%d)\n",a,b);
	if ( n%a!=0 || m%b!=0 ) return 0;
	vis.clear();
	for ( int i=0; i<n; i+=a )
		for ( int j=0; j<m; j+=b )
			if ( ins(i,j,i+a,j+b) ) return 0;
	return 1;
}
int main()
{
	int i,j,ans=0,x=999,y=999;
	scanf("%d%d",&n,&m);
	for ( i=0; i<n; i++ ) scanf("%s",tbl[i]);
	for ( i=1; i<=n; i++ )
		for ( j=1; j<=m; j++ )
			if ( chk(i,j) ) {
				ans++;
				if ( i*j<x*y || (i*j==x*y && i<x) ) {
					x=i;
					y=j;
				}
			}
	printf("%d\n%d %d\n",ans,x,y);
	return 0;
}