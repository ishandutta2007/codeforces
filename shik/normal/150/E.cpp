// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 100010
#define INF 1000000000
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
struct Seg_T {
	int n;
	PII dat[8*N];
	void init( int _n ) {
		for ( n=1; n<_n; n*=2 );
		for ( int i=1; i<4*n; i++ ) dat[i]=MP(-INF,-1);
	}
	void ins( int p, PII v ) {
		p+=n+1;
		for ( ; p>=1 && v>dat[p]; p/=2 ) dat[p]=v;
	}
	PII rmq( int st, int ed ) {
		if ( st>ed ) return MP(-INF,-1);
		st+=n; ed+=n+2;
		PII r=MP(-INF,-1);
		while ( st^ed^1 ) {
			if ( ~st&1 ) r=max(r,dat[st^1]);
			if ( ed&1 ) r=max(r,dat[ed^1]); 
			st>>=1; ed>>=1;
		}
		return r;
	}
} seg;
struct E {
	int to,val;
	E(){}
	E( int _to, int _val ):to(_to),val(_val){}
};
int n,lb,ub,st,ed,ans=-1,gap,vis[N],who[N],dis[N],val[N],fa[N],sz[N],nn,q[N],fr,bk,big[N];
vector<E> e[N];
int get_root( int p ) {
	nn=fr=bk=0; q[bk++]=p; fa[p]=-1;
	while ( fr!=bk ) {
		who[nn++]=p=q[fr++];
		FOR(it,e[p]) if ( !vis[it->to] && it->to!=fa[p] ) { fa[it->to]=p; q[bk++]=it->to; }
	}
	int w=p,sml=INF;
	for ( int i=nn-1; i>=0; i-- ) {
		sz[p=who[i]]=1;
		FOR(it,e[p]) if ( !vis[it->to] && it->to!=fa[p] ) sz[p]+=sz[it->to];
		int bl=nn-sz[p];
		FOR(it,e[p]) if ( !vis[it->to] && it->to!=fa[p] ) bl=max(bl,sz[it->to]);
		if ( bl<sml ) sml=bl,w=p;
	}
	return w;
}
void dfs( int p, int f, int d, int v ) {
	who[nn]=p; dis[nn]=d; val[nn]=v; nn++;
	FOR(it,e[p]) if ( !vis[it->to] && it->to!=f ) dfs(it->to,p,d+1,v+(it->val>=gap?1:-1));
}
bool chk( int p, int sn ) {
	seg.init(sn+5);
	seg.ins(0,MP(0,p));
	FOR(it,e[p]) if ( !vis[it->to] ) {
		nn=0; dfs(it->to,p,1,it->val>=gap?1:-1);
		for ( int i=0; i<nn; i++ ) if ( ub-dis[i]>=0 ) {
			PII now=seg.rmq(max(lb-dis[i],0),min(ub-dis[i],sn));
			if ( val[i]+now.first>=0 ) { st=who[i]; ed=now.second; return 1; }
		}
		for ( int i=0; i<nn; i++ ) seg.ins(dis[i],MP(val[i],who[i]));
	}
	return 0;
}
void go( int p ) {
	vis[p=get_root(p)]=1;
	nn=0; dfs(p,0,0,0);
	int sn=*max_element(dis,dis+nn),L=ans,R=INF;
	while ( L!=R ) {
		gap=(L+R+1)/2;
		if ( chk(p,sn) ) ans=L=gap;
		else R=gap-1;
	}
	FOR(it,e[p]) if ( !vis[it->to] ) go(it->to);
}
int main()
{
	scanf("%d%d%d",&n,&lb,&ub);
	for ( int i=1; i<n; i++ ) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[a].push_back(E(b,c));
		e[b].push_back(E(a,c));
	}
	go(1);
	printf("%d %d\n",st,ed);
	return 0;
}