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
ll n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<ll> d0, d1, d2;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() > 2) return cout << -1 << endl, 0;
		if (adj[i].size() == 2) d2.push_back(i);
		else if (adj[i].size() == 1) d1.push_back(i);
		else d0.push_back(i);
	}

	vector<vector<ll>> G;

	while (true) {
		if (d2.empty()) break;
		ll u = d2.front();
		ll a = adj[u][0], b = adj[u][1];	
		d2.erase(find(all(d2), u));
		G.push_back({a, b, u});
		if (adj[a].size() == 2) {
			if (adj[a][0] != b && adj[a][1] != b) return cout << -1 << endl, 0;
		      	d2.erase(find(all(d2), a));
			d2.erase(find(all(d2), b));
			continue;
		}

		if (adj[b].size() == 2) return cout << -1 << endl, 0;
		d1.erase(find(all(d1), a));
		d1.erase(find(all(d1), b));
	}

	while (true) {
		if (d1.empty()) break;
		ll u = d1.front();
		ll v = adj[u][0];
		d1.erase(find(all(d1), u));
		d1.erase(find(all(d1), v));
		G.push_back({u, v});
	}

	bool ok = true;
	while (ok && !d0.empty()) {
		ok = false;
		for (int i = 0; i < G.size(); i++) {
			if (G[i].size() < 3) {
				G[i].push_back(d0.front());
				d0.erase(d0.begin());
				ok = true;
				break;
			}
		}
	}

	if (d0.size() % 3) return cout << -1 << endl, 0;
	for (int i = 0; i < d0.size(); i += 3) G.push_back({d0[i], d0[i + 1], d0[i + 2]});
	for (int i = 0; i < G.size(); i++) if (G[i].size() != 3) return cout << -1 << endl, 0;
	for (vector<ll> v : G) cout << v[0] << sep << v[1] << sep << v[2] << endl;
	return 0;
}