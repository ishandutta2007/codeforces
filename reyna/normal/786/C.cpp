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

const int N = (int) 1e5 + 5, S = N * 40, mod = (int) 0;

int sz, n, root[N], a[N], seg[S], cl[S], cr[S], last[N];

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
	if (pos < m)
		cl[v] = update(pos, x, cl[v], b, m);
	else
		cr[v] = update(pos, x, cr[v], m, e);
	seg[v] = seg[cl[v]] + seg[cr[v]];
	return v;
}

int kval;
int find_nxt(int pos, int v, int b = 0, int e = n) {
	if (e <= pos) return n;
	if (seg[v] <= kval) {
		kval -= seg[v];
		return n;
	}
	if (b + 1 == e) return b;
	int m = b + e >> 1;
	int ansl = find_nxt(pos, cl[v], b, m);
	if (ansl != n) return ansl;
	return find_nxt(pos, cr[v], m, e);
}

int main() {
	scanf("%d", &n);
	for (int j = 0; j < n; ++j)
		scanf("%d", a + j);
	memset(last, -1, sizeof last);
	root[n] = build();
	for (int j = n - 1; j >= 0; --j) {
		int rt = root[j + 1];
		if (last[a[j]] != -1)
			rt = update(last[a[j]], -1, rt);
		last[a[j]] = j;
		rt = update(j, 1, rt);
		root[j] = rt;
	}
	for (int k = 1; k <= n; ++k) {
		int res = 0;
		int cur = 0;
		while (cur < n) {
			kval = k;
			cur = find_nxt(cur, root[cur]);
			++res;
		}
		printf("%d ", res);
	}
}