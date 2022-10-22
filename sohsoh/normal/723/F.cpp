#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debugp(x)		    cerr << #x << ": " << x.X << sep << x.Y << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, s, t, ds, dt, par[MAXN], H[MAXN];
vector<pll> edges, req_s, rem_s, s_edges, ans, t_edges;

int Find(int v) {
	if (v == par[v]) return v;
	return Find(par[v]);
}

inline void Union(int v, int u) {
	u = Find(u);
	v = Find(v);
	if (u == v) return;
	if (H[v] > H[u]) swap(v, u);
	if (H[v] == H[u]) H[u]++;
	par[v] = u;
}
	
inline bool S(pll e) {
	if (e.X == s || e.Y == s) return true;
	return false;
}

inline bool T(pll e) {
	if (e.X == t || e.Y == t) return true;
	return false;
}

inline bool Req(pll e) {
	return Find(e.X) != Find(e.Y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}
		
	cin >> s >> t >> ds >> dt;
	for (pll e : edges) {
		if (!S(e)) Union(e.X, e.Y);
		else s_edges.push_back(e);
	}

	int deg_s = 0, deg_t = 0;
	for (pll e : s_edges) {
		if (!Req(e) && !T(e)) rem_s.push_back(e);
		if (!T(e) && Req(e)) {
			ans.push_back(e);
			req_s.push_back(e);
			Union(e.X, e.Y);
			deg_s++;
		}
	}

	for (pll e : s_edges) {
		if (T(e) && Req(e)) {
			ans.push_back(e);
			req_s.push_back(e);
			Union(e.X, e.Y);
			deg_s++;
			deg_t++;
		}
	}

	memset(H, 0, sizeof H);
	for (int i = 1; i <= n; i++) par[i] = i;
	for (pll e : ans) Union(e.X, e.Y);
	
	for (pll e : edges) {
		if (T(e)) t_edges.push_back(e);
		else if (!S(e) && Req(e)) ans.push_back(e), Union(e.X, e.Y);
	}

	for (pll e : rem_s) {
		if (Req(e) && deg_s < ds) {
			deg_s++;
			Union(e.X, e.Y);
			ans.push_back(e);
		}
	}

	for (pll e : t_edges) {
		if (Req(e) && !S(e)) {
			deg_t++;
			ans.push_back(e);
			Union(e.X, e.Y);
		}
	}

	for (pll e : t_edges) {
		if (Req(e) && S(e)) {
			deg_t++;
			deg_s++;
			ans.push_back(e);
			Union(e.X, e.Y);
		}
	}

	for (int i = 1; i <= n; i++) if (Find(i) != Find(1)) return cout << "No" << endl, 0;
       	if (deg_s > ds || deg_t > dt || (int) ans.size() > n - 1) return cout << "No" << endl, 0;	
	cout << "Yes" << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << endl;
	return 0;
}