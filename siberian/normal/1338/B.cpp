#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e5 + 10;
int n;
vector<int> g[MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

bool used[MAXN];
int h[MAXN];
int par[MAXN];

void dfs_build(int v, int p) {
	par[v] = p;
	h[v] = h[p] + 1;
	used[v] = true;
	for (auto i : g[v]) {
		if (i == p) continue;
		dfs_build(i, v);
		used[v] = false;
	}
}

int ans_min, ans_max;

void run() {
	for (int i = 0; i < n; i++) {
		if ((int)g[i].size() > 1) {
			dfs_build(i, i);
			break;
		}
	}
	bool f1 = false, f2 = false;
	for (int i = 0; i < n; i++) {
		if (!used[i]) continue;
		if (h[i] % 2 == 0) {
			f1 = true;
		} else {
			f2 = true;
		}
	}
	ans_min = 1;
	if (f1 && f2) {
		ans_min = 3;
	}

	ans_max = 0;
	for (int v = 0; v < n; v++) {
		int cnt_leaves = 0;
		int cnt_all = 0;
		for (auto i : g[v]) {
			if (i == par[v]) continue;
			cnt_leaves += used[i];
			cnt_all++;
		}
		if (cnt_leaves > 0) {
			ans_max += cnt_all - cnt_leaves + 1;
		} else {
			ans_max += cnt_all;
		}
	}
}

void write() {
	cout << ans_min << " " << ans_max << endl;
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