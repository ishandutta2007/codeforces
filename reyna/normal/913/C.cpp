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
const int N = (int) 32, mod = (int) 0;
long long dp[N];
int32_t main() {
	memset(dp, 63, sizeof dp);
	int n, want;
	cin >> n >> want;
	for (int j = 0; j < n; ++j) cin >> dp[j];
	for (int j = 1; j < N; ++j) dp[j] = min(dp[j], dp[j - 1] * 2);
	int res = 9e18, cur = 0;
	for (int j = 30; j >= 0; --j) {
		if (want >> j & 1) {
			cur += dp[j];
		}
		res = min(res, cur + dp[j]);
	}
	res = min(res, cur);
	cout << res << endl;
}