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

const int N = (int) 3e7 + 7, M = 2e5 + 5, mod = (int) 0;
int n, sz, seg[N], cl[N], cr[N], p[M], root[M];
int build(int b = 0, int e = n) {
	int v = sz++;
	if (b + 1 == e) {
		return v;	
	}
	int m = b + e >> 1;
	cl[v] = build(b, m);
	cr[v] = build(m, e);
	return v;
}
int query(int i, int j, int v, int b = 0, int e = n) {
	if (i >= e || b >= j) return 0;
	if (i <= b && e <= j) return seg[v];
	int m = b + e >> 1;
	return query(i, j, cl[v], b, m) + query(i, j, cr[v], m, e);
}
int update(int pos, int x, int id, int b = 0, int e = n) {
	int v = sz++;
	cl[v] = cl[id];
	cr[v] = cr[id];
	seg[v] = seg[id];
	if (b + 1 == e) {
		seg[v] += x;
		return v;
	}
	int m = b + e >> 1;
	if (pos < m) {
		cl[v] = update(pos, x, cl[v], b, m);	
	} else {
		cr[v] = update(pos, x, cr[v], m, e);
	}
	seg[v] = seg[cl[v]] + seg[cr[v]];
	return v;
}
long long cnt[9];
int main() {
	ios_base::sync_with_stdio(0);
	int q;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) {
		cin >> p[j];
		--p[j];
	}
	root[0] = build();
	for (int j = 0; j < n; ++j) {
		root[j + 1] = update(p[j], +1, root[j]);
	}
	for (int j = 0; j < q; ++j) {
		int xl, yl, xr, yr;
		cin >> xl >> yl >> xr >> yr;
		--xl;
		--yl;
//		swap(xl, yl);
//		swap(xr, yr);
		for (int area = 0; area < 9; ++area) {
			int row = area / 3, col = area % 3;
			int sty, edy;
			if (row == 0) sty = 0, edy = yl;
			if (row == 1) sty = yl, edy = yr;
			if (row == 2) sty = yr, edy = n;
			cnt[area] = 0;
			if (col == 0) cnt[area] = query(sty, edy, root[xl]);
			if (col == 1) cnt[area] = query(sty, edy, root[xr]);
			if (col == 2) cnt[area] = edy - sty;
		}
		for (int j = 8; j >= 0; --j)
			if (j % 3 != 0)
				cnt[j] -= cnt[j - 1];
		long long res = n * (LL) (n - 1) / 2;
		for (int j = 0; j < 9; ++j) if (j != 4) res -= (LL) cnt[j] * (cnt[j] - 1) / 2;
		res -= cnt[0] * (cnt[1] + cnt[2] + cnt[3] + cnt[6]);
		res -= cnt[6] * (cnt[3] + cnt[7] + cnt[8]);
		res -= cnt[8] * (cnt[7] + cnt[5] + cnt[2]);
		res -= cnt[2] * (cnt[5] + cnt[1]);
		cout << res << '\n';
	}
}