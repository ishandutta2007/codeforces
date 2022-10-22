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

int n;
vector<int> adj[MAXN];
ll dp_down[MAXN], dp_up[MAXN], sub_g[MAXN];

void dfs(int v, int p) {
	sub_g[v] = 1;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		sub_g[v] += sub_g[u];
		dp_down[v] += dp_down[u];
	}

	dp_down[v] += sub_g[v];
}

void dfs2(int v, int p) {
	dp_up[v] = n - sub_g[v] + 1;
	if (p) dp_up[v] += dp_up[p] + dp_down[p] - dp_down[v] - sub_g[v] - 1;
	for (int u : adj[v]) if (u != p) dfs2(u, v);
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
	dfs2(1, 0);
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp_down[i] + dp_up[i] - 1);
	cout << ans << endl;
	return 0;
}