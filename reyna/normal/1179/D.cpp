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
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
#define int long long
const int N = (int) 5e5 + 5, mod = (int) 0;
vector<int> adj[N];
int n, ed[N], st[N], tot, sz[N], mn[N << 2], ch[N << 2];
int apply(int v, int x) {
	mn[v] += x;
	ch[v] += x;
}
void push(int v) {
	if (!ch[v]) return;
	apply(mn[v << 1 | 0], ch[v]);
	apply(mn[v << 1 | 1], ch[v]);
	ch[v] = 0;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		apply(v, x);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	mn[v] = min(mn[l], mn[r]);
}
int query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return 1e18;
	if (i <= b && e <= j) return mn[v];
	int m = b + e >> 1, l =  v << 1, r = l | 1;
	push(v);
	return min(query(i, j, l, b, m), query(i, j, r, m, e));
}
void dfs_init(int v, int p = -1) {
	st[v] = tot++;
	for (int u : adj[v]) if (u != p) {
		dfs_init(u, v);
		sz[v] += sz[u];
	}
	++sz[v];
	ed[v] = tot;
}
int s[N];
int dfs_res(int v, int p = -1) {
	int res = 1e18;
	int tpn = n - sz[v];
	int sm = tpn;
	for (int u : adj[v]) if (u != p) {
		res = min(res, dfs_res(u, v));
		sm += sz[u];
	}
	int cnt = 0;
	for (int u : adj[v]) if (u != p) {
		++cnt;
		int cur_mn = query(st[u], ed[u]);
//		all.pb(cur_mn - (sz[u] * (sz[u] - 1) / 2));
		res = min(res, (sm - sz[u]) * (sm - sz[u] - 1) / 2 + cur_mn);	
	}
	vector<pair<int, int>> all;
	for (int x : adj[v]) if (x != p) {
		int cx = query(st[x], ed[x]);
		int sx = sz[x];
		all.pb(mp(2 * cx + (-(2 * n - 1) * sx + sx * sx), -sx));
	}
	sort(ALL(all));
	for (auto &x : all) x.second *= -1;
	int h = 0, t = 0, mn = 1e18;
	for (int j = 0; j < (int) all.size(); ++j) {
		int sx = all[j].second, px = all[j].first;
		while (t - h > 1 && (all[s[h + 1]].first - all[s[h]].first + all[s[h]].second - all[s[h + 1]].second - 1) / 
				(all[s[h]].second - all[s[h + 1]].second) <= sx) ++h;
		if (t - h != 0) res = min(res, (n * (n - 1) + all[s[h]].first + px + 2 * sx * all[s[h]].second) / 2);
		if (sx < mn) {
			mn = min(mn, sx);
			while (t - h > 1 && (all[s[t - 1]].first - all[s[t - 2]].first + all[s[t - 2]].second- all[s[t - 1]].second - 1) /
					(all[s[t - 2]].second - all[s[t - 1]].second) > (px - all[s[t - 1]].first + all[s[t - 1]].second - sx - 1) / 
					(all[s[t - 1]].second - sx)) --t;
			s[t++] = j;
		}
	}
	/*
	for (int x : adj[v]) for (int y : adj[v]) if (x != p && y != p && x != y) {
		
//		cout << " hello " << x << ' ' << y << ' ' << query(st[x], ed[x]) << ' ' << query(st[y], ed[y]) << endl;
	//	res = min(res, query(st[x], ed[x]) + query(st[y], ed[y]) + sm * (sm - 1) / 2
	//			- (sz[x] * (sm - sz[x]) + sz[y] * (sm - sz[y]) - sz[y] * sz[x])) + (sz[x] * (sz[x] - 1) / 2) + (sz[y] * (sz[y] - 1) / 2); 
		
		int cx = query(st[x], ed[x]), cy = query(st[y], ed[y]);
		int sx = sz[x], sy = sz[y];
		int cur_res = cx + cy +  (n * (n - 1) - (2 * n - 1) * (sx + sy) + sx * sx + sy * sy + 2 * sx * sy) / 2;
		res = min(res, cur_res);
	}
	*/
/*	{
		int mn0 = 1e18, mn1 = 1e18;
		for (int x : all) {
			if (mn0 > x) mn1 = mn0, mn0 = x;
			else if (mn1 > x) mn1 = x;
		}
		res = min(res, mn0 + mn1 + sm);
	} */
	
	if (cnt) update(st[v], st[v] + 1, 1e18);
	for (int u : adj[v]) if (u != p) {
//		cout << " : )) " << v << ' ' << u << ' ' << n - sz[u] - tpn << endl;
		update(st[u], ed[u], (n - sz[u] - tpn) * (n - sz[u] - tpn - 1) / 2);
	}
	return res;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	dfs_init(0);
	cout << n * (n - 1) - dfs_res(0) << endl;
	
}