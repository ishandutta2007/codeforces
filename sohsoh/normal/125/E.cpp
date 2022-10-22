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

int n, m, k, par[MAXN];
vector<int> ans_v;
vector<pair<pll, pll>> edges;
map<pll, int> ind;

int Find(int v) {
	if (v == par[v]) return v;
	return par[v] = Find(par[v]);
}

inline bool Union(int v, int u) {
	u = Find(u);
	v = Find(v);
	if (u == v) return false;
	par[u] = v;
	return true;
}

inline bool Capital(pair<pll, pll> e) {
	return e.Y.X == 1 || e.Y.Y == 1;
}

inline int MST(ll t) {
	int cnt = 0;
	ans_v.clear();;
	for (int i = 1; i <= n; i++) par[i] = i;
	vector<pair<pll, pll>> t_edges;

	for (auto e : edges) {
		t_edges.push_back(e);
		if (Capital(e)) t_edges.back().X.X += t;
	}

	sort(all(t_edges));
	for (auto e : t_edges) {
		if (Union(e.Y.X, e.Y.Y)) {
			if (Capital(e)) cnt++;	
			ans_v.push_back(e.X.Y);
		}
	}

	if (ans_v.size() < n - 1) return -1;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		w *= 2;
		edges.push_back({{w, i}, {u, v}});
		ind[make_pair(u, v)] = i;
	}
	
	if (MST(0) < 0) return cout << -1 << endl, 0;
	
	ll L = -1e9, R = 1e9;
	while (L < R) {
		ll mid = (L + R) >> 1;
		if (MST(mid) <= k) R = mid;
		else L = mid + 1;
	}
	
	if (MST(L) != k) return cout << -1 << endl, 0;
	cout << ans_v.size() << endl;
	for (int e : ans_v) cout << e << sep;
	cout << endl;
	return 0;
}