//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(ll (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const ll N = 3e5+5, inf = 0x3f3f3f3f3f3f3f3f;

ll n, x, y, d[N], dd[N], sz[N], fa[N][25], mi[N][25], ma[N][25], son[N];
struct Edge {
	ll v, w, nxt;
	Edge(ll a=0, ll b=0, ll c=0) : v(a), w(b), nxt(c) {}
	~Edge() {}
}e[N<<1];
ll ne, h[N];
void add(ll u, ll v, ll w) {
	e[++ne] = Edge(v, w, h[u]); h[u] = ne;
	e[++ne] = Edge(u, w, h[v]); h[v] = ne;
}

struct Lca {
	ll lca, mi, ma;
	Lca(ll a=0, ll b=0, ll c=0) : lca(a), mi(b), ma(c) {}
	~Lca() {}
};

void dfs(ll u, ll f, ll w) {
	if(u != f) {
		d[u] = d[f] + 1;
		dd[u] = dd[f] + w;
		mi[u][0] = ma[u][0] = w;
		++son[f];
	}
	else {
		d[u] = 1;
		dd[u] = 0;
	}
	sz[u] = 1;
	fa[u][0] = f;
	rep(i, 1, 20) {
		fa[u][i] = fa[fa[u][i-1]][i-1];
		mi[u][i] = min(mi[u][i-1], mi[fa[u][i-1]][i-1]);
		ma[u][i] = max(ma[u][i-1], ma[fa[u][i-1]][i-1]);
	}
	for(ll i=h[u];i;i=e[i].nxt) {
		ll v = e[i].v, w = e[i].w;
		if(v != f) {
			dfs(v, u, w);
			sz[u] += sz[v];
		}
	}
}
Lca lca(ll u, ll v) {
	ll mi1 = inf, ma1 = -inf;
	if(d[u] < d[v]) swap(u, v);
	per(i, 20, 0) if(d[fa[u][i]] >= d[v]) {
		mi1 = min(mi1, mi[u][i]);
		ma1 = max(ma1, ma[u][i]);
		u = fa[u][i];
	}
	if(u == v) return Lca(u, mi1, ma1);
	per(i, 20, 0) if(fa[u][i] != fa[v][i]) {
		mi1 = min(mi1, min(mi[u][i], mi[v][i]));
		ma1 = max(ma1, max(ma[u][i], ma[v][i]));
		u = fa[u][i];
		v = fa[v][i];
	}
	mi1 = min(mi1, min(mi[u][0], mi[v][0]));
	ma1 = max(ma1, max(ma[u][0], ma[v][0]));
	return Lca(fa[u][0], mi1, ma1);
}

int main() {
	fil(mi, 0x3f); fil(ma, ~0x3f);
	scanf("%lld%lld%lld", &n, &x, &y);
	rep(i, 1, n-1) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		add(u, v, 1);
	}
	dfs(x, x, 0);
	ll _ = y;
	while(fa[_][0] != x) _ = fa[_][0];
	printf("%lld\n", n*(n-1)-sz[y]*(sz[x]-sz[_]));
    return 0;
}