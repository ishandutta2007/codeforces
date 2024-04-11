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

int n, m, D[MAXN], D_p[MAXN];
bool vis[MAXN];
vector<int> ans;
vector<pll> adj[MAXN];

void dfs(int v) {
       	vis[v] = true;	
	for (pll e : adj[v]) {
		int ind = e.Y, u = e.X;
		if (vis[u]) continue;
		dfs(u);
		if (D[u] != D_p[u]) D_p[v] ^= 1, D_p[u] ^= 1, ans.push_back(ind);  
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	int e = 0, neg = 0;
	for (int i = 1; i <= n; i++) {
		cin >> D[i];
		if (D[i] == -1) neg = i;
	       	else e ^= D[i];
	}

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}

	if (neg == 0 && e == 1) return cout << -1 << endl, 0;
	if (neg) D[neg] = e;
	for (int i = 1; i <= n; i++) if (D[i] == -1) D[i] = 0;

	dfs(1);
	cout << ans.size() << endl;
	for (int e : ans) cout << e << endl;
	return 0;
}