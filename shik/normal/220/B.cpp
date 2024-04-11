// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 100010
#define M 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct Q {
	int id,l,r;
	void read( int _id ) { id=_id; scanf("%d%d",&l,&r); }
} q[M];
bool cpl( Q a, Q b ) { return a.l<b.l; }
bool cpr( Q a, Q b ) { return a.r<b.r; }
int a[N],app[N],now,ans[M];
void add( int x, int v ) {
	if ( x>=N ) return;
	if ( x && app[x]==x ) now--;
	app[x]+=v;
	if ( x && app[x]==x ) now++;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<m; i++ ) q[i].read(i);
	sort(q,q+m,cpl);
	int sz=1.514*sqrt(m);
	for ( int i=0; i<m; i+=sz ) sort(q+i,q+min(i+sz,m),cpr);
	int l=0,r=0;
	for ( int i=0; i<m; i++ ) {
		while ( l<q[i].l ) add(a[l++],-1);
		while ( l>q[i].l ) add(a[--l],+1);
		while ( r<q[i].r ) add(a[++r],+1);
		while ( r>q[i].r ) add(a[r--],-1);
		ans[q[i].id]=now;
	}
	for ( int i=0; i<m; i++ ) printf("%d\n",ans[i]);
	return 0;
}