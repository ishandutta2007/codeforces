#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<INT, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 100100
VI adj[NN];
queue <int> girls[NN];
int sz[NN], dep[NN], top[NN], fa[NN];

void dfs(int u){
	sz[u]=1;
	for(int v : adj[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		sz[u]+=sz[v];
	}
}

int L[NN], R[NN], rec[NN], rid;
void dfs(int u, int chain){
	rec[rid]=u;
	L[u]=rid++;
	top[u]=chain;
	int son=0;
	for(int v : adj[u]){
		if(v==fa[u]) continue;
		if(sz[v]>sz[son]) son=v;
	}
	if(son) dfs(son, chain);
	for(int v : adj[u]){
		if(v==fa[u] || v==son) continue;
		dfs(v, v);
	}
	R[u]=rid;
}

#define ls (u<<1)
#define rs (ls|1)
#define mid (L+R>>1)

pii mn[NN<<2];
INT up[NN<<2];
const INT inf=1LL<<60;

void push_up(int u){
	mn[u]=min(mn[ls], mn[rs]);
}

void build(int u, int L, int R){
	if(L+1==R){
		if(!girls[rec[L]].empty()) mn[u].x=girls[rec[L]].front();
		else mn[u].x=inf;
		mn[u].y=rec[L];
		return ;
	}
	build(ls, L, mid);
	build(rs, mid, R);
	push_up(u);
}

void push_down(int u){
	if(up[u]){
		up[ls]+=up[u];
		mn[ls].x=min(inf, mn[ls].x+up[u]);
		up[rs]+=up[u];
		mn[rs].x=min(inf, mn[rs].x+up[u]);
		up[u]=0;
	}
}

void update(int u, int L, int R, int l, int r, INT x){
	if(r<=L || R<=l) return ;
	if(l<=L && R<=r){
		up[u]+=x;
		mn[u].x=min(inf, mn[u].x+x);
		return ;
	}
	push_down(u);
	update(ls, L, mid, l, r, x);
	update(rs, mid, R, l, r, x);
	push_up(u);
}

pii calc(int u, int L, int R, int l, int r){
	if(r<=L || R<=l) return pii(inf, 0);
	if(l<=L && R<=r) return mn[u];
	push_down(u);
	return min(calc(ls, L, mid, l, r), calc(rs, mid, R, l, r));
}

pii calc(int u, int v){
	int fu=top[u];
	int fv=top[v];
	pii ans=pii(inf, 0);
	while(fu!=fv){
		if(dep[fu]<dep[fv]) swap(fu, fv), swap(u, v);
		smin(ans, calc(1, 0, rid, L[fu], L[u]+1));
		u=fa[fu];
		fu=top[u];
	}
	if(dep[u]<dep[v]) swap(u, v);
	smin(ans, calc(1, 0, rid, L[v], L[u]+1));
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int i=1; i<n; i++){
		int u, v; gn(u, v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1);
	dfs(1, 1);
	
	for(int i=1; i<=m; i++){
		int u; gn(u);
		girls[u].push(i);
	}
	
	build(1, 0, n);
	
	int tp, u, v, k;
	while(q--){
		gn(tp, u);
		if(tp==1){
			gn(v, k);
			VI ans;
			while(k--){
				pii best=calc(u, v);
				if(best.x>=inf) break;
				int p;
				ans.pb(p=girls[best.y].front());
				girls[best.y].pop();
				if(girls[best.y].empty()) update(1, 0, n, L[best.y], L[best.y]+1, inf);
				else update(1, 0, n, L[best.y], L[best.y]+1, girls[best.y].front()-p);
			}
			printf("%d", ans.size());
			for(int x : ans) printf(" %d", x);
			puts("");
		}
		else {
			gn(k);
			update(1, 0, n, L[u], R[u], k);
		}
	}
	
	return 0;
}