#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define INF 514514514
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P {
	int x,y;
	void read() { scanf("%d%d",&x,&y); }
} p[N];
struct Rec {
	int x1,y1,x2,y2,z;
	Rec(){}
	Rec( P q ):x1(q.x),y1(q.y),x2(q.x),y2(q.y){}
	void read() { scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&z); }
	inline bool cover( const Rec &r ) const { return x1<=r.x1 && r.x2<=x2 && y1<=r.y1 && r.y2<=y2; }
	inline bool jiao( const Rec &r ) const { return !(x2<r.x1||x1>r.x2) && !(y2<r.y1||y1>r.y2); }
} rec[N];
inline bool cpz( int a, int b ) { return rec[a].z<rec[b].z; }
inline bool cpx( int a, int b ) { return p[a].x!=p[b].x?p[a].x<p[b].x:p[a].y<p[b].y; }
inline bool cpy( int a, int b ) { return p[a].y!=p[b].y?p[a].y<p[b].y:p[a].x<p[b].x; }
inline int key( int id, int lv ) { return lv%2==0?p[id].x:p[id].y; }
struct KD_T {
	Rec val[8*N];
	bool leaf[8*N];
	void pull( int id ) {
		val[id].x1=min(val[id*2].x1,val[id*2+1].x1);
		val[id].y1=min(val[id*2].y1,val[id*2+1].y1);
		val[id].x2=max(val[id*2].x2,val[id*2+1].x2);
		val[id].y2=max(val[id*2].y2,val[id*2+1].y2);
		val[id].z=min(val[id*2].z,val[id*2+1].z);
	}
	void init( int id, int n, int *lst, int lv ) {
		if ( n==1 ) {
			val[id]=p[lst[0]];
			val[id].z=lst[0];
			leaf[id]=1;
			return;
		}
		sort(lst,lst+n,lv%2==0?cpx:cpy);
		init(id*2,n/2,lst,lv+1);
		init(id*2+1,n-n/2,lst+n/2,lv+1);
		pull(id);
	}
	void del_min( int id ) {
		if ( leaf[id] ) {
			val[id].z=INF;
			return;
		}
		if ( val[id*2].z==val[id].z ) del_min(id*2);
		else del_min(id*2+1);
		pull(id);
	}
	void up( int id ) { do pull(id); while ( id/=2 ); }
	pair<int,int> Q( int id, const Rec &r ) {
		if ( !r.jiao(val[id]) ) return make_pair(INF,-1);
		if ( r.cover(val[id]) ) return make_pair(val[id].z,id);
		return min(Q(id*2,r),Q(id*2+1,r));
	}
} kdt;
int n,m;
void input() {
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) rec[i].read();
	scanf("%d",&m);
	for ( int i=0; i<m; i++ ) p[i].read();
}
int ans[N],lst[N],srt[N];
void build() {
	for ( int i=0; i<m; i++ ) lst[i]=i;
	kdt.init(1,m,lst,0);
}
void solve() {
	for ( int i=0; i<n; i++ ) srt[i]=i;
	sort(srt,srt+n,cpz);
	for ( int i=0; i<n; i++ ) {
		pair<int,int> ret=kdt.Q(1,rec[srt[i]]);
		if ( ret.first==INF ) continue;
		kdt.del_min(ret.second);
		kdt.up(ret.second/2);
		ans[ret.first]=srt[i]+1;
	}
	for ( int i=0; i<m; i++ ) printf("%d\n",ans[i]);
}
int main()
{
	input();
	build();
	solve();
	return 0;
}