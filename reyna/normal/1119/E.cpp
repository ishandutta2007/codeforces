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
#define int long long
typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int n, a[N], b[N];
int check(int lim) {
	for (int j = 0; j < n; ++j) b[j] = a[j];
	int cur_sat = 0, cur_have = 0;
	for (int j = n - 1; j >= 0; --j) {
		int use = min(b[j] / 2, lim - cur_have);
		cur_have += use;
		b[j] -= use * 2;
		cur_sat += b[j];
		cur_sat = min(cur_sat, cur_have);
	}
	if (cur_have >= lim && cur_sat >= cur_have) return 1;
	return 0;
}
int32_t main() {
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	int bl = 0, br = 1e18 + 1;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (check(bm)) {
			bl = bm;	
		} else {
			br = bm;
		}
	}
	cout << bl << endl;
}