// \_()_/
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

int n, cen, sub_g[MAXN], ans[MAXN];
vector<int> adj[MAXN], V;
ll tot = 0;

void dfs(int v, int p) {
	sub_g[v] = 1;
	int mx = 0;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		sub_g[v] += sub_g[u];
		mx = max(mx, sub_g[u]);
	}
	
	if (max(mx, n - sub_g[v]) <= n / 2) cen = v;
	if (p) tot += min(sub_g[v], n - sub_g[v]);
}

void dfs2(int v, int p) {
	V.push_back(v);
	for (int u : adj[v])
		if (u != p)
			dfs2(u, v);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	dfs(1, 0);
	dfs2(cen, 0);

	for (int i = 0; i < n; i++) ans[V[i]] = V[(i + n / 2) % n];
	cout << 2 * tot << endl;
	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}