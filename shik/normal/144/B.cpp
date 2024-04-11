// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int sqr( int x ) { return x*x; }
struct C {
	int x,y,r;
	void read() { scanf("%d%d%d",&x,&y,&r); }
	bool cover( int qx, int qy ) { return sqr(x-qx)+sqr(y-qy)<=r*r; }
} c[N];
int n;
bool chk( int x, int y ) {
	for ( int i=0; i<n; i++ ) if ( c[i].cover(x,y) ) return 1;
	return 0;
}
int main()
{
	int x1,y1,x2,y2,ans=0;
	scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
	if ( x1>x2 ) swap(x1,x2);
	if ( y1>y2 ) swap(y1,y2);
	for ( int i=0; i<n; i++ ) c[i].read();
	for ( int i=y1; i<=y2; i++ ) {
		if ( !chk(x1,i) ) ans++;
		if ( !chk(x2,i) ) ans++;
	}
	for ( int i=x1+1; i<x2; i++ ) {
		if ( !chk(i,y1) ) ans++;
		if ( !chk(i,y2) ) ans++;
	}
	printf("%d\n",ans);
	return 0;
}