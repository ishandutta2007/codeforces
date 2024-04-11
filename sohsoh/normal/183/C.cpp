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

int n, m, col[MAXN];
vector<int> vec, adj[MAXN], adj_rev[MAXN];
bool vis[MAXN];

void dfs(int v, int c) {
	if (vis[v]) {
		if (c != col[v]) vec.push_back(abs(col[v] - c));
		return;
	}

	vis[v] = true;
	col[v] = c;

	for (int u : adj[v]) dfs(u, c + 1);
	for (int u : adj_rev[v]) dfs(u, c - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_rev[v].push_back(u);
	}	
	
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 1);
	if (vec.empty()) return cout << n << endl, 0;
	ll ans = vec.front();
	for (int e : vec) ans = __gcd(ans, (ll)e);
	cout << ans << endl;
	return 0;
}