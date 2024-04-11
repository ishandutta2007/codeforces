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
int a[N], b[N];
int32_t main() {
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < m; ++j) cin >> b[j];
	if (k >= n || k >= m) {
		cout << -1 << endl;
		return 0;
	}
	int res = 0;
	for (int cancel = 0; cancel <= k; ++cancel) {
		int ot = k - cancel;
		int early = a[cancel];
		early += ta;
		int pos = lower_bound(b, b + m, early) - b;
		pos += ot;
		if (pos >= m) {
			cout << -1 << endl;
			return 0;
		}
		res = max(res, b[pos] + tb);
	}
	cout << res << endl;
}