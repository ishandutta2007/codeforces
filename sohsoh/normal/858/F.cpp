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

int n, m, depth[MAXN];
bool vis[MAXN], used[MAXN];
vector<int> adj[MAXN];
vector<vector<int>> ans;

void dfs(int v, int p, int d = 0) {
	vis[v] = true;
	depth[v] = d;
	
	vector<int> E;
	for (int u : adj[v]) {
		if (!vis[u]) {
		       	dfs(u, v, d + 1);
			if (!used[u]) E.push_back(u);
		} else if (d < depth[u]) E.push_back(u);
	}

	if ((E.size() & 1) && p > 0) E.push_back(p), used[v] = true;
	for (int i = 0; i < int(E.size()) - 1; i += 2) ans.push_back({E[i], v, E[i + 1]});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
	cout << ans.size() << endl;
	for (auto e : ans) cout << e[0] << sep << e[1] << sep << e[2] << endl;
	return 0;
}