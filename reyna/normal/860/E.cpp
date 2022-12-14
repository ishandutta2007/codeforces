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

const int N = (int) 2e6 + 6, mod = (int) 0;
long long seg[N];
int ch[N], st[N], ed[N], pos[N], head[N], root, h[N], n, sz[N], heavy[N], par[N];
vector<int> adj[N], level[N];
void dfs_heavy(int v) {
	sz[v] = 1;
	heavy[v] = -1;
	level[h[v]].push_back(v);
	for (int u : adj[v]) {
		h[u] = h[v] + 1;
		dfs_heavy(u);
		if (heavy[v] == -1 || sz[u] > sz[heavy[v]]) {
			heavy[v] = u;	
		}
		sz[v] += sz[u];
	}
}
void build(int root) {
	dfs_heavy(root);	
	int tot = 0, ftot = 0;
	for (int v = 0; v < n; ++v)
		if (par[v] == -1 || heavy[par[v]] != v) {
			st[v] = ftot++;
			for (int u = v; u != -1; u = heavy[u])
				pos[u] = tot++, head[u] = v, ftot++;
			ed[v] = ftot;
		}
}
long long fin[N], fcnt[N];
int allcnt[N];
long long f_query(int m, int offset, int lim, long long *f) {
	++m;
	long long res = 0;
	while (m > 0) {
		res += f[m + offset];
		m -= m & -m;
	}
	return res;
}
void f_update(int m, int x, int offset, int lim, long long *f) { ++m;
	while (m + offset < lim) {
		f[m + offset] += x;
		m += m & -m;
	}	
}
long long query(int v) {
	int hd = head[v];
	// [st[hd], ed[hd])
	int m = pos[v] - pos[hd], offset = st[hd], most = ed[hd];
	int overall = allcnt[hd];
	int cnt = f_query(m, offset, most, fcnt);
	long long pref = f_query(m, offset, most, fin);
	long long val = pref + (overall - cnt) * (LL) (m + 1);
	return val;
}

void update(int v) {
	int hd = head[v];
	// [st[hd], ed[hd])
	int m = pos[v] - pos[hd], offset = st[hd], most = ed[hd];
	allcnt[hd]++;
	f_update(m, 1, offset, most, fcnt);
	f_update(m, m + 1, offset, most, fin);
}
/*
void update(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v] += (e - b);
		ch[v]++;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, l, b, m);
	update(i, j, r, m, e);
	seg[v] = seg[l] + seg[r] + ch[v] * (LL) (e - b);
}
long long query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return 0;
	if (i <= b && e <= j) return seg[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	return query(i, j, l, b, m) + query(i, j, r, m, e) + ch[v] * ((LL) min(e, j) - max(b, i));
}
*/
long long res[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> par[j];
		--par[j];
		if (par[j] == -1) {
			root = j;	
		} else {
			adj[par[j]].push_back(j);
		}
	}
	build(root);
	for (int lvl = 0; lvl <= n; ++lvl) {
		for (int v : level[lvl]) {
			while (v != -1) {
				//int l = pos[head[v]], r = pos[v] + 1;
				update(v);
				v = par[head[v]];
			}
		}
		for (int v : level[lvl]) {
			int to_add = v;
			while (v != -1) {
			//	int l = pos[head[v]], r = pos[v] + 1;
				res[to_add] += query(v);
				v = par[head[v]];
			}
		}
	}
	for (int v = 0; v < n; ++v)
		cout << res[v] - h[v] - 1 << ' ';
}