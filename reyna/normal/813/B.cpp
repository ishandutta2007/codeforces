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
#define double long double
const int N = (int) 0, mod = (int) 0, oo = (int) 1e18;

int32_t main() {
	int x, y, l, r;
	cin >> x >> y >> l >> r;
	set<int> st;
	for (int p = 0; p <= 64; ++p)
		for (int q = 0; q <= 64; ++q) {
			int x0 = 1, y0 = 1;
			for (int j = 0; j < p; ++j) {
				if ((double) x0 * x > oo) {
					x0 = oo;
				} else {
					x0 = x0 * x;
				}
			}
			for (int j = 0; j < q; ++j) {
				if ((double) y0 * y > oo) {
					y0 = oo;
				} else {
					y0 = y0 * y;
				}
			}
			int val = x0 + y0;
			if (l <= val && val <= r) {
				st.insert(val);	
			}
		}
	vector<int> v;
	v.push_back(l - 1);
	for (int x : st) v.push_back(x);
	v.push_back(r + 1);
	int res = 0;
	for (int j = 0; j < (int) v.size() - 1; ++j)
		res = max(res, v[j + 1] - v[j] - 1);
	cout << res << endl;
}