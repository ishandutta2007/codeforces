#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int n, m, par[MAXN], tpar[MAXN];
vector<pair<ll, pll>> edges;

int Find(int v) {
	if (v == par[v]) return v;
	return par[v] = Find(par[v]);
}

inline bool Union(int v, int u) {
	v = Find(v);
	u = Find(u);
	if (u == v) return false;
	par[v] = u;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) par[i] = i;

	ll mst = 0, t = 0;
	for (int i = 1; i <= n; i++) cin >> par[0]; 
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, {u, v}});
	}
	
	sort(all(edges));
	for (auto e : edges) {
		if (tpar[e.Y.Y] == 0 && Union(e.Y.X, e.Y.Y)) {
			mst += e.X;
			t++;
			tpar[e.Y.Y] = 1;
		}
	}

	if (t < n - 1) return cout << -1 << endl, 0;
	cout << mst << endl;
	return 0;
}