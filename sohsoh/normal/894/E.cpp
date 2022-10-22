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

int n, m, c, C[MAXN];
vector<pll> adj[MAXN], adj_r[MAXN];
vector<pair<pll, int>> edges;
vector<int> T[MAXN];
stack<int> st;
bool vis[MAXN];
ll dp[MAXN], val[MAXN];

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = true;
	for (pll e : adj[v])
		dfs(e.X);
	st.push(v);
}

void sfd(int v) {
	C[v] = c;
	T[c].push_back(v);
	for (pll e : adj_r[v]) 
		if (C[e.X] == 0)
			sfd(e.X);
}

ll Cost(ll e) {
	ll L = 0, R = 1e5;
	while (L < R) {
		ll mid = (L + R + 1) >> 1;
		if (mid * (mid + 1) / 2 > e) R = mid - 1;
		else L = mid;	
	}
	
	if (L == 0) return 0;
	return (L + 1) * e - L * (L + 1) * (L + 2) / 6;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj_r[v].push_back({u, w});
		edges.push_back({{u, v}, w});
	}

	for (int i = 1; i <= n; i++) dfs(i);
	while (!st.empty()) {
		int v = st.top();
		st.pop();
		if (C[v] == 0) c++, sfd(v);
	}

	for (auto e : edges)
		if (C[e.X.X] == C[e.X.Y])
			val[C[e.X.X]] += Cost(e.Y);

	for (int i = c; i > 0; i--) {
		for (int v : T[i]) {
			for (pll e : adj[v]) {
				int u = e.X, w = e.Y;
				if (C[u] == i) continue;
				dp[i] = max(dp[i], dp[C[u]] + w);
			}
		}

		dp[i] += val[i];
	}

	int s;
	cin >> s;
	cout << dp[C[s]] << endl;
	return 0;
}