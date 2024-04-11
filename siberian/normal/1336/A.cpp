#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
const int MAXN = 2e5 + 10;
int n, k;
vector<int> g[MAXN];

void read() {
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int h[MAXN];
int sz[MAXN];

void dfs_h(int v, int p) {
	sz[v] = 1;
	h[v] = h[p] + 1;
	for (auto i : g[v]) {
		if (i == p) continue;
		dfs_h(i, v);
		sz[v] += sz[i];
	}
}

int ans;

void run() {
	dfs_h(0, 0);
	vector<int> order(n);
	iota(all(order), 0);
	sort(all(order), [&] (int a, int b) {return h[a] - sz[a] > h[b] - sz[b];});
	ans = 0;
	for (int i = 0; i < k; i++) {
		ans += h[order[i]] - sz[order[i]];
	}
}

void write() {
	cout << ans << endl;
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