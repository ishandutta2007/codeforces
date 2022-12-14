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
const int N = (int) 1e6 + 6, mod = (int) 0;
int sum[N << 2], val[N], suf[N << 2], whole[N << 2], qt[N], qd[N];

void build(int v = 1, int b = 0, int e = N) {
	if (b + 1 == e) {
		whole[v] = -1;
		suf[v] = -1;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	suf[v] = -1;
	whole[v] = whole[l] + whole[r];
}

void update(int pos, int x, int v = 1, int b = 0, int e = N) {
	if (b + 1 == e) {
		val[b] += x;
		whole[v] = val[b] - 1;
		suf[v] = max(-1LL, whole[v]);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	if (pos < m) {
		update(pos, x, l, b, m);
	} else {
		update(pos, x, r, m, e);
	}
	whole[v] = whole[l] + whole[r];
	suf[v] = max(suf[r], suf[l] + whole[r]);
	suf[v] = max(-1LL, suf[v]);
}
pair<int, int> query(int i, int j, int v = 1, int b = 0, int e = N) {
	if (i >= e || b >= j) return mp(-1, 0);
	if (i <= b && e <= j) return mp(suf[v], whole[v]);
	int m = b + e >> 1, l = v << 1, r = l | 1;
	auto xl = query(i, j, l, b, m);
	auto xr = query(i, j, r, m, e);
	int wh = xl.second + xr.second;
	int s = max(xr.first, xl.first + xr.second);
	s = max(-1LL, s);
	return mp(s, wh);
}

int32_t main() {
	int q;
	cin >> q;
	build();
	for (int j = 0; j < q; ++j) {
		char c;
		cin >> c;
		if (c == '+') {
			cin >> qt[j] >> qd[j];
			update(qt[j], qd[j]);
		} else if (c == '-') {
			int i;
			cin >> i;
			--i;
			update(qt[i], -qd[i]);
		} else {
			int t;
			cin >> t;
			cout << 1 + query(0, t + 1).first << '\n';
		}
	}
}