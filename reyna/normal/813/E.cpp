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

const int N = (int) 1e6 + 6, M = N * 10, mod = (int) 0;
int n, lc[M], rc[M], add[M], sz = 0, root[N], a[N];
vector<int> all[N];
int build(int b = 0, int e = n) {
	int v = sz++;
	if (b + 1 == e) {
		return v;
	}
	int m = b + e >> 1;
	lc[v] = build(b, m);
	rc[v] = build(m, e);
	return v;
}
int update(int i, int j, int x, int id, int b = 0, int e = n) {
	if (i >= e || b >= j) return id;
	int v = sz++;
	add[v] = add[id];
	lc[v] = lc[id];
	rc[v] = rc[id];
	if (i <= b && e <= j) {
		add[v] += x;
		return v;
	}
	int m = b + e >> 1;
	lc[v] = update(i, j, x, lc[v], b, m);
	rc[v] = update(i, j, x, rc[v], m, e);
	return v;
}
int query(int pos, int v, int b = 0, int e = n) {
	if (b + 1 == e) return add[v];
	int m = b + e >> 1;
	if (pos < m) {
		return query(pos, lc[v], b, m) + add[v];
	} else {
		return query(pos, rc[v], m, e) + add[v];
	}
}
int main() {
	int k;
	cin >> n >> k;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		all[a[j]].push_back(j);
	}
	root[0] = build();
	for (int r = 0; r < n; ++r) {
		int pos = lower_bound(all[a[r]].begin(), all[a[r]].end(), r) - all[a[r]].begin();
		int l = (pos < k ? 0 : all[a[r]][pos - k] + 1);
		root[r + 1] = update(l, r + 1, 1, root[r]);
	}
	int q;
	cin >> q;
	int lans = 0;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l = ((l + lans) % n) + 1;
		r = ((r + lans) % n) + 1;
		if (l > r) swap(l, r);
		--l;
		cout << (lans = query(l, root[r])) << '\n';
	}
}