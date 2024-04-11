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

const int N = (int) 2005, mod = (int) 0;
vector<int> px, py;
int xmx[N], mark[N], match[N], par[2][N][N], xl[N], xr[N], yl[N], yr[N], xmn[N], ymx[N], ymn[N], ax[N], ay[N], bx[N], by[N];;
vector<int> res, adj[N], all[2][N];
int find(int x, int *par) {
	return x == par[x] ? x : par[x] = find(par[x], par);	
}
void dfs_see(int v) {
	if (v == -1) return;
	if (mark[v]) return;
	res.pb(v);
	mark[v] = 1;
	for (int u : adj[v]) if (!mark[u]) {
		mark[u] = 1;
		dfs_see(match[u]);	
	}
}
int dfs(int v) {
	if (v == -1) return 1;
	if (mark[v]) return 0;
	mark[v] = 1;
	for (int u : adj[v]) if (dfs(match[u])) {
		match[u] = v;
		match[v] = u;
		return 1;
	}
	return 0;
}
int unite(int u, int v, int *par) {
	u = find(u, par);
	v = find(v, par);
	if (u == v) return 0;
	par[u] = v;
	return 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ax[i] >> ay[i];
		px.pb(ax[i]);
		py.pb(ay[i]);
	}
	sort(ALL(px));
	sort(ALL(py));
	px.resize(unique(ALL(px)) - px.begin());
	py.resize(unique(ALL(py)) - py.begin());
	for (int i = 0; i < n; ++i) {
		bx[i] = ax[i];
		by[i] = ay[i];
		ax[i] = lower_bound(ALL(px), ax[i]) - px.begin();
		ay[i] = lower_bound(ALL(py), ay[i]) - py.begin();
		all[0][ax[i]].pb(ay[i]);
		all[1][ay[i]].pb(ax[i]);
	}
	for (int r = 0; r <= 1; ++r)
		for (int i = 0; i < N; ++i)
			sort(ALL(all[r][i]));
	int c0 = 0, c1 = 0, c = 0;
	for (int r = 0; r <= 1; ++r)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < (int) all[r][i].size() - 1; ++j) {
				int &px = xl[c], &py = yl[c], &qx = xr[c], &qy = yr[c];
				if (r == 0) {
					px = qx = i;
					py = all[r][i][j];
					qy = all[r][i][j + 1];
				} else {
					py = qy = i;
					px = all[r][i][j];
					qx = all[r][i][j + 1];
				}
				++c;
				if (r == 0) c0++; else c1++;
			}
	for (int j = 0; j < c0; ++j)
		for (int i = c0; i < c; ++i) {
			if (yl[j] < yl[i] && yl[i] < yr[j] && xl[i] < xl[j] && xl[j] < xr[i]) {
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	memset(match, -1, sizeof match);
	for (int i = 0; i < c0; ++i)
		if (match[i] == -1) {
			memset(mark, 0, sizeof mark);
			dfs(i);
		}
	memset(mark, 0, sizeof mark);
	for (int i = 0; i < c0; ++i)
		if (match[i] == -1)
			dfs_see(i);
	for (int i = c0; i < c; ++i)
		if (match[i] != -1 && !mark[i])
			res.pb(i);
	memset(mark, 0, sizeof mark);
	for (int i = c0; i < c; ++i)
		if (match[i] == -1)
			dfs_see(i);
	for (int r = 0; r <= 1; ++r)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				par[r][i][j] = j;
	memset(mark, 0, sizeof mark);
	for (int j : res) mark[j] = 1;
	/*
	for (int i = 0; i < c0; ++i)
		for (int j = 0; j < c0; ++j) if (i != j && mark[i] && mark[j])
			if (yr[i] == yl[j] && xl[i] == xl[j]) {
				unite(i, j, par[0][xl[i]]);
			}
	for (int i = c0; i < c; ++i)
		for (int j = c0; j < c; ++j) if (i != j && mark[i] && mark[j])
			if (xr[i] == xl[j] && yl[i] == yl[j])
				unite(i, j, par[1][yl[i]]);
				*/
	for (int j : res) {
		if (j < c0) {
			unite(yl[j], yr[j], par[0][xl[j]]);	
		} else {
			unite(xl[j], xr[j], par[1][yl[j]]);
		}
	}
	vector<pair<int, pair<int, int>>> red, blue;
	for (int i = 0; i < N; ++i) {
		if (all[0][i].size()) {
			int mx = -1;
			for (int j = 0; j < (int) all[0][i].size(); ++j) {
				int pos = all[0][i][j];
				if (pos > mx) {
					int nxt = find(pos, par[0][i]);
					mx = max(mx, nxt);
					red.pb(mp(i, mp(pos, nxt)));
				}
			}
		}
		if (all[1][i].size()) {
			
			int mx = -1;
			for (int j = 0; j < (int) all[1][i].size(); ++j) {
				int pos = all[1][i][j];
				if (pos > mx) {
					int nxt = find(pos, par[1][i]);
					mx = max(mx, nxt);
					blue.pb(mp(i, mp(pos, nxt)));
				}
			}
		}
	}
	cout << (int) blue.size() << endl;
	for (auto x : blue) cout << px[x.y.x] << ' ' << py[x.x] << ' ' << px[x.y.y] << ' ' << py[x.x] << '\n';
	cout << (int) red.size() << endl;
	for (auto x : red) cout << px[x.x] << ' ' << py[x.y.x] << ' ' << px[x.x] << ' ' << py[x.y.y] << '\n';
				
	
}