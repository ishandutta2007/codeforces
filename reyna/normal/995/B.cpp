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

const int N = (int) 205, mod = (int) 0;
int xl[N], xr[N], a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < 2 * n; ++j) cin >> a[j], --a[j];
	for (int j = 0; j < 2 * n; ++j) {
		if (xl[a[j]] == 0) {
			xl[a[j]] = j + 1;
		} else {
			xr[a[j]] = j + 1;
		}
	}
	int res = 0;
	for (int x = 0; x < n; ++x)
		for (int y = x + 1; y < n; ++y) {
			if (max(xl[x], xl[y]) < min(xr[x], xr[y])) {
				++res;
			}
			if (xl[x] < xl[y] && xr[y] < xr[x]) {
				++res;
			}
			if (xl[y] < xl[x] && xr[x] < xr[y]) {
				++res;
			}
		}
	cout << res << endl;
}