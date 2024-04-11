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

ll C[MAXN] = {0}, n, m, vis[MAXN] = {0};
vector<pll> adj[MAXN];
bool is_2 = false;

void dfs(ll v) {
	vis[v] = 1;
	for (pll u : adj[v]) {
		if (vis[u.X] == 1) is_2 = true, C[u.Y] = 2;
		else if (vis[u.X] == 2) C[u.Y] = 1;
		else if (vis[u.X] == 0) {
			C[u.Y] = 1;
			dfs(u.X);
		}
	}

	vis[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
	if (is_2) cout << 2 << endl;
	else cout << 1 << endl;
	for (int i = 0; i < m; i++) cout << C[i] << sep;
	cout << endl;
	return 0;
}