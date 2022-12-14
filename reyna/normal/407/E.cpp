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
#define stack stalk
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], n, k, d, resl = 0, resr = 1;
void do_best(int l, int r) {
	if (r - l > resr - resl) {
		resl = l;
		resr = r;
	} else if (r - l == resr - resl) {
		if (resl > l) {
			resl = l;
			resr = r;
		}
	}
}
int ch[N << 2], seg[N << 2];
void push(int v) {
	ch[v << 1 | 0] += ch[v];
	ch[v << 1 | 1] += ch[v];
	seg[v << 1 | 0] += ch[v];
	seg[v << 1 | 1] += ch[v];
	ch[v] = 0;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		ch[v] += x;
		seg[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	seg[v] = min(seg[l], seg[r]);
}
int find_best(int i, int j, int lim, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return -1;
	if (seg[v] > lim) return -1;
	if (b + 1 == e) {
		return b;
	}
	push(v);
	int m = b + e >> 1, l = v << 1, r = l | 1;
	int ansl = find_best(i, j, lim, l, b, m);
	if (ansl != -1) return ansl;
	return find_best(i, j, lim, r, m, e);
}
struct stack {
	int a[N], sz;
	stack() { memset(a, 0, sizeof a), sz = 0; a[sz++] = -1; }
	int &operator [] (int x) { return a[x]; }
	void clear() { 
		sz = 0; 
		a[sz++] = -1;
	}
} mn, mx;
int32_t main() {
	cin >> n >> k >> d;
	int mnval = 1e9 + 1;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		mnval = min(mnval, a[j]);
	}
	for (int j = 0; j < n; ++j) {
		a[j] -= mnval;	
	}
	if (d == 0) {
		int pt = 0;
		for (int j = 0; j < n; ++j) {
			while (pt < n && a[pt] == a[j]) ++pt;
			do_best(j, pt);
		}
		cout << resl + 1 << ' ' << resr << '\n';
		return 0;
	}
	map<int, int> last;
	int valid_l = 0;
	for (int pos = 0; pos < n; ++pos) {
		if (last.find(a[pos]) != last.end()) {
			int pl = last[a[pos]];
			valid_l = max(valid_l, pl + 1);
		}
		last[a[pos]] = pos;
		if (pos - 1 >= 0) {
			int diff = abs(a[pos] - a[pos - 1]);
			if (diff % d != 0) {
				valid_l = pos;
				mn.clear();
				mx.clear();
			}
		}
		int val = a[pos];
		while (mn.sz > 1) {
			if (val < a[mn[mn.sz - 1]]) {
				update(mn[mn.sz - 2] + 1, mn[mn.sz - 1] + 1, a[mn[mn.sz - 1]] / d);
				--mn.sz;
			} else {
				break;
			}
		}
		update(mn[mn.sz - 1] + 1, pos + 1, -(a[pos] / d));
		mn[mn.sz++] = pos;
		while (mx.sz > 1) {
			if (val > a[mx[mx.sz - 1]]) {
				update(mx[mx.sz - 2] + 1, mx[mx.sz - 1] + 1, -(a[mx[mx.sz - 1]] / d));
				--mx.sz;
			} else {
				break;
			}
		}
		update(mx[mx.sz - 1] + 1, pos + 1, (a[pos] / d));
		mx[mx.sz++] = pos;
		update(pos, pos + 1, pos);
		int bestl = find_best(valid_l, pos + 1, k + pos);
		if (bestl >= valid_l) {
			do_best(bestl, pos + 1);	
		}
	}
	cout << resl + 1 << ' ' << resr << '\n';
}