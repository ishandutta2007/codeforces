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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 20;
const ll MAXA = 10;

int par[MAXN][LOG], n, m, q, H[MAXN];
vector<int> P[MAXN][LOG], C[MAXN], adj[MAXN];

inline void Merge(vector<int> a, vector<int> b, vector<int>& c) {
	unsigned int p1 = 0, p2 = 0;
	while (p1 + p2 < MAXA && (p1 < a.size() || p2 < b.size())) {
		if (p1 < a.size() && (p2 >= b.size() || a[p1] < b[p2])) c.push_back(a[p1]), p1++;
		else c.push_back(b[p2]), p2++;
	}
}

void dfs(int v, int p) {
	par[v][0] = p;
	Merge(C[v], {}, P[v][0]);
	for (int u : adj[v]) {
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

inline vector<int> Path(int v, int k) {
	vector<int> ans;
	for (int i = LOG - 1; i >= 0; i--) {
		if (k & (1 << i)) {
			k ^= (1 << i);
			vector<int> tans;
			Merge(ans, P[v][i], tans);
			ans = tans;
			v = par[v][i];
		}
	}

	return ans;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
	       	C[x].push_back(i);	
	}


	dfs(1, 0);
	for (int i = 1; i < LOG; i++) {
		for (int v = 1; v <= n; v++) {
			par[v][i] = par[par[v][i - 1]][i - 1];
			Merge(P[v][i - 1], P[par[v][i - 1]][i - 1], P[v][i]);
		}
	}	

	while (q--) {
		int u, v, a;
		cin >> u >> v >> a;
		int lca = LCA(u, v);
		vector<int> ans, tans;
		ans = Path(v, H[v] - H[lca]);
		Merge(ans, Path(u, H[u] - H[lca]), tans);
		ans.clear();
		Merge(tans, C[lca], ans);
		cout << min(int(ans.size()), a) << sep;
		for (int i = 0; i < a && i < ans.size(); i++) cout << ans[i] << sep;
		cout << endl;
	}
	return 0;
}