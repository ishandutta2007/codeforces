#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

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
const ll MAXN2 = 2e6;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

int n, m, par[MAXN][LOG], last_vert[MAXN][LOG], H[MAXN], S[MAXN], E[MAXN], score[MAXN2], up[MAXN2], tmp = n, LCA_P[MAXN2], LCA_T[MAXN2];
vector<int> adj[MAXN];
map<pll, int> bad_map;
pll Q[MAXN], QT[MAXN];
ll ans1, ans2;

inline pll BadPair(pll e) {
	int u = e.X, v = e.Y;
	if (u == 0) u = ++tmp;
	if (v == 0) v = ++tmp;
	if (u > v) swap(u, v);
	return {u, v};
}

void lca_dfs(int v, int p, int h) {
	H[v] = h;
	par[v][0] = p;
	last_vert[v][0] = v;
	for (int u : adj[v]) if (u != p) lca_dfs(u, v, h + 1);
}

inline pll kth_par(int v, int k) {
	int j = 0, lv = 0;
	while (k) {
		if (k & 1) {
			lv = last_vert[v][j];
			v = par[v][j];
		}

		j++;
		k >>= 1;
	}

	return {v, lv};
}

inline pair<int, pll> LCA(int v, int u) {
	if (H[v] < H[u]) swap(u, v);	
	int pu = u, pv = v;
	pll tv = kth_par(v, H[v] - H[u]);
	v = tv.X;
	
	int L = 0, R = n;
	while (L < R) {
		int mid = (L + R) >> 1;
		if (kth_par(v, mid).X == kth_par(u, mid).X) R = mid;
		else L = mid + 1;
	}
	
	int lv = 0, lu = 0;
	auto dv = kth_par(v, L), du = kth_par(u, L);
	v = dv.X, u = du.X, lv = dv.Y, lu = du.Y;
	if (lv == 0) lv = tv.Y;
	if (v == pv) lv = 0;
	if (u == pu) lu = 0;
	return {v, BadPair({lv, lu})};
}

void dfs1(int v, int p) {
	score[v] += S[v] - E[v];
	up[v] += S[v] - 2 * E[v];
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs1(u, v);
		up[v] += up[u];
		score[v] += up[u];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	tmp = n + 10;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
		
	lca_dfs(1, 0, 1);
	for (int i = 1; i < LOG; i++) {
		for (int v = 1; v <= n; v++) {
			last_vert[v][i] = last_vert[par[v][i - 1]][i - 1];
			par[v][i] = par[par[v][i - 1]][i - 1];
		}
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, lca;	
		cin >> u >> v;
		auto e = LCA(u, v);
		lca = e.X;
		bad_map[e.Y]++;
		Q[i] = {u, v};
		S[u]++;
		S[v]++;
		E[lca]++;
		QT[i] = e.Y;
	}

	dfs1(1, 0);
	for (int i = 1; i <= m; i++) {
		int u = Q[i].X, v = Q[i].Y, lca, lv, lu;
		auto e = LCA(u, v);
		lca = e.X, lv = e.Y.X, lu = e.Y.Y;
		LCA_P[lca]++;
		LCA_T[QT[i].X]++;
		LCA_T[QT[i].Y]++;
		ll tans = score[lca] - up[lv] - up[lu] + bad_map[QT[i]] - 2;
		if (lv <= n) tans++;
		if (lu <= n) tans++;
		ans1 += tans;
	}

	for (int i = 1; i <= m; i++) {
		int lca = LCA(Q[i].X, Q[i].Y).X;
		int L = QT[i].X, R = QT[i].Y;
		ans2 += LCA_P[lca];
		ans2 -= LCA_T[L];
		ans2 -= LCA_T[R];
		ans2 += bad_map[QT[i]];
	}


	cout << ans1 - ans2 / 2 << endl;
	return 0;
}