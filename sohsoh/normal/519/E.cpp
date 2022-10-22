#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

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

int n, q, par[MAXN][LOG], H[MAXN], sub_g[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	par[v][0] = p;
	sub_g[v] = 1;
	for (int u : adj[v]) {
		if (u == p) continue;
		H[u] = H[v] + 1;
		dfs(u, v);
		sub_g[v] += sub_g[u];
	}
}

inline int kth_par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--) {
		if (k & (1 << i)) {
			k ^= (1 << i);
			v = par[v][i];
		}
	}

	return v;
}

inline int LCA(int u, int v) {
	if (H[v] < H[u]) swap(v, u);
	v = kth_par(v, H[v] - H[u]);
	if (u == v) return v;

	for (int i = LOG - 1; i >= 0; i--) {
		if (par[v][i] != par[u][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	}

	return par[v][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	dfs(1, 0);
	for (int i = 1; i < LOG; i++) 
		for (int v = 1; v <= n; v++) 
			par[v][i] = par[par[v][i - 1]][i - 1];
	

	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		if ((H[u] + H[v]) & 1) {
			cout << 0 << endl;
			continue;
		}

		if (H[v] < H[u]) swap(u, v);
		int lca = LCA(u, v), w = lca;
		w = kth_par(v, H[v] - H[lca] - ((H[v] - H[u]) >> 1));
		if (w != lca) {
			int v_p = kth_par(v, H[v] - H[w] - 1);
			cout << sub_g[w] - sub_g[v_p] << endl;
		} else {
			int v_p = kth_par(v, H[v] - H[w] - 1);
			int u_p = kth_par(u, H[u] - H[w] - 1);
			cout << n - sub_g[v_p] - sub_g[u_p] << endl;
		}
	}
	return 0;
}