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
const int N = (int) 1e5 + 6, M = 10, mod = (int) 0;
int a[N], n, seg[N << 2][M], ch[N << 2][M];
void pull(int v) {
	int l = v << 1, r = l | 1;
	for (int j = 0; j < 10; ++j) seg[v][j] = seg[l][j] + seg[r][j];
}
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		int x = a[b], z = 1;
		while (x != 0) {
			seg[v][x % 10] += z;
			x /= 10;
			z *= 10;
		}
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	pull(v);
}
int old[M];
void apply(int v, int c[M]) {
	memcpy(old, seg[v], sizeof old);
	for (int j = 0; j < 10; ++j) {
		int cur = c[ch[v][j]];
		ch[v][j] = cur;
	}
	memset(seg[v], 0, sizeof seg[v]);
	for (int j = 0; j < 10; ++j) {
		seg[v][c[j]] += old[j];
	}
}
void push(int v) {
	int l = v << 1, r = l | 1;
	apply(l, ch[v]);
	apply(r, ch[v]);
	for (int j = 0; j < 10; ++j) ch[v][j] = j;
}
int res[M];
void query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;	
	if (i <= b && e <= j) {
		for (int k = 0; k < 10; ++k)
			res[k] += seg[v][k];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	query(i, j, l, b, m);
	query(i, j, r, m, e);
}
int to[M];
void update(int i, int j, int x, int y, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		for (int k = 0; k < 10; ++k) to[k] = k;
		to[x] = y;
		apply(v, to);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, y, l, b, m);
	update(i, j, x, y, r, m, e);
	pull(v);
}
int32_t main() {
	for (int j = 0; j < (N << 2); ++j) for (int k = 0; k < 10; ++k) ch[j][k] = k;
	int q;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) cin >> a[j];
	build();
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			--l;
			update(l, r, x, y);
		} else {
			memset(res, 0, sizeof res);
			int l, r;
			cin >> l >> r;
			--l;
			query(l, r);
			long long g = 0;
			for (int j = 0; j < 10; ++j) {
				g += res[j] * j;
			}
			cout << g << '\n';
		}
	}
	
}