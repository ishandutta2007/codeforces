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
vector<pair<int, int>> adj[MAXN];
vector<pair<pair<int, int>, int>> E;
vector<int> st1, st2;
ll up[MAXN], down[MAXN], sub_g[MAXN];

void dfs(int v, int p, vector<int>& st) {
	st.push_back(v);
	for (pair<int, int> e : adj[v]) {
		int u = e.X;
		if (u == p) continue;
		dfs(u, v, st);
	}
}

void dfs2(int v, int p, ll sz) {
	sub_g[v] = 1;
	up[v] = down[v] = 0;
	ll rem = n - sz;
	for (pair<int, int> e : adj[v]) {
		int u = e.X;
		ll w = e.Y;
		if (u == p) continue;
		dfs2(u, v, sz);
		sub_g[v] += sub_g[u];
		up[u] = w * (sub_g[u]) * (n - sub_g[u]);
		down[u] = w * (sub_g[u] + rem) * (n - sub_g[u] - rem); 
	}
}

ll dp[MAXN][2];

ll dfs3(int v, int p) {
	dp[v][0] = dp[v][1] = 0;
	for (pair<int, int> e : adj[v]) {
		int u = e.X;
		if (u == p) continue;
		dfs3(u, v);
	   	dp[v][1] = min(dp[v][1] + dp[u][0] + up[u], dp[v][0] + dp[u][1] + down[u]);	
		dp[v][0] += dp[u][0] + up[u];
	}

	return min(dp[v][0], dp[v][1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		E.push_back({{u, v}, w});
	}

	ll fans = INF;
	for (pair<pair<int, int>, int> e : E) {
		int u = e.X.X, v = e.X.Y, w = e.Y;;
		adj[u].erase(find(all(adj[u]), make_pair(v, w)));
		adj[v].erase(find(all(adj[v]), make_pair(u, w)));
		dfs(v, 0, st1);
		dfs(u, 0, st2);
		ll ans = 1ll * w * st1.size() * st2.size();

		dfs2(v, 0, st1.size());
		dfs2(u, 0, st2.size());

		fans = min(fans, ans + dfs3(v, 0) + dfs3(u, 0));

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		st1.clear();
		st2.clear();
	}

	cout << fans << endl;
	return 0;
}