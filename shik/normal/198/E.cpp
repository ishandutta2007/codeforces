// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>
#define N 250010
#define INF LLONG_MAX
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;
struct Seg_T {
	PLI sml[8*N];
	void pull( int id ) {
		sml[id]=min(sml[id*2],sml[id*2+1]);
	}
	void init( int id, int L, int R ) {
		sml[id]=MP(INF,-1);
		if ( L==R ) return;
		int M=(L+R)/2;
		init(id*2,L,M);
		init(id*2+1,M+1,R);
	}
	void ins( int id, int L, int R, int p, int q, LL v ) {
		if ( L==R ) {
			sml[id]=min(sml[id],MP(v,q));
			return;
		}
		int M=(L+R)/2;
		if ( p<=M ) ins(id*2,L,M,p,q,v);
		else ins(id*2+1,M+1,R,p,q,v);
		pull(id);
	}
	PLI get( int id, int L, int R, int p ) {
		if ( L>p ) return MP(INF,-1);
		if ( R<=p ) return sml[id];
		int M=(L+R)/2;
		return min(get(id*2,L,M,p),get(id*2+1,M+1,R,p));
	}
	void del( int id, int L, int R, int p ) {
		if ( L==R ) {
			sml[id].first=INF;
			return;
		}
		int M=(L+R)/2;
		if ( p<=M ) del(id*2,L,M,p);
		else del(id*2+1,M+1,R,p);
		pull(id);
	}
} seg;
int n,x[N],y[N],m[N],p[N],r[N];
void input() {
	scanf("%d%d%d%d%d",x+0,y+0,p+0,r+0,&n);
	for ( int i=1; i<=n; i++ ) scanf("%d%d%d%d%d",x+i,y+i,m+i,p+i,r+i);
}
LL l[2*N],nl;
int get( LL v ) { return lower_bound(l,l+nl,v)-l+1; }
void lshua() {
#define XD 1000000000LL
	for ( int i=0; i<=n; i++ ) l[nl++]=m[i]*XD+i;
	for ( int i=0; i<=n; i++ ) l[nl++]=p[i]*XD+n;
	sort(l,l+nl); nl=unique(l,l+nl)-l;
	for ( int i=0; i<=n; i++ ) m[i]=get(m[i]*XD+i);
	for ( int i=0; i<=n; i++ ) p[i]=get(p[i]*XD+n);
}
LL r2[N],d2[N];
void build() {
	for ( int i=n; i>=0; i-- ) x[i]-=x[0],y[i]-=y[0];
	for ( int i=0; i<=n; i++ ) {
		r2[i]=1LL*r[i]*r[i];
		d2[i]=1LL*x[i]*x[i]+1LL*y[i]*y[i];
	}
	seg.init(1,1,nl);
	for ( int i=1; i<=n; i++ ) seg.ins(1,1,nl,m[i],i,d2[i]);
}
void solve() {
	int ans=-1;
	queue<int> q;
	q.push(0);
	while ( !q.empty() ) {
		ans++;
		int i=q.front(); q.pop();
		while ( 1 ) {
			PLI now=seg.get(1,1,nl,p[i]);
			if ( now.first>r2[i] ) break;
			q.push(now.second);
			seg.del(1,1,nl,m[now.second]);
		}
	}
	printf("%d\n",ans);
}
int main()
{
	input();
	lshua();
	build();
	solve();
	return 0;
}