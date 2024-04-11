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

const int N = (int) 1e6 + 6, mod = (int) 0, oo = 2e9;
struct rec {
	int xl, xr, yl, yr;
	rec(){}
	rec(int _xl, int _xr, int _yl, int _yr) {
		xl = _xl;
		xr = _xr;
		yl = _yl;
		yr = _yr;
	}
	
};
rec merge(rec a, rec b) {
	rec c = rec(max(a.xl, b.xl), min(a.xr, b.xr), max(a.yl, b.yl), min(a.yr, b.yr));
	return c;
}
rec pre[N], suf[N], a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int xl, xr, yl, yr;
		cin >> xl >> yl >> xr >> yr;
		++xr, ++yr;
		a[j] = rec(xl, xr, yl, yr);
	}
	pre[0] = rec(-oo, oo, -oo, oo);
	suf[n] = rec(-oo, oo, -oo, oo);
	for (int j = 0; j < n; ++j)
		pre[j + 1] = merge(pre[j], a[j]);
	for (int j = n - 1; j >= 0; --j)
		suf[j] = merge(suf[j + 1], a[j]);
	for (int j = 0; j < n; ++j) {
		rec x = merge(pre[j], suf[j + 1]);
		if (x.xl < x.xr && x.yl < x.yr) {
			cout << x.xl << ' ' << x.yl << endl;
			return 0;
		}
	}
}