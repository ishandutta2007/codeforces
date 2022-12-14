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

const int N = (int) 5e5 + 5, mod = (int) 0;
int gcd(int x, int y) { return min(x, y) == 0 ? max(x, y) : __gcd(x, y); }
int n, a[N], seg[N << 2];
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		seg[v] = a[b];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	seg[v] = gcd(seg[l], seg[r]);
}
void update(int pos, int x, int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		seg[v] = x;
		a[b] = x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	if (pos < m) {
		update(pos, x, l, b, m);	
	} else {
		update(pos, x, r, m, e);
	}
	seg[v] = gcd(seg[l], seg[r]);
}
int query(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return n;
	if (seg[v] % x == 0) return n;
	if (b + 1 == e) return b;
	int m = b + e >> 1, l = v << 1, r = l | 1;
	int xl = query(i, j, x, l, b, m);
	if (xl == n) {
		return query(i, j, x, r, m, e);	
	}
	return xl;
}
int find_true(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return 1;
	if (i <= b && e <= j) return seg[v] % x == 0;
	int m = b + e >> 1, l = v << 1, r = l | 1;
	return find_true(i, j, x, l, b, m) & find_true(i, j, x, r, m, e);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	build();
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			--l;
			int pos = query(l, r, x);
			if (pos == n) {
				cout << "YES\n";	
			} else {
				if (find_true(l, pos, x) & find_true(pos + 1, r, x)) {
					cout << "YES\n";	
				} else {
					cout << "NO\n";
				}
			}
		} else {
			int pos, x;
			cin >> pos >> x;
			--pos;
			update(pos, x);
		}
	}
}