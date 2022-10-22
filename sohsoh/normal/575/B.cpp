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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, par[MAXN][LOG], C[MAXN][LOG][2], q, H[MAXN], U[MAXN], D[MAXN], ans = 0;
vector<int> adj[MAXN];
set<pll> st;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline void mkey(int& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

void dfs(int v, int p) {
	par[v][0] = p;
	for (int u : adj[v]) {
		if (u == p) continue;
		H[u] = H[v] + 1;
		dfs(u, v);
	}
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];

	return v;
}

inline int LCA(int v, int u) {
	if (H[v] < H[u]) swap(v, u);
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
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs2(u, v);
		U[v] += U[u];
	}

	if (st.find({v, p}) != st.end()) mkey(ans += poww(2, U[v]) - 1);
	if (st.find({p, v}) != st.end()) mkey(ans += poww(2, D[v]) - 1);
	D[p] += D[v];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if (c) st.insert({v, u});
	}

	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];
	
	cin >> q;
	int u = 1;
	while (q--) {
		int v, lca;
		cin >> v;
		lca = LCA(u, v);
		U[u]++;
		U[lca]--;
		D[lca]--;
		D[v]++;
		u = v;
	}
	
	dfs2(1, 0);
	cout << ans << endl;
	return 0;
}