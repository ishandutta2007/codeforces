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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool ok;
int n, col[MAXN], T, par[MAXN];
pair<pll, pll> pos[MAXN];
vector<int> c_adj[MAXN], adj[MAXN], C[MAXN], P1, P2, ans;

void dfs_c(int v) {
	par[v] = T;
	C[T].push_back(v);
	for (int u : c_adj[v]) if (par[u] == 0) dfs_c(u);
}

void dfs(int v) {
	if (col[v] == 1) for (int e : C[v]) P1.push_back(e);
	else for (int e : C[v])  P2.push_back(e);
	
	for (int u : adj[v]) {
		if (col[u] == 0) col[u] = 3 - col[v], dfs(u);
		else if (col[u] == col[v]) ok = false;
	}
}

inline int solve() {
	ans.clear();
	ok = true;
	for (int i = 0; i < n + 10; i++) {
		adj[i].clear();
		c_adj[i].clear();
		C[i].clear();
		par[i] = 0;
		pos[i] = {{0, 0}, {0, 0}};
		col[i] = 0;
	}

	cin >> n;
	for (int c = 1; c <= 2; c++) {
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (pos[x].X.X == 0) pos[x].X = {c, i};
			else if (pos[x].Y.X == 0) pos[x].Y = {c, i};
			else ok = false;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (pos[i].X.X != pos[i].Y.X) {
			c_adj[pos[i].X.Y].push_back(pos[i].Y.Y);
			c_adj[pos[i].Y.Y].push_back(pos[i].X.Y);
		}
	}

	T = 0;
	for (int i = 1; i <= n; i++) {
		if (par[i] == 0) {
			T++;
			dfs_c(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (pos[i].X.X == pos[i].Y.X) {
			adj[par[pos[i].X.Y]].push_back(par[pos[i].Y.Y]);
			adj[par[pos[i].Y.Y]].push_back(par[pos[i].X.Y]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (col[i] == 0) {
			P1.clear();
			P2.clear();
			col[i] = 1;
			dfs(i);
			if (P2.size() < P1.size()) swap(P1, P2);
			for (int e : P1) ans.push_back(e);
		}
	}
	
	if (!ok) return cout << -1 << endl, 0;
	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}