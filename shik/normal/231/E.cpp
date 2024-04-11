// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> e1[N],e2[N];
int fa[N][18],bel[N];
bool vis[N],in[N],cyc[N];
void dfs( int p, int f ) {
	fa[p][0]=f;
	bel[p]=p;
	vis[p]=1;
	in[p]=1;
	FOR(it,e1[p]) if ( *it!=f ) {
		if ( in[*it] ) {
			cyc[*it]=1;
			for ( int i=p; i!=*it; i=fa[i][0] ) bel[i]=*it;
		} else if ( !vis[*it] ) dfs(*it,p);
	}
	in[p]=0;
}
int sum[N],dep[N];
void go( int p, int lv ) {
	dep[p]=lv;
	sum[p]=sum[fa[p][0]]+cyc[p];
	for ( int i=1; i<18; i++ ) fa[p][i]=fa[fa[p][i-1]][i-1];
	FOR(it,e2[p]) go(*it,lv+1);
}
inline int bit( int x, int i ) { return (x>>i)&1; }
int lca( int a, int b ) {
	if ( dep[a]<dep[b] ) return lca(b,a);
	for ( int i=17; i>=0; i-- ) if ( bit(dep[a]-dep[b],i) ) a=fa[a][i];
	if ( a==b ) return a;
	for ( int i=17; i>=0; i-- ) if ( fa[a][i]!=fa[b][i] ) a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int main()
{
	int n,m,a,b,q;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<m; i++ ) {
		scanf("%d%d",&a,&b);
		e1[a].push_back(b);
		e1[b].push_back(a);
	}
	dfs(1,0);
	for ( int i=1; i<=n; i++ ) fa[i][0]=bel[fa[i][0]];
	for ( int i=1; i<=n; i++ ) if ( i==bel[i] ) e2[fa[i][0]].push_back(i);
	go(1,1);
	scanf("%d",&q);
	while ( q-- ) {
		scanf("%d%d",&a,&b);
		a=bel[a]; b=bel[b];
		int c=lca(a,b);
		int s=sum[a]+sum[b]-2*sum[c]+cyc[c];
		int ans=1,p=2;
		while ( s ) {
			if ( s&1 ) ans=1LL*ans*p%1000000007;
			s>>=1;
			p=1LL*p*p%1000000007;
		}
		printf("%d\n",ans);
	}
	return 0;
}