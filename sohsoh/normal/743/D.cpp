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

vector<ll> adj[MAXN];
ll sum[MAXN] = {0}, n, A[MAXN], BG[MAXN], par[MAXN];

void dfs(ll v, ll p) {
	par[v] = p;
	sum[v] = A[v];
	for (ll u : adj[v]) if (u != p) dfs(u, v), sum[v] += sum[u];
}

void dfs2(ll v, ll p) {
	BG[v] = sum[v];
	for (ll u : adj[v]) if (u != p) dfs2(u, v), BG[v] = max(BG[v], BG[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	fill(BG, BG + MAXN, -1 * INF);
	dfs2(1, 0);
	
	ll ans = -1 * INF;
	for (int i = 1; i <= n; i++) {
		vector<ll> v;
		for (ll u : adj[i]) if (u != par[i]) v.push_back(BG[u]);
		sort(all(v));
		if (v.size() > 1) ans = max(ans, v.back() + v[v.size() - 2]);
	}
	
	if (ans == -1 * INF) return cout << "Impossible" << endl, 0;
	cout << ans << endl;
	
	return 0;
}