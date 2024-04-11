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
const ll MOD = 998244353; // 1e9 + 9;

ll dp[MAXN][3], n; // off, on, on but not in
vector<int> adj[MAXN];

void dfs(int v, int p) {
	dp[v][0] = dp[v][1] = dp[v][2] = 1;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v][0] *= (dp[u][1] + dp[u][2] - dp[u][0] + MOD) % MOD, dp[v][0] %= MOD;
		dp[v][1] *= (2 * dp[u][2] + dp[u][1] - dp[u][0] + MOD) % MOD, dp[v][1] %= MOD;
		dp[v][2] *= (2 * dp[u][2] + 2 * dp[u][1] - dp[u][0] + MOD) % MOD, dp[v][2] %= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	cout << (dp[1][1] + dp[1][2] - dp[1][0] - 1 + 2 * MOD) % MOD << endl;
	return 0;
}