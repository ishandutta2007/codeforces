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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, dp[MAXN][2], L[MAXN], R[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v][0] += max(dp[u][0] + abs(L[v] - L[u]), dp[u][1] + abs(L[v] - R[u]));
		dp[v][1] += max(dp[u][0] + abs(R[v] - L[u]), dp[u][1] + abs(R[v] - R[u]));
	}
}

inline void solve() {
	for (int i = 0; i < n + 4; i++) {
		dp[i][0] = dp[i][1] = 0;
		adj[i].clear();
	}

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}