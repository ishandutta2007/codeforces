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
const int N = (int) 405, mod = (int) 0;
vector<int> allx, ally;
int cnt, mark[N], black[N][N], row[N], col[N], xl[N], xr[N], yl[N], yr[N], cap[N][N];
void add_edge(int u, int v, int w) {
	cap[u][v] = w;
}
int add_flow(int v, int dest, int f = 1e18) {
	if (v == dest) return f;
	if (mark[v]++) return 0;
	for (int u = 0; u < cnt; ++u) {
		if (cap[v][u]) {
			int x = add_flow(u, dest, min(f, cap[v][u]));
			if (x) {
				cap[v][u] -= x;
				cap[u][v] += x;
				return x;
			}
		}
	}
	return 0;
}
int max_flow(int src, int snk) {
	int res = 0;
	while (true) {
		memset(mark, 0, sizeof mark);
		int x = add_flow(src, snk);
		if (x == 0) break;
		res += x;
	}
	return res;
}
int32_t main() {
	int n, m;
	cin >> n >> m;
	allx.pb(0);
	allx.pb(n);
	ally.pb(0);
	ally.pb(n);
	n = m;
	for (int j = 0; j < n; ++j) {
		cin >> xl[j] >> yl[j] >> xr[j] >> yr[j];
		--xl[j];
		--yl[j];
		allx.pb(xl[j]);
		allx.pb(xr[j]);
		ally.pb(yl[j]);
		ally.pb(yr[j]);
	}
	sort(ALL(allx));
	sort(ALL(ally));
	allx.resize(unique(ALL(allx)) - allx.begin());
	ally.resize(unique(ALL(ally)) - ally.begin());
	for (int j = 0; j < n; ++j) {
		xl[j] = lower_bound(ALL(allx), xl[j]) - allx.begin();
		xr[j] = lower_bound(ALL(allx), xr[j]) - allx.begin();
		yl[j] = lower_bound(ALL(ally), yl[j]) - ally.begin();
		yr[j] = lower_bound(ALL(ally), yr[j]) - ally.begin();
	}
	for (int j = 0; j < n; ++j) {
		for (int x = xl[j]; x < xr[j]; ++x)
			for (int y = yl[j]; y < yr[j]; ++y)
				black[x][y] = 1;
	}
	int src = cnt++;
	int snk = cnt++;
	for (int j = 0; j < (int) allx.size() - 1; ++j) row[j] = cnt++;
	for (int j = 0; j < (int) ally.size() - 1; ++j) col[j] = cnt++;
	for (int x = 0; x < (int) allx.size() - 1; ++x)
		for (int y = 0; y < (int) ally.size() - 1; ++y) {
			if (black[x][y]) {
				add_edge(row[x], col[y], 1e18);	
			}
		}
	for (int x = 0; x < (int) allx.size() - 1; ++x) add_edge(src, row[x], allx[x + 1] - allx[x]);
	for (int y = 0; y < (int) ally.size() - 1; ++y) add_edge(col[y], snk, ally[y + 1] - ally[y]);
	cout << max_flow(src, snk) << endl;
		
	
}