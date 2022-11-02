#include <bits/stdc++.h>
using namespace std;

void debug() { cerr << endl; }

template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
	return ;
	cerr << H << ' ';
	debug(T...);
}

#define N 200100
#define K 20

typedef long long ll;

struct Centroid {
	int n;
    vector <int> adj[N];
    int node[N], nodes, pa[N], son[N], del[N];
    void init(int _n) {
    	n = _n;
    	for (int i = 1; i <= n; i ++) adj[i].clear();
    }
    inline void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
    }
    int bfs(int u) {
        nodes = 0;
        pa[node[++nodes] = u] = 0;
        for (int i = 1; i <= nodes; i ++) {
            u = node[i];
            son[u] = 1;
            for (auto v : adj[u]) {
                if (v != pa[u] && !del[v]) pa[node[++nodes] = v] = u;
            }
        }
        for (int i = nodes; i >= 1; i --) {
            int u = node[i];
            if (son[u] * 2 >= nodes) return u;
            son[pa[u]] += son[u];
        }
        return 0;
    }
    int anc[N][K], dist[N][K];
    int cnt[N], add_cnt[N];
    ll sum_dist[N], add_dist[N];
    void dfs(int u, int p, int lev, int rt, int dep = 0) {
    	anc[u][lev] = rt;
    	dist[u][lev] = dep;
        for (auto v : adj[u]) {
            if (v == p || del[v]) continue;
            dfs(v, u, lev, rt, dep + 1);
        }
    }
    void build(int u = 1, int lev = 0) {
        int rt = bfs(u);
        del[rt] = 1;
        dfs(rt, 0, lev, rt);
        cnt[rt] = sum_dist[rt] = add_cnt[rt] = add_dist[rt] = 0;
        for (auto u : adj[rt]) if (!del[u]) build(u, lev + 1);
    }
	void update(int u, int cost) {
		debug("update", u, cost);
		for (int i = K - 1, pre = 0; i >= 0; i --) {
			int v = anc[u][i];
			if (!v) continue;
			cnt[v] += cost, sum_dist[v] += cost * dist[u][i];
			if (pre) add_cnt[pre] += cost, add_dist[pre] += cost * dist[u][i];
			pre = v;
		}
	}
	ll calc(int u) {
		debug("calc", u);
		ll ans = 0;
		for (int i = K - 1, pre = 0; i >= 0; i --) {
			int v = anc[u][i];
			if (!v) continue;
			int tot = cnt[v];
			ans += sum_dist[v];
			if (pre) tot -= add_cnt[pre], ans -= add_dist[pre];
			pre = v;
			ans += 1ll * dist[u][i] * tot;
		}
		debug("ans", ans);
		return ans;
	}
	int calc_dist(int u, int v) {
		for (int i = K - 1; i >= 0; i --) {
			if (!anc[u][i] || !anc[v][i]) continue;
			if (anc[u][i] == anc[v][i]) return dist[u][i] + dist[v][i];
		}
	}
} C;

int dep[N], fa[N][K];

void dfs(int u, int p = 0) {
	fa[u][0] = p; dep[u] = dep[p] + 1;
	for (int k = 1; k < K; k ++) fa[u][k] = fa[fa[u][k-1]][k-1];
	for (auto v : C.adj[u]) if (v != p) dfs(v, u);
}

int anc(int u, int d) {
	for (int k = 0; k < K; k ++) if (d >> k & 1) u = fa[u][k];
	return u;
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	v = anc(v, dep[v] - dep[u]);
	if (u == v) return u;
	for (int k = K - 1; k >= 0; k --) if (fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
	return fa[u][0];
}

int calc_dist(int u, int v) {
	int w = lca(u, v);
	return dep[u] + dep[v] - 2 * dep[w];
}

int calc_point(int u, int v, int d) {
	int w = lca(u, v);
	if (dep[u] - dep[w] >= d) return anc(u, d);
	else return anc(v, dep[u] + dep[v] - 2 * dep[w] - d);
}

struct circle{
	int o, r;
	circle(int o = 0, int r = 0) : o(o), r(r) {}
	bool operator < (const circle &c) const {
		return C.calc_dist(o, c.o) + r <= c.r;
	}
	circle operator + (const circle &c) const {
		int d = C.calc_dist(o, c.o);
		if (d + r <= c.r) return c;
		if (d + c.r <= r) return *this;
		return circle(calc_point(o, c.o, (d + c.r - r) / 2), (d + c.r + r) / 2);
	}
} c[N];

ll sum[N];

ll solve(int l, int r) {
	if (l == r) return 0;
	int m = l + r >> 1;
	ll rlt = solve(l, m) + solve(m + 1, r);
	c[m] = circle(m, 0), c[m+1] = circle(m + 1, 0);
	for (int i = m - 1; i >= l; i --) c[i] = c[i+1] + circle(i, 0);
	for (int i = m + 2; i <= r; i ++) c[i] = c[i-1] + circle(i, 0);
	sum[r+1] = 0;
	for (int i = r; i > m; i --) sum[i] = sum[i+1] + c[i].r;
	int j = m + 1, k = m + 1;
	for (int i = m; i >= l; i --) {
		while (k <= r && !(c[i] < c[k])) C.update(c[k].o, 1), k ++;
		while (j < k && (c[j] < c[i])) C.update(c[j].o, -1), j ++;
		rlt += sum[k] + 1ll * c[i].r * (j - m - 1);
		rlt += (C.calc(c[i].o) + 1ll * c[i].r * (k - j) + sum[j] - sum[k]) >> 1;
	}
	while (j < k) C.update(c[j].o, -1), j ++;
	debug(l, r, rlt);
	return rlt;
}

int main() {
    int n, m;
    scanf("%d", &n);
    C.init(2 * n - 1); m = n;
    for (int i = 1, u, v; i < n; i ++) {
		scanf("%d %d", &u, &v);
		m ++;
		C.add_edge(u, m);
		C.add_edge(m, v);
    }
    C.build(); dfs(1);
    printf("%lld\n", solve(1, n));

    return 0;
}