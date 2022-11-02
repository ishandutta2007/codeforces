// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 150010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
double s[N];
struct Node {
	double s,l,m,r;
	Node(){}
	Node( double _s, double _l, double _m, double _r ):s(_s),l(_l),m(_m),r(_r){}
} node[4*N];
Node merge( Node a, Node b ) { return Node(a.s+b.s,max(a.l,a.s+b.l),max(a.r+b.l,max(a.m,b.m)),max(b.r,b.s+a.r)); }
struct Seg_T {
	void init( int id, int L, int R ) {
		if ( L==R ) {
			node[id]=Node(s[L],max(s[L],0.),max(s[L],0.),max(s[L],0.));
			return;
		}
		int M=(L+R)/2;
		init(id*2,L,M);
		init(id*2+1,M+1,R);
		node[id]=merge(node[id*2],node[id*2+1]);
	}
	Node Q( int id, int L, int R, int st, int ed ) {
		if ( st<=L && R<=ed ) return node[id];
		int M=(L+R)/2;
		if ( ed<=M ) return Q(id*2,L,M,st,ed);
		else if ( st>M ) return Q(id*2+1,M+1,R,st,ed);
		else return merge(Q(id*2,L,M,st,ed),Q(id*2+1,M+1,R,st,ed));
	}
} seg;
#define M 300010
int n,m,c,x[N],p[N],a[M],b[M];
void input() {
	scanf("%d%d%d",&n,&m,&c);
	for ( int i=0; i<n; i++ ) scanf("%d",x+i);
	for ( int i=0; i<n-1; i++ ) scanf("%d",p+i);
	for ( int i=0; i<m; i++ ) scanf("%d%d",a+i,b+i);
}
int d[N];
void build() {
	n--;
	for ( int i=0; i<n; i++ ) d[i]=x[i+1]-x[i];
	for ( int i=0; i<n; i++ ) s[i]=d[i]/2.0 - p[i]/100.0*c;
	seg.init(1,0,n-1);
}
void solve() {
	double ans=0;
	for ( int i=0; i<m; i++ ) ans+=seg.Q(1,0,n-1,a[i]-1,b[i]-2).m;
	printf("%.9f\n",ans);
}
int main()
{
	input();
	build();
	solve();
	return 0;
}