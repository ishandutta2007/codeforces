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

int n, m, col[MAXN];
vector<int> adj[MAXN];

void dfs(int v) {
	col[v] = 1;
	for (int u : adj[v])
		if (col[u] == 1) col[v] = 2;
	for (int u : adj[v]) if (col[u] == 0) dfs(u);
}

inline int solve() {
	for (int i = 0; i < n + 10; i++) adj[i].clear(), col[i] = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	col[1] = 1;
	dfs(1);
	for (int i = 1; i <= n; i++) if (col[i] == 0) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	vector<int> ans;
	for (int i = 1; i <= n; i++) if (col[i] == 1) ans.push_back(i);
	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}