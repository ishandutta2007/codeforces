#include <bits/stdc++.h>

using namespace std;
const int N = 300005;
vector<int> g[N];
int dpt[N], fa[N], nxt[N], mxd[N], dp[N], sz[N];

void dfs1(int p) {
	for (int i: g[p]) {
		if (i == fa[p]) continue;
		dpt[i] = dpt[p] + 1;
		fa[i] = p;
		dfs1(i);
		if (mxd[i] > mxd[p]) {
			nxt[p] = i;
			mxd[p] = mxd[i];
		}
	}
	if (!mxd[p]) mxd[p] = dpt[p];
}

void dfs2(int p) {
	dp[p] = max(dp[fa[p]], dpt[p]);
	for (int i: g[p]) {
		if (i == fa[p] || i == nxt[p]) continue;
		dp[p] = max(dp[p], mxd[i]);
	}
	if (nxt[p]) dfs2(nxt[p]);
}

void dfs3(int p) {
	if (g[p].size() + (p == 1) == 1) {
		sz[p] = 1;
		return;
	}
	if (g[p].size() + (p == 1) == 2) {
		int x;
		for (int i: g[p]) if (i != fa[p]) x = i;
		dfs3(x);
		sz[p] = max(sz[x], mxd[x] - dpt[p] + 1);
		return;
	}
	vector<int> v;
	for (int i: g[p]) {
		if (i == fa[p]) continue;
		dfs3(i);
		sz[p] = max(sz[p], sz[i]);
		v.push_back(mxd[i] - dpt[p]);
	}
	sort(v.begin(), v.end(), greater<int>());
	sz[p] = max(sz[p], v[0] + v[1] + 1);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		g[i].clear();
		dpt[i] = fa[i] = nxt[i] = mxd[i] = dp[i] = sz[i] = 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs1(1);
	dfs2(1);
	dfs3(1);
	int p = 1;
	for (int i = 1; i <= n; ++i) {
		if (i >= mxd[1]) {
			cout << mxd[1] << ' ';
			continue;
		}
//		while (fa[p] && max(dp[p], sz[nxt[p]] / 2 + i) >= max(dp[fa[p]], sz[p] / 2 + i)) p = fa[p];
		while (nxt[nxt[p]] && max(dp[p], sz[nxt[p]] / 2 + i) >= max(dp[nxt[p]], sz[nxt[nxt[p]]] / 2 + i)) p = nxt[p];
		cout << max(dp[p], sz[nxt[p]] / 2 + i) << ' ';
	}
	cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}