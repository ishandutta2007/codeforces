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

vector<ll> adj[MAXN];
ll vis[MAXN] = {0}, cycle = 0, n, m, k, h[MAXN] = {0};
vector<ll> c1, c2;
vector<ll> cyc_tmp, cyc;

void solve() {		
	debug(cyc.size())
	if (cyc.size() <= k) {
		cout << 2 << endl << cyc.size() << endl;
		while (!cyc.empty()) cout << cyc.back() << sep, cyc.pop_back();
		cout << endl;
	} else {
		cout << 1 << endl;
		ll ind = 0;
		while (ind < (k + 1) / 2) {
			cout << cyc.back() << sep;
			cyc.pop_back();
			cyc.pop_back();
			ind++;
		}

		cout << endl;
	}

	exit(0);
}

void dfs1(ll v, ll p) {
	h[v] = h[p] + 1;
	cyc_tmp.push_back(v);

	ll tar = -INF;

	for (ll u : adj[v]) if (vis[u] != 0 && u != p) tar = max(tar, h[u]);
	
	if (tar >= 0) {
		for (int i = tar - 1; i < h[v]; i++) cyc.push_back(cyc_tmp[i]);
		solve();
	}

	for (ll u : adj[v]) {
		if (vis[u] == 0) {
			if (vis[v] == 1) vis[u] = 2;
			else vis[u] = 1;
			dfs1(u, v);
		}
	}

	cyc_tmp.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vis[1] = 1;
	dfs1(1, 0);
	
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1) c1.push_back(i);
		else c2.push_back(i);
	}

	cout << 1 << endl;
	if (c1.size() >= (k + 1) / 2) for (int i = 0; i < (k + 1) / 2; i++) cout << c1[i] << sep;
	else for (int i = 0; i < (k + 1) / 2; i++) cout << c2[i] << sep;
	return cout << endl, 0;

	return 0;
}