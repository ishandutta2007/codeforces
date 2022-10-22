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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int low[MAXN], H[MAXN], dp1[MAXN], dp2[MAXN], n, k;
vector<int> adj[MAXN];

void dfs(int v, int p) {
	low[v] = H[v];
	if (p > 0 && adj[v].size() == 1) {
		low[v] = H[v] - k;
		dp1[v] = dp2[v] = 1;
		return;
	}

	int delta = 0;
	for (int u : adj[v]) {
		if (u == p) continue;
		H[u] = H[v] + 1;
		dfs(u, v);
		low[v] = min(low[u], low[v]);
		int dp1_val = 0;
		if (low[u] <= H[v]) dp1_val = dp1[u];

		dp1[v] += dp1_val;
		dp2[v] += dp1_val;
		delta = max(delta, dp2[u] - dp1_val);
	}

	dp2[v] += delta;
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}

	H[1] = 1;
	dfs(1, 0);
	cout << dp2[1] << endl;
	return 0;
}