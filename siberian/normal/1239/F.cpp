#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;

struct ed{
	int u, v;
	ed() {}
	ed(int a, int b) {
		u = a, v = b;
	}
};

int n, m;
vector<vector<int> > g;
vector<ed> edge;
vector<bool> used;
vector<int> h, par, color, path;
bool flag;

void out(vector<int> & ans) {
	cout << "Yes\n";
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i + 1 << " ";
	cout << "\n";
}

bool make_xor(vector<int> a) {
	vector<bool> have(n);
	for (auto i : a)
		have[i] = true;
	a.clear();
	for (int i = 0; i < n; i++)
		if (!have[i])
			a.push_back(i);
	if (!a.empty() && a.size() != n) {
		out(a);
		return true;
	}
	return false;
}

bool solve1() {
	for (int i = 0; i < n; i++) {
		if (g[i].size() % 3 == 0) {
			return make_xor({i});
		}
	}
	return make_xor({});
}

void dfs_h(int v, int len, int p) {
	used[v] = true;
	h[v] = len++;
	par[v] = p;
	for (auto i : g[v]) {
		if (g[i].size() % 3 != 2) continue;
		if (used[i]) continue;
		dfs_h(i, len, v);
	}
}

bool solve2() {
	used.assign(n, false);
	h.assign(n, 0);
	par.assign(n, -1);
	for (int i = 0; i < n; i++) {
		if (g[i].size() % 3 != 2) continue;
		if (used[i]) continue;
		dfs_h(i, 0, -1);
	}

	pair <int, int> fans = {INF, INF};

	for (int i = 0; i < m; i++) {
		int v = edge[i].v;
		int u = edge[i].u;

		if (g[v].size() % 3 != 2) continue;
		if (g[u].size() % 3 != 2) continue;
		if (h[v] > h[u]) swap(v, u);
		if (par[u] == v) continue;
		fans = min(fans, make_pair(h[u] - h[v], i));
	}
	
	if (fans.first == INF) {
		return make_xor({});
	}

	vector<int> ans;
	int v = edge[fans.second].v;
	int u = edge[fans.second].u;	
	if (h[v] > h[u]) swap(v, u);
	while (u != v) {
		ans.push_back(u);
		u = par[u];
	}	
	ans.push_back(v);
	return make_xor(ans);
}

bool solve3() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += g[i].size() % 3 == 1;
	}
	if (cnt < 2) {
		return make_xor({});
	}

	used.assign(n, false);
	par.assign(n, -1);
	deque<ed> q;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		if (g[i].size() % 3 != 1) continue;
		used[i] = true;
		q.push_back({i, -1});
		while (!q.empty()) {
			auto x = q[0];
			q.pop_front();
			for (auto u : g[x.u]) {
				if (u == x.v) continue;
				if (used[u]) continue;
				if (g[u].size() % 3 == 2) {
					q.push_back({u, x.u});
					par[u] = x.u;
					used[u] = true;
				}
				else {
					vector<int> ans;
					par[u] = x.u;
					while (u != i) {
						ans.push_back(u);
						u = par[u];
					}
					ans.push_back(i);
					return make_xor(ans);
				}
			}
		}		
	}
	return make_xor({});
}

void dfs_color(int v, int c) {
	used[v] = true;
	color[v] = c;
	for (auto i : g[v]) {
		if (!used[i]) {
			dfs_color(i, c);
		}
	}
}

void dfs_path(int v, int p) {
	used[v] = true;
	path.push_back(v);
	for (auto i : g[v]) {
		if (i != p && g[i].size() % 3 == 1) {
			flag = true;
			return;
		}
	}
	for (auto i : g[v]) {
		if (i == p) continue;
		if (!used[i])
			dfs_path(i, v);
		if (flag) return;
	}
	if (flag) return;
	path.pop_back();
}

bool solve4() {
	int v = -1;
	for (int i = 0; i < n; i++) {
		if (g[i].size() % 3 == 1) {
			if (v != -1) {
				return make_xor({});
			}
			v = i;
		}
	}
	if (v == -1) {
		return make_xor({});
	}

	used.assign(n, false);
	color.assign(n, 0);
	used[v] = true;
	int c = 0;
	for (auto i : g[v]) {
		if (!used[i]) {
			dfs_color(i, c++);
		}
	}

	vector<int> ans;

	flag = false;
	used.assign(n, false);
	used[v] = true;

	for (auto i : g[v]) {
		if (color[i] == 0) {
			dfs_path(i, v);
			break;
		}
	}

	for (auto i : path)
		ans.push_back(i);
	path.clear();

	flag = false;

	for (auto i : g[v]) {
		if (color[i] == 1) {
			dfs_path(i, v);
			break;
		}
	}

	for (auto i : path)
		ans.push_back(i);
	path.clear();

	ans.push_back(v);
	return make_xor(ans);
}

void solve() {
	cin >> n >> m;
	g.assign(n, {});
	edge.clear();
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
		edge.push_back({u, v});
	}
	if (solve1()) return;
	if (solve2()) return;
	if (solve3()) return;
	if (solve4()) return;
	cout << "No\n";
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}