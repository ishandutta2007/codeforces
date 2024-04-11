// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 200010
#define S 1000010
using namespace std;
typedef long long LL;
LL ans[N];
struct Q {
	int id,L,R;
	void read( int _id ) { id=_id; scanf("%d%d",&L,&R); }
} q[N];
int n,m,num[N],tmt;
bool cp( Q a, Q b ) {
	int ax=a.L/tmt,bx=b.L/tmt;
	if ( ax!=bx ) return ax<bx;
	return (ax&1)?a.R<b.R:a.R>b.R;
}
void input() {
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%d",num+i);
	for ( int i=0; i<m; i++ ) q[i].read(i);
	tmt=(int)(1.514*sqrt(m)+1);
	sort(q,q+m,cp);
}
int st,ed,app[S]; LL now;
LL go( int L, int R ) {
	while ( st<L ) { now-=num[st]*(1+2*--app[num[st]]); st++; }
	while ( ed>R ) { now-=num[ed]*(1+2*--app[num[ed]]); ed--; }
	while ( st>L ) { st--; now+=num[st]*(1+2*app[num[st]]++); }
	while ( ed<R ) { ed++; now+=num[ed]*(1+2*app[num[ed]]++); }
	return now;
}
void solve() {
	st=ed=1; app[num[1]]++; now=num[1];
	for ( int i=0; i<m; i++ ) ans[q[i].id]=go(q[i].L,q[i].R);
	for ( int i=0; i<m; i++ ) printf("%I64d\n",ans[i]);
}
int main()
{
	input();
	solve();
	return 0;
}