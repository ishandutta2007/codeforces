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

int n, q, par[MAXN][LOG], D[MAXN], H[MAXN], ans[MAXN];
vector<pll> adj[MAXN];

void dfs(int v, int p) {
	par[v][0] = p;
	for (pll e : adj[v]) {
		int u = e.X;
		if (u == p) continue;
		H[u] = H[v] + 1;
		dfs(u, v);
	}
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--) {
		if (k & (1 << i)) {
			k ^= (1 << i);
			v = par[v][i];
		}
	}

	return v;
}

inline int LCA(int v, int u) {
	if (H[v] < H[u]) swap(u, v);
	v = Par(v, H[v] - H[u]);
	if (v == u) return v;

	for (int i = LOG - 1; i >= 0; i--) {
		if (par[v][i] != par[u][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	}

	return par[v][0];
}

void dfs2(int v, int p) {
	for (pll e : adj[v]) {
		int u = e.X, ind = e.Y;
		if (u == p) continue;
		dfs2(u, v);
		ans[ind + 1] += D[u];
		D[v] += D[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	cin >> q;
	while (q--) {
		int u, v, lca;
		cin >> u >> v;
		lca = LCA(u, v);
		D[v]++;
		D[u]++;
		D[lca] -= 2;
	}

	dfs2(1, 0);
	for (int i = 1; i < n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}