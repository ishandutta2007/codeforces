#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef vector<int> vi;

struct hl_decomp {
	int N, M;
	vector<vi> G;
	vi sz, id, par, dep;
	hl_decomp(int _N, vector<vi> _G)
		: N(_N), G(_G), sz(N), id(N), par(N), dep(N) {
		dfs_sz(0, -1);
		dfs_decomp(0, -1);
		M = 1; par[0] = -1; dfs_decomp(0, -1);
		dfs_dep(0, -1);
	}
	void dfs_sz(int u, int p) {
		sz[u] = 1;
		for (int v : G[u]) if (v != p) {
			dfs_sz(v, u);
			sz[u] += sz[v];
		}
	}
	void dfs_decomp(int u, int p) {
		int v0 = -1;
		for (int v : G[u]) if (v != p)
			if (v0 == -1 || sz[v] > sz[v0]) v0 = v;
		for (int v : G[u]) if (v != p) {
			if (v == v0) {
				id[v] = id[u];
				par[v] = par[u];
			}
			else {
				id[v] = M++;
				par[v] = u;
			}
			dfs_decomp(v, u);
		}
	}
	void dfs_dep(int u, int p) {
		for (int v : G[u]) if (v != p) {
			dep[v] = dep[u] + 1;
			dfs_dep(v, u);
		}
	}
	int lca(int u, int v) {
		while (id[u] != id[v]) {
			int _u = par[u], _v = par[v];
			int du = (_u == -1 ? -1 : dep[_u]);
			int dv = (_v == -1 ? -1 : dep[_v]);
			if (du >= dv) u = _u;
			else v = _v;
		}
		return dep[u] < dep[v] ? u : v;
	}
	int dist(int u, int v) {
		int w = lca(u, v);
		return dep[u] + dep[v] - dep[w] * 2;
	}
};

int main() {
	int N, Q; cin >> N >> Q;
	vector<vector<int> > G(N);
	rep(i, N - 1) {
		int u = i + 1;
		int v; scanf("%d", &v); v--;
		G[u].pb(v), G[v].pb(u);
	}
	hl_decomp hl(N, G);
	while (Q--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		a--, b--, c--;
		int ans;
		vector<int> d = {hl.dist(a, b), hl.dist(b, c) ,hl.dist(c, a)};
		sort(d.begin(), d.end());
		ans = (d[1] + d[2] - d[0]) / 2;
		printf("%d\n", ans + 1);
	}
}