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

ll I[MAXN], G[MAXN], n;
vector<ll> adj[MAXN], ans;

void dfs(ll v, ll p = 0, ll d0 = 0, ll d1 = 0, ll d = 0) {
	if (d & 1 && (I[v] + d1) % 2 != G[v]) d1++, ans.push_back(v);
	if (d % 2 == 0 && (I[v] + d0) % 2 != G[v]) d0++, ans.push_back(v);
	for (ll u : adj[v]) if (u != p) dfs(u, v, d0, d1, d + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) cin >> I[i];
	for (int i = 1; i <= n; i++) cin >> G[i];
	dfs(1);
	cout << ans.size() << endl;
	for (ll u : ans) cout << u << endl;
	return 0;
}