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

const int N = (int) 1e6 + 5, mod = (int) 1e9 + 7;
int h, w, n, dp[N], ql[N], qr[N], qs[N], qu[N], uo[N], so[N];
bool by_u(int x, int y) { return qu[x] > qu[y]; }
bool by_s(int x, int y) { return qs[x] > qs[y]; }
set<pair<int, int>, greater<pair<int, int>>> seg[N];
void update(int i, int j, int x, int d, int v = 1, int b = 0, int e = w) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		if (d == 1)
			seg[v].insert(make_pair(qu[x], x));
		else
			seg[v].erase(make_pair(qu[x], x));
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, d, l, b, m);
	update(i, j, x, d, r, m, e);
}
int better(int &res, int x) {
	if (qu[x] > qu[res])
		res = x;
	return res;
}
int query(int pos, int v = 1, int b = 0, int e = w) {
	int res = n;
	better(res, (*(seg[v].begin())).second);
	if (b + 1 != e) {
		int m = b + e >> 1, l = v << 1, r = l | 1;
		if (pos < m)
			better(res, query(pos, l, b, m));
		else
			better(res, query(pos, r, m, e));
	}
	return res;
}
void fall(int pos, int add) {
	int p = query(pos);
	dp[p] = (dp[p] + add) % mod;
}
int main() {
	scanf("%d %d %d", &h, &w, &n);
	qu[n] = -1e9;
	for (int j = 0; j < n; ++j) {
		int &u = qu[j], &l = ql[j], &r = qr[j], &s = qs[j];
		scanf("%d %d %d %d", &u, &l, &r, &s); --l;
		s += u;
		uo[j] = j;
		so[j] = j;
	}
	sort(uo, uo + n, by_u);
	sort(so, so + n, by_s);
	for (int j = 0; j < N; ++j) seg[j].insert(make_pair(-1e9, n));
	int pt = 0;
	while (pt < n && qs[so[pt]] >= h + 1) {
		int x = so[pt];
		update(ql[x], qr[x], x, 1);
		++pt;
	}
	for (int j = 0; j < w; ++j) fall(j, 1);
	for (int _ = 0; _ < n; ++_) {
		int j = uo[_];
		while (pt < n && qs[so[pt]] >= qu[j]) {
			int x = so[pt];
			update(ql[x], qr[x], x, 1);
			++pt;
		}
		update(ql[j], qr[j], j, 0);
		{
			if (ql[j] == 0) {
				fall(qr[j], dp[j]);
			} else {
				fall(ql[j] - 1, dp[j]);
			}
		}
		{
			if (qr[j] == w) {
				fall(ql[j] - 1, dp[j]);
			} else {
				fall(qr[j], dp[j]);
			}
		}	
	}
	cout << dp[n] << '\n';
}