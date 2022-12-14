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
int n, a[N], st[N << 2], fl[N << 2], seg[N << 2];
pair<int, int> sr[N];
void pull(int v) {
	seg[v] = seg[v << 1 | 0] + seg[v << 1 | 1];	
}
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		seg[v] = (a[sr[b].second] > 0);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	pull(v);
}
void push(int v, int b, int e) {
	int m = b + e >> 1, l = v << 1, r = l | 1;
	if (st[v] >= 0) {
		fl[v] = fl[l] = fl[r] = 0;
		st[l] = st[r] = st[v];
		seg[l] = (m - b) * st[l];
		seg[r] = (e - m) * st[r];
		st[v] = -1;
		return;
	}
	if (!fl[v]) return;
	fl[v] = 0;
	if (st[l] >= 0) st[l] ^= 1;
	if (st[r] >= 0) st[r] ^= 1;
	fl[l] ^= 1;
	fl[r] ^= 1;
	seg[l] = (m - b) - seg[l];
	seg[r] = (e - m) - seg[r];
}

void update_set(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v] = (e - b) * x;
		fl[v] = 0;
		st[v] = x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, b, e);
	update_set(i, j, x, l, b, m);
	update_set(i, j, x, r, m, e);
	pull(v);
}
void update_flip(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (!x) return;
	if (i <= b && e <= j) {
		seg[v] = (e - b) - seg[v];
		if (st[v] >= 0) {
			st[v] ^= 1;
			fl[v] = 0;
		} else {
			fl[v] ^= 1;
		}
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, b, e);
	update_flip(i, j, x, l, b, m);
	update_flip(i, j, x, r, m, e);
	pull(v);
}
int query(int pos, int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) return seg[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, b, e);
	if (pos < m) {
		return query(pos, l, b, m);
	}
	return query(pos, r, m, e);
}
int all[N], res[N];
int main() {
	memset(st, -1, sizeof st);
	int q;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		all[j] = abs(a[j]);
		sr[j].second = j;
		sr[j].first = all[j];
	}
	sort(all, all + n);
	sort(sr, sr + n);
	build();
	while (q--) {
		char c;
		cin >> c;
		int x;
		cin >> x;
		int posl = lower_bound(all, all + n, abs(x)) - all;
		int posr = upper_bound(all, all + n, abs(x)) - all;
		if (c == '>') {
			if (x < 0) {
				update_flip(0, posl, 1);
				update_set(posl, n, 0);
			} else {
				update_set(posr, n, 0);	
			}
		} else {
			if (x > 0) {
				update_flip(0, posl, 1);
				update_set(posl, n, 1);
			} else {
				update_set(posr, n, 1);	
			}
		}
	}
	for (int j = 0; j < n; ++j) res[sr[j].second] = query(j);
	for (int j = 0; j < n; ++j)
		cout << abs(a[j]) * (res[j] == 0 ? -1 : 1) << ' ';
}