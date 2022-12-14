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

const int N = (int) 1e6 + 6, mod = (int) 0;
map<pair<int, int>, int> ind;
vector<pair<int, int>> seg[N];
int par[N], g[N], bad, sz[N];
pair<int, int> find(int v) {
	if (par[v] == v) return mp(par[v], g[v]);
	auto x = find(par[v]);
	x.second ^= g[v];
	return x;
}
vector<pair<pair<int, int>, int>> history;
void undo_history() {
	auto cur = history.back();
	history.pop_back();
	if (cur.second == -1) return;
	int pu = cur.first.first, pv = cur.first.second, d = cur.second;
	sz[pv] -= sz[pu];
	par[pu] = pu;
	g[pu] ^= d;
}
void unite(int u, int v) {
	int pu = find(u).first;
	int pv = find(v).first;
	int xu = find(u).second;
	int xv = find(v).second;
	if (pu == pv) {
		if (xu == xv) {
			bad = 1;
		}
		history.push_back(mp(mp(-1, -1), -1));
		return;
	}
	if (sz[pu] > sz[pv]) swap(pu, pv), swap(xu, xv);
	history.push_back(mp(mp(pu, pv), xu == xv));
	g[pu] ^= (xu == xv);
	par[pu] = pv;	
	sz[pv] += sz[pu];
}

int n, q;
void add_query(int i, int j, pair<int, int> x, int v = 1, int b = 0, int e = q) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v].push_back(x);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	add_query(i, j, x, l, b, m);
	add_query(i, j, x, r, m, e);
}
void dfs(int v = 1, int b = 0, int e = q) {
	for (auto e : seg[v]) {
		unite(e.first, e.second);	
	}
	if (b + 1 == e) {
		cout << (bad ? "NO\n" : "YES\n");
	} else {
		int m = b + e >> 1, l = v << 1, r = l | 1;
		int tmp = bad;
		dfs(l, b, m);
		bad = tmp;
		dfs(r, m, e);
		bad = tmp;
	}
	for (int j = 0; j < (int) seg[v].size(); ++j) undo_history();
}
int main() {
	cin >> n >> q;
	for (int j = 0; j < n; ++j) sz[j] = 1, par[j] = j;
	for (int j = 0; j < q; ++j) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (x > y) swap(x, y);
		int l = ind[mp(x, y)];
		if (!l) {
			ind[mp(x, y)] = j + 1;
		} else {
			add_query(l - 1, j, mp(x, y));
			ind[mp(x, y)] = 0;
		}
	}
	for (auto x : ind) if (x.second) add_query(x.second - 1, q, x.first);
	dfs();
}