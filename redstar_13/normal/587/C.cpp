#include <bits/stdc++.h>
#define  pb push_back
#define ls (u<<1)
#define rs (ls|1)
#define mid (L+R>>1)

using namespace std;
template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

typedef vector<int> VI;
#define NN 100010
VI v[NN];
VI adj[NN];
VI ans;
int flag;
int sz[NN], dep[NN], fa[NN];
int dfn[NN], top[NN];
int n,rid;
int k;
int id[NN];
VI f[NN*4];

inline void push_up(VI a,VI b,VI &C){
	VI c;
	int sza=a.size(),szb=b.size();
	int na=0,nb=0;
	while(na<sza||nb<szb){
		if(c.size()>=10) break;
		if(c.size()>=k&&flag) break;
		if((na<sza&&nb>=szb)||(na<sza&&nb<szb&&a[na]<=b[nb])){
			c.pb(a[na]);
			na++;
		}
		else if((nb<szb&&na>=sza)||(nb<szb&&na<sza&&a[na]>=b[nb])){
			c.pb(b[nb]);
			nb++;
		}
	}
	C=c;
}

inline void build(int u,int L,int R){
	if(L+1==R){
		int uu=id[L];
		f[u]=v[uu];
		return;
	}
	build(ls,L,mid);
	build(rs,mid,R);
	push_up(f[ls],f[rs],f[u]);
}

inline void querySeg(int u, int L, int R, int st, int ed){
	if (R<=st || ed<=L) return ;
	if (st<=L && R<=ed) {
		push_up(ans,f[u],ans);
		return ;
	}
	querySeg(ls, L, mid, st, ed);
	querySeg(rs, mid, R, st, ed);
}

inline void dfs1(int u, int f=0){
	sz[u]=1;
	fa[u]=f;
	for(int i=adj[u].size(); i--; ){
		int v=adj[u][i];
		if(v==f) continue;
		dep[v]=dep[u]+1;
		dfs1(v, u); sz[u]+=sz[v];
	}
}

inline void dfs2(int u, int chain, int f=0){
	int son=-1;
	dfn[u]=++rid; top[u]=chain; id[rid]=u;
	for(int i=adj[u].size(); i--; ){
		int v=adj[u][i];
		if(v==f) continue;
		if(son==-1 || sz[son]<sz[v]) son=v;
	}
	if(~son) dfs2(son, chain, u);
	for(int i=adj[u].size(); i--; ){
		int v=adj[u][i];
		if(v==f || v==son) continue;
		dfs2(v, v, u);
	}
}

inline int calc(int u, int v){
	int res=0;
	int fu=top[u], fv=top[v];
	while(fu!=fv){
		if(dep[fu]<dep[fv]) swap(u, v), swap(fu, fv);
		querySeg(1, 1, n+1, dfn[fu], dfn[u]+1);
		u=fa[fu], fu=top[u];
	}
	if(dep[u]>dep[v]) swap(u, v);
	querySeg(1, 1, n+1, dfn[u], dfn[v]+1);
	printf("%d ",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	puts("");
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int m,q;
	gn(n,m);
	gn(q);
	for(int i=1;i<n;i++){
		int u,v;
		gn(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1;i<=m;i++){
		int x;
		gn(x);
		v[x].pb(i);
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
		if(v[i].size()>10) v[i].resize(10);
	}
	dfs1(1);
	dfs2(1,1);
	build(1,1,n+1);
	flag=1;
	while(q--){
		ans.clear();
		int u,v;
		gn(u,v);
		gn(k);
		calc(u,v);
	}
    return 0;
}