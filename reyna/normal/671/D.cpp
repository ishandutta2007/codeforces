// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 3e5 + 5, L = 20, mod = 0;
#define mp make_pair
#define int long long
int sz[N], h[N], par[N][L], mark[N];
long long dp[N], sum[N], cost[N], cs[N];
vector<int> query[N], hpop[N], adj[N];

void pre_dfs(int v = 0, int p = 0) {
	if (v)
		h[v] = h[p] + 1;
	par[v][0] = p;
	for (int i = 1; i < L; ++i)
		par[v][i] = par[par[v][i - 1]][i - 1];
	sz[v] = 1;
	for (int u : adj[v]) if (u != p) {
		pre_dfs(u, v);
		sz[v] += sz[u];
	}
}

int go_up(int v, int k) {
	rep(i, L) if (k >> i & 1)
		v = par[v][i];
	return v;
}

int lca(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	u = go_up(u, h[u] - h[v]);
	if (u == v)
		return v;
	for (int i = L - 1; i >= 0; --i)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

set<pair<int, int>> st;
long long add = 0;

void dfs_add(int v, int p = 0, int d = 0) {
	for (int q : query[v]) if (mark[q])
		cost[q] = d + sum[v] - add + cs[q], st.insert(mp(cost[q], q));
	for (int u : adj[v]) if (u != p)
		dfs_add(u, v, d + sum[v] - dp[u]);
}

void dfs(int v, int p = 0) {
	pair<int, int> mx = mp(0, -1);
	for (int u : adj[v]) if (u != p) {
		mx = max(mx, mp(sz[u], u));
	}
	for (int u : adj[v]) if (u != p && u != mx.second) {
		dfs(u, v);
		add = 0;
		st.clear();
	}
	if (mx.second != -1) {
		dfs(mx.second, v);
	}
	for (int q : hpop[v])
		mark[q] = 0, st.erase(mp(cost[q], q));
	for (int u : adj[v]) if (u != p)
		sum[v] += dp[u];
	if (mx.second != -1)
		add += sum[v] - dp[mx.second];
	for (int u : adj[v]) if (u != p && u != mx.second) {
		dfs_add(u, v, sum[v] - dp[u]);
	}
//	long long res = 0;
//	for (int q : hpop[v]) {
//		mark[q] = 0;
//		st.erase(mp(cost[q], q));
//	}
	for (int q : query[v]) {
//		if (v == 1)
//			cout << q << endl;
		cost[q] = sum[v] - add + cs[q];
		st.insert(mp(cost[q], q));
	}
	if (v == 0)
		return;
	if (st.size() == 0) {
		cout << -1 << endl;
		exit(0);
	}
	dp[v] = (*(st.begin())).first + add;
}

int32_t main() {
	memset(mark, 1, sizeof mark);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	adj[0].push_back(1);
	adj[1].push_back(0);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	n++;
	pre_dfs(0);
	rep(i, m) {
		int u, v, c;
		cin >> u >> v >> c;
		cost[i] = c;
		cs[i] = c;
		v = lca(u, v);
		if (u != v) {
			if (v == 1)
				v = 0;
			hpop[v].push_back(i);
			query[u].push_back(i);
		}
	}
	cs[m] = 0;
	query[1].push_back(m);
	dfs(0);
	cout << dp[1] << '\n';
	return 0;
}