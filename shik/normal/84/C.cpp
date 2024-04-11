// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int sqr( int x ) { return x*x; }
struct C {
	int id,x,r;
	C( int _x=0, int _r=0 ):x(_x),r(_r){};
	void read( int _id ) { id=_id; scanf("%d%d",&x,&r); }
	bool cover( int cx, int cy ) { return sqr(cx-x)+sqr(cy)<=sqr(r); }
} c[N];
int hit[N];
bool operator <( C a, C b ) { return a.x<b.x; }
int main()
{
	int n,m,x,y;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) c[i].read(i);
	sort(c,c+n);
	memset(hit,-1,sizeof(hit));
	scanf("%d",&m);
	for ( int i=1; i<=m; i++ ) {
		scanf("%d%d",&x,&y);
		int p=lower_bound(c,c+n,x)-c;
		if ( p<n && hit[c[p].id]==-1 && c[p].cover(x,y) ) hit[c[p].id]=i;
		p--;
		if ( p>=0 && hit[c[p].id]==-1 && c[p].cover(x,y) ) hit[c[p].id]=i;
	}
	printf("%ld\n",n-count(hit,hit+n,-1));
	for ( int i=0; i<n; i++ ) printf("%d%c",hit[i],i==n-1?'\n':' ');
	return 0;
}