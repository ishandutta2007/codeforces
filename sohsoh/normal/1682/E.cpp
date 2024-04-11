#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 20;

int n, m, P[MAXN], par[MAXN][LOG], H[MAXN], SU[MAXN], SD[MAXN], par_ind[MAXN], e_in[MAXN], e_out[MAXN];
vector<pll> adj[MAXN];
bool vis[MAXN];

namespace topol {
	vector<int> adj[MAXN], ans;
	bool vis[MAXN];

	inline void add(int v, int u) {
		adj[v].push_back(u);
	}

	void dfs(int v) {
		vis[v] = true;
		for (int u : adj[v])
			if (!vis[u])
				dfs(u);
	
		ans.push_back(v);
	}

	void build() {
		for (int v = 1; v <= m; v++)
			if (!vis[v])
				dfs(v);

		reverse(all(ans));
	}
}

void dfs1(int v, int p) {
	par[v][0] = p;
	H[v] = H[p] + 1;
	vis[v] = true;

	for (auto [u, ind] : adj[v]) {
		if (!vis[u]) {
			par_ind[u] = ind;
			dfs1(u, v);
		}
	}
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];

	return v;
}

inline int LCA(int u, int v) {
	if (H[u] > H[v]) swap(u, v);
	v = Par(v, H[v] - H[u]);
	if (u == v) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];

	return par[v][0];
}

inline void addUPath(int v, int u) {
	if (u == v) return;
	SU[v]++;
	SU[Par(v, H[v] - H[u] - 1)]--;
}

inline void addDPath(int v, int u) {
	if (u == v) return;
	SD[v]++;
	SD[Par(v, H[v] - H[u] - 1)]--;
}

void dfs2(int v) {
	vis[v] = true;
	for (auto [u, ind] : adj[v]) {
		if (!vis[u]) {
			dfs2(u);
			SD[v] += SD[u];
			SU[v] += SU[u];
		}
	}
	
	int a = par_ind[v], b = par_ind[par[v][0]];
	if (SD[v])
		topol::add(b, a);
	if (SU[v])
		topol::add(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> P[i];
	
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs1(i, 0);

	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	for (int i = 1; i <= n; i++) {
		int v = i, u = P[v], lca = LCA(u, v);
		if (u == v) continue;
	
		e_out[v] = par_ind[v];
		e_in[u] = par_ind[u];
		if (lca == v)
			e_out[v] = par_ind[Par(u, H[u] - H[lca] - 1)];
		if (lca == u)
			e_in[u] = par_ind[Par(v, H[v] - H[lca] - 1)];

		addUPath(v, lca);
		addDPath(u, lca);
		if (u != lca && v != lca)
			topol::add(par_ind[Par(v, H[v] - H[lca] - 1)],
					par_ind[Par(u, H[u] - H[lca] - 1)]);
	}

	for (int i = 1; i <= n; i++)
		if (P[i] != i)
			topol::add(e_out[i], e_in[i]);

	memset(vis, false, sizeof vis);
	for (int v = 1; v <= n; v++)
		if (!vis[v])
			dfs2(v);

	topol::build();
	for (int e : topol::ans)
		cout << e << sep;
	cout << endl;
	return 0;
}