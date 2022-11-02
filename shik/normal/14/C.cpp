// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P {
	int x1,y1,x2,y2;
	void read() {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if ( x1>x2 || (x1==x2&&y1>y2) ) swap(x1,x2),swap(y1,y2);
	}
	void print() {
		printf("(%d,%d) ~ (%d,%d)\n",x1,y1,x2,y2);
	}
} p[4];
bool operator <( P a, P b ) {
	if ( a.x1!=b.x1 ) return a.x1<b.x1;
	if ( a.y1!=b.y1 ) return a.y1<b.y1;
	if ( a.x2!=b.x2 ) return a.x2<b.x2;
	return a.y2<b.y2;
}
bool chk( P a, P b, P c, P d ) {
	if ( a.x1!=a.x2 ) return 0;
	if ( b.y1!=b.y2 ) return 0;
	if ( c.x1!=c.x2 ) return 0;
	if ( d.y1!=d.y2 ) return 0;
	if ( a.x1>=c.x1 ) return 0;
	if ( b.y1<=d.y1 ) return 0;
	if ( a.x2!=b.x1 || a.y2!=b.y1 ) return 0;
	if ( b.x2!=c.x2 || b.y2!=c.y2 ) return 0;
	if ( c.x1!=d.x2 || c.y1!=d.y2 ) return 0;
	if ( d.x1!=a.x1 || d.y1!=a.y1 ) return 0;
	return 1;
}
int main()
{
	for ( int i=0; i<4; i++ ) p[i].read();
	sort(p,p+4);
	do {
		if ( chk(p[0],p[1],p[2],p[3]) ) return puts("YES"),0;
	} while ( next_permutation(p,p+4) );
	puts("NO");
	return 0;
}