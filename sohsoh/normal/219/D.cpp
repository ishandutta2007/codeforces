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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, dp_down[MAXN], dp_up[MAXN];
vector<pair<int, int>> adj[MAXN];

void dfs(int v, int p) {
	for (auto e : adj[v]) {
		int u = e.X;
		if (u == p) continue;
	      	dfs(u, v);
		dp_down[v] += dp_down[u];
		dp_down[v] += e.Y;
	}
}

void dfs_up(int v, int p, int inv = 0) {
	if (p) {
		dp_up[v] += dp_up[p];
		dp_up[v] += dp_down[p] - dp_down[v];
		if (inv) dp_up[v]--;
		else dp_up[v]++;
	}

	for (auto e : adj[v]) {
		int u = e.X;
		if (u == p) continue;
		dfs_up(u, v, e.Y);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, 0});
		adj[v].push_back({u, 1});
	}

	dfs(1, 0);
	dfs_up(1, 0);

	int ans = INF;
	vector<int> ans_v;
	for (int i = 1; i <= n; i++) {
		int tans = dp_up[i] + dp_down[i];
		if (tans < ans) {
			ans = tans;
			ans_v.clear();
		}

		if (tans == ans) ans_v.push_back(i);
	}

	cout << ans << endl;
	for (int e : ans_v) cout << e << sep;
	cout << endl;
	return 0;
}