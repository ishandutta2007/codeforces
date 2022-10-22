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

// to, ind, cost
vector<pll> adj[MAXN]; 
ll n, q, oc[MAXN], cost[MAXN], cnt[MAXN];

void dfs(int v, int p) {
	cnt[v] = 1;
	for (pll e : adj[v]) if (e.X != p) dfs(e.X, v), cnt[v] += cnt[e.X], oc[e.Y] = cnt[e.X] * (n - cnt[e.X]);	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v >> cost[i];
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	dfs(1, 0);
	ll tot_sum = 0;
	for (int i = 1; i < n; i++) tot_sum += cost[i] * oc[i];

	cout << fixed << setprecision(10);
	
	cin >> q;
	while (q--) {
		ll i, w;
		cin >> i >> w;
		tot_sum -= oc[i] * (cost[i] - w);
		cost[i] = w;
		cout << ld(n - 2) * (long double)tot_sum / (long double)(ld(n) * ld(n - 1) * ld(n - 2) / ld(6)) << endl;
	}
	return 0;
}