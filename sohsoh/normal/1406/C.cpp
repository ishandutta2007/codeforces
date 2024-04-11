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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll sz[MAXN] = {0}, n;
bool cent[MAXN];
vector<ll> adj[MAXN];
void dfs(ll v, ll p) {
	cent[v] = true;
	sz[v] = 1;
	for (ll u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
	       	if (sz[u] > n / 2) cent[v] = false;
	}

	if (n - sz[v] > n / 2) cent[v] = false;
} 

ll solve() {
	for (int i = 0; i < n + 10; i++) adj[i].clear();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	vector<ll> C;
	for (int i = 1; i <= n; i++) if (cent[i]) C.push_back(i);
	if (C.size() <= 1) return cout << 1 << sep << adj[1][0] << endl << 1 << sep << adj[1][0] << endl, 0;

	ll x = adj[C[0]][0];
	if (x == C[1]) x = adj[C[0]][1];
	cout << C[0] << sep << x << endl;
	cout << C[1] << sep << x << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}