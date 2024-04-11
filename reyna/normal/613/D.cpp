//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


const int N = 1e5 + 5, sq = 249, lgN = 18, oo = 1e9 + 9;

int read() { int x; cin >> x; return x; }

int mark[N], st[N], ed[N], par[N][lgN], h[N], stamp, dead[N];
ll dp[N][2];
vector<int> adj[N], imp, die;


void dfs_order(int v, int p = 0) {
	st[v] = stamp++;
	par[v][0] = p;
	if (v) h[v] = h[p] + 1;
	for (int i = 1; i < lgN; ++i)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for (int u : adj[v]) if (u != p)
		dfs_order(u, v);
	ed[v] = stamp;
}

void dfs_dp(int v, int p = 0) {
	if (mark[v]) {
		dp[v][0] = oo;
		dp[v][1] = 0;
		for (int u : adj[v]) if (u != p) {
			dfs_dp(u, v);
			dp[v][1] += dp[u][0];
		}
	} else {
		dp[v][0] = 0;
		dp[v][1] = 0;
		ll cnt = 0;
		for (int u : adj[v]) if (u != p) {
			dfs_dp(u, v);
			dp[v][1] = min(dp[v][1] + dp[u][0], dp[v][0] + dp[u][1]);
			dp[v][0] += dp[u][0];
			cnt += dp[u][1];
		}
		dp[v][0] = min(cnt + 1, dp[v][0]);
		dp[v][1] = min(dp[v][1], dp[v][0]);
	}
}

int go_up(int v, int d) {
	for (int i = 0; i < lgN; ++i)
		if (d >> i & 1)
			v = par[v][i];
	return v;
}

int lca(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	u = go_up(u, h[u] - h[v]);
	if (u == v)
		return v;
	for (int i = lgN - 1; i >= 0; --i)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[v][0];
}

int ispar(int u, int v) {
	return st[u] <= st[v] && st[v] < ed[u];
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	for (int i = 1; i < n; ++i) {
		int u = read() - 1, v = read() - 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_order(0, 0);
	int q = read();
	while (q--) {
		int m = read();
		for (int v : imp)
			mark[v] = 0;
		imp.clear();
		for (int i = 0; i < m; ++i) {
			int v = read() - 1;
			imp.push_back(v);
			mark[v] = 1;
		}
		bool fl = 0;
		for (int v : imp) if (v)
			if (mark[par[v][0]]) {
				cout << -1 << '\n';
				fl = 1;
				break;
			}
		if (fl)
			continue;
		if (m > sq) {
			dfs_dp(0, 0);
			cout << min(dp[0][0], dp[0][1]) << '\n';
		} else {
			multiset<pair<int, pair<int, int>>> s;
			for (int i = 0; i < m; ++i)
				for (int j = i + 1; j < m; ++j) {
					int u = imp[i], v = imp[j];
					if (h[u] > h[v])
						swap(u, v);
					if (ispar(u, v)) {
						s.insert({-st[go_up(v, h[v] - h[u] - 1)], {u, v}});
					} else {
						int l = lca(u, v);
						s.insert({-st[l], {u, v}});
					}
				}
			int res = 0;
			while ((int) s.size()) {
				int w = -s.begin()->first, u = s.begin()->second.first, v = s.begin()->second.second;
				s.erase(s.begin());
				if (dead[w]) {
					mark[v] = 0;
					if (!ispar(u, v)) {
						mark[u] = 0;
					}
					continue;
				}
				if (mark[u] && mark[v]) {
					dead[w] = 1;
					die.push_back(w);
					res++;
					mark[v] = 0;
					if (!ispar(u, v)) {
						mark[u] = 0;
					}
				}
			}
			cout << res << '\n';
			for (int x : die)
				dead[x] = 0;
			die.clear();
		}
	}
	
	
	
}