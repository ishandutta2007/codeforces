#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

int par[MAXN][LOG], n, m, q, H[MAXN], low[MAXN], U[MAXN], D[MAXN], C[MAXN], c;
bool edge_vis[MAXN], vis[MAXN];
vector<pll> adj[MAXN];

void dfs(int v, int p) {
	par[v][0] = p;
	vis[v] = true;
	C[v] = c;
	low[v] = H[v];

	for (pll e : adj[v]) {
		int u = e.X, ind = e.Y;
		if (edge_vis[ind]) continue;
		edge_vis[ind] = true;

		if (!vis[u]) {
			H[u] = H[v] + 1;
			dfs(u, v);
			low[v] = min(low[v], low[u]);
		} else low[v] = min(low[v], H[u]);
	}
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];
	return v;
}

inline int LCA(int u, int v) {
	if (H[v] < H[u]) swap(v, u);
	v = Par(v, H[v] - H[u]);
	if (v == u) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];

	return par[v][0];
}

void dfs2(int v, int p) {
	vis[v] = true;
	for (pll e : adj[v]) {
		int u = e.X;
		if (vis[u]) continue;
		dfs2(u, v);
		U[v] += U[u];
	}

	D[p] += D[v];
	if (D[v] && U[v] && low[v] > H[p] && p) {
		cout << "No" << endl;
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			c++;
			dfs(i, 0);
		}
	}

	for (int i = 1; i < LOG; i++) 
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	while (q--) {
		int u, v, lca;
		cin >> u >> v;
		if (C[u] != C[v]) return cout << "No" << endl, 0;
		lca = LCA(u, v);
		U[u]++;
		U[lca]--;
		D[v]++;
		D[lca]--;
	}

	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs2(i, 0);
	cout << "Yes" << endl;
	return 0;
}