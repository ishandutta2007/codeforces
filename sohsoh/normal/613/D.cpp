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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 20;

int tin[MAXN], n, q, par[MAXN][LOG], H[MAXN], t;
ll dp[MAXN][2];
vector<int> adj[MAXN];
vector<int> V;
bool B[MAXN];

void dfs(int v, int p) {
	tin[v] = ++t;
	par[v][0] = p;
	H[v] = H[p] + 1;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
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

void dfs2(int v) {
	for (int u : adj[v]) dfs2(u);
	
	if (B[v]) {
		dp[v][0] = INF;
		dp[v][1] = 0;
		for (int u : adj[v]) dp[v][1] += min(dp[u][0], dp[u][1] + 1);
	} else {
		ll s1 = 0, s2 = 0, delta = 0;
		for (int u : adj[v]) {
			s1 += dp[u][0];
			s2 += min(dp[u][0], dp[u][1]);
			delta = max(delta, dp[u][0] - dp[u][1]);
		}
		
		dp[v][0] = min(s1, s2 + 1);
		dp[v][1] = min(dp[v][0], s1 - delta);
	}
}

inline int solve() {	
	for (int e : V) {
		B[e] = false;
		adj[e].clear();
	}
	V.clear();
	
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int v;
		cin >> v;
		V.push_back(v);
	}

	sort(all(V), [] (int v, int u) {
		return tin[v] < tin[u];	
	});

	for (int e : V) {
		B[e] = true;
		if (B[par[e][0]]) return cout << -1 << endl, 0;
	}

	for (int i = 1; i < k; i++) V.push_back(LCA(V[i], V[i - 1]));	
	sort(all(V), [] (int v, int u) {
		return tin[v] < tin[u];	
	});

	V.resize(unique(all(V)) - V.begin());
	for (int i = 1; i < V.size(); i++) adj[LCA(V[i], V[i - 1])].push_back(V[i]);

	dfs2(V[0]);
	cout << min(dp[V[0]][0], dp[V[0]][1]) << endl;
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];
	
	for (int i = 1; i <= n; i++) adj[i].clear();
	cin >> q;
	while (q--) solve();
	return 0;
}