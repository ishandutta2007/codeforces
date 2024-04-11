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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n = 0, da, db, a, b, dist[MAXN];
vector<ll> adj[MAXN];

void dfs(ll v, ll p, ll d) {
	dist[v] = d;
	for (ll u : adj[v]) if (u != p) dfs(u, v, d + 1);
}

ll solve() {
	for (int i = 0; i < n + 10; i++) adj[i].clear();
	cin >> n >> a >> b >> da >> db;
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (db <= 2 * da) return cout << "Alice" << endl, 0;
	dfs(a, -1, 0);
	if (dist[b] <= da) return cout << "Alice" << endl, 0;
	dfs(1, -1, 0);
	ll v = max_element(dist, dist + n + 1) - dist;
	dfs(v, -1, 0);
	if (*max_element(dist, dist + n + + 1) <= 2 * da) return cout << "Alice" << endl, 0;
	cout << "Bob" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}