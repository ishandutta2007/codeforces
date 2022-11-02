#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const double eps=1e-2;
const double inf=1e10;
struct Seg_T {
	double val[4*N];
	void init( int id, int L, int R ) {
		val[id]=1;
		if ( L==R ) return;
		int M=(L+R)/2;
		init(id*2,L,M);
		init(id*2+1,M+1,R);
	}
	void ins( int id, int L, int R, int st, int ed, double v ) {
		if ( ed<L || st>R ) return;
		if ( st<=L && R<=ed ) { val[id]*=v; return; }
		int M=(L+R)/2;
		ins(id*2,L,M,st,ed,v);
		ins(id*2+1,M+1,R,st,ed,v);
	}
	double Q( int id, int L, int R, int pos ) {
		if ( L==R ) return val[id];
		int M=(L+R)/2;
		if ( pos<=M ) return val[id]*Q(id*2,L,M,pos);
		else return val[id]*Q(id*2+1,M+1,R,pos);
	}
} seg;
struct Tree {
	int x,h,l,r;
	void read() { scanf("%d%d%d%d",&x,&h,&l,&r); }
} tree[N];
bool operator <( Tree a, Tree b ) { return a.x<b.x; }
struct Mush {
	double x,p;
	Mush(){}
	Mush( double _x, double _p ) { x=_x; p=_p; }
	void read() { scanf("%lf%lf",&x,&p); }
} mush[N];
bool operator <( Mush a, Mush b ) { return a.x<b.x; }
int n,m;
void input() {
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) tree[i].read();
	for ( int i=1; i<=m; i++ ) mush[i].read();
}
void build() {
	mush[0]=Mush(-inf,0);
	mush[m+1]=Mush(inf,0);
	m+=2;
	sort(mush,mush+m);
}
int pre_mush( double x ) { return upper_bound(mush,mush+m,Mush(x,0))-mush-1; }
int nxt_mush( double x ) { return lower_bound(mush,mush+m,Mush(x,0))-mush; }
void solve() {
	seg.init(1,0,m-1);
	for ( int i=0; i<n; i++ ) {
		int rst=nxt_mush(tree[i].x+eps);
		int red=pre_mush(tree[i].x+tree[i].h+eps);
		seg.ins(1,0,m-1,rst,red,(100-tree[i].r)/100.0);
		int lst=nxt_mush(tree[i].x-tree[i].h-eps);
		int led=pre_mush(tree[i].x-eps);
		seg.ins(1,0,m-1,lst,led,(100-tree[i].l)/100.0);
	}
	double ans=0;
	for ( int i=0; i<m; i++ ) ans+=mush[i].p*seg.Q(1,0,m-1,i);
	printf("%.9f\n",ans);
}
int main()
{
	input();
	build();
	solve();
	return 0;
}