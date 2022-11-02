
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2e5 + 10, MAXLOG = 19, max_XOR = 1 << 20;

int n;
vector<int> g[MAXN];
int val[MAXN];

int sparse[MAXN * 2][MAXLOG], tin[MAXN], h[MAXN], timer = 0;
int lg[MAXN * 2];

void dfs(int v, int p) {
	tin[v] = timer++;
	sparse[tin[v]][0] = v;
	for (auto i : g[v]) {
		if (i != p) {
			h[i] = h[v] + 1;
			dfs(i, v);
			sparse[timer++][0] = v;
		}
	}
}

void buildLca() {
	dfs(0, 0);
	for (int i = 2; i < timer; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int l = 1; l < MAXLOG; l++) {
		for (int i = 0; i + (1 << l) <= timer; i++) {
			int u = sparse[i][l - 1], v = sparse[i + (1 << (l - 1))][l - 1];
			if (h[u] < h[v]) {
				sparse[i][l] = u;
			} else {
				sparse[i][l] = v;
			}
		}
	}
}

int lca(int v, int u) {
	int l = tin[v];
	int r = tin[u];
	if (r < l) swap(l, r);
	int log = lg[r - l];
	u = sparse[l][log];
	v = sparse[r - (1 << log) + 1][log];
	if (h[u] < h[v]) {
		return u;
	} else {
		return v;
	}
}

ll start[MAXN], finish[MAXN];
ll calc[max_XOR];

bool used[MAXN];
int sz[MAXN];
int centr;

ll ans[MAXN], diff[MAXN];

void dfs_centroid(int v, int p, int size) {
	sz[v] = 1;
	int mx = 0;
	for (auto i : g[v]) {
		if (i != p && !used[i]) {
			dfs_centroid(i, v, size);
			sz[v] += sz[i];
			mx = max(sz[i], mx);
		}
	}
	mx = max(mx, size - sz[v]);
	if (mx <= size / 2) {
		centr = v;
	}
}

bool check(int num) {
	return __builtin_popcount(num) <= 1;
}

void add_path(int u, int v, ll cnt) {
	int l = lca(u, v);
	if (l != u && l != v) {
		start[u] += cnt;
		start[v] += cnt;
		finish[l] += 2 * cnt;
		diff[l] += 2 * cnt;
		return;
	}
	if (l != u) {
		start[u] += cnt;
		finish[l] += cnt;
		return;
	}
	if (l != v) {
		start[v] += cnt;
		finish[l] += cnt;
		return;
	}
}

void dfs_calc(int v, int p, int XOR, int centr) {
	XOR ^= val[v];
	ll add = 0;
	if (check(XOR)) {
		add_path(v, centr, 1);
	}

	add += calc[XOR];

	for (int i = 0; i < 20; i++)
		add += calc[XOR ^ (1 << i)];
	
	add_path(v, centr, add);
	diff[centr] += add;
	
	for (auto i : g[v]) {
		if (i != p && !used[i]) {
			dfs_calc(i, v, XOR, centr);
		}
	}
}

void dfs_add(int v, int p, int XOR, int add) {
	XOR ^= val[v];
	calc[XOR] += add;
	for (auto i : g[v]) {
		if (i != p && !used[i]) {
			dfs_add(i, v, XOR, add);
		}
	}
}

void solve(int v, int size) {
	if (used[v]) return;
	dfs_centroid(v, -1, size);
	int u = centr;
	used[u] = true;
	
	for (auto i : g[u]) {
		if (used[i]) continue;
		dfs_add(i, u, 0, 1);
	} 
	
	for (auto i : g[u]) {
		if (used[i]) continue;
		dfs_add(i, u, 0, -1);
		dfs_calc(i, u, val[centr], centr);
		dfs_add(i, u, 0, 1);
	}

	for (auto i : g[u]) {
		if (used[i]) continue;
		dfs_add(i, u, 0, -1);
	}	

	for (auto i : g[u]) {
		if (used[i]) continue;
		int help_sz = sz[i];
		if (help_sz > sz[u])
			help_sz = size - sz[u];
		solve(i, help_sz);
	}
}

ll dfs_ans(int v, int p) {
	ans[v] = start[v];
	for (auto i : g[v]) {
		if (i != p) {
			ans[v] += dfs_ans(i, v);
		}
	}
	return ans[v] - finish[v];
}

void read() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		val[i] = 1 << (x - 'a');
	}
}

void run() {
	buildLca();
	solve(0, n);
	dfs_ans(0, 0);
}

void write() {
	for (int i = 0; i < n; i++) {
		cout << ans[i] - diff[i] / 2 + 1 << " ";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}