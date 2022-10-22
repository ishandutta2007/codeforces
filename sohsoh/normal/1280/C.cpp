// \_()_/
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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int sub_g[MAXN], n;
vector<pll> adj[MAXN];
ll ans1, ans2;

void dfs(int v, int p, int w) {
	sub_g[v] = 1;
	for (pll e : adj[v]) {
		if (e.X != p) {
			dfs(e.X, v, e.Y);
			sub_g[v] += sub_g[e.X];
		}
	}

	if (sub_g[v] & 1) ans1 += w;
	ans2 += 1ll * min(sub_g[v], n - sub_g[v]) * w;
}

inline void solve() {
	cin >> n;
	n *= 2;
	
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dfs(1, 0, 0);
	cout << ans1 << sep << ans2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			sub_g[i] = 0;
		}

		ans1 = ans2 = 0;
		solve();
	}
	return 0;
}