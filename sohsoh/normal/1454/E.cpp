#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int> adj[MAXN], C;
int n, low[MAXN], D[MAXN], cnt = 0;
set<pll> cyc;
bool vis[MAXN];

void dfs_cyc(int v, int p, int d = 1) {
	vis[v] = true;
	low[v] = d;
	D[v] = d;
	for (int u : adj[v]) {
		if (u == p) continue;
		if (vis[u]) low[v] = min(low[v], D[u]), cyc.insert({u, v}), cyc.insert({v, u});
		else {
			dfs_cyc(u, v, d + 1);
		       	low[v] = min(low[v], low[u]);
			if (low[u] < D[u]) cyc.insert({u, v}), cyc.insert({v, u});
		}
	}
}

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = true;
	cnt++;
	for (int u : adj[v]) {
		if (cyc.find({v, u}) == cyc.end()) dfs(u);
	}
}

int solve() {
	for (int i = 0; i < n + 10; i++) adj[i].clear();
	fill(D, D + n + 10, 0);
	fill(vis, vis + n + 10, false);
	cyc.clear();
	C.clear();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs_cyc(1, 0);
	fill(vis, vis + n + 10, false);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt = 0;
			dfs(i);
			C.push_back(cnt);
		}
	}

	ll ans = 0, s = 0;
	for (ll e : C) {
		ans += e * (e - 1) / 2;
		ans += e * s * 2;
		s += e;
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();	
	return 0;
}