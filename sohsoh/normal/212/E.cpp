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

const ll MAXN = 5e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, ans = 0;
bool dp[MAXN][MAXN], can[MAXN];
int sub_g[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	sub_g[v] = 1;
	dp[v][0] = true;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		sub_g[v] += sub_g[u];
		for (int i = MAXN - sub_g[u] - 1; i >= 0; i--) dp[v][i + sub_g[u]] |= dp[v][i];
	}

	for (int i = 0; i < MAXN; i++) {
		bool bf = can[4];
		if (dp[v][i] || (p > 0 && i >= (n - sub_g[v]) && dp[v][i - (n - sub_g[v])])) can[i] = true;
	}
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
	for (int i = 1; i < n - 1; i++) if (can[i]) ans++;
	cout << ans << endl;
	for (int i = 1; i < n - 1; i++) if (can[i]) cout << i << sep << n - i - 1 << endl;
	return 0;
}