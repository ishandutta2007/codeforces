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
const int N = (int) 3e3 + 3, mod = (int) 0;
int a[N], b[N], dp[N][N];
int32_t main() {
	int n, k, loc;
	cin >> n >> k >> loc;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
	}
	for (int j = 0; j < k; ++j) cin >> b[j];
	sort(a, a + n);
	sort(b, b + k);
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for (int j = 0; j <= n; ++j) {
		for (int i = 0; i <= k; ++i) {
			if (i > 0) smin(dp[j][i], dp[j][i - 1]);
			if (i > 0 && j > 0) smin(dp[j][i], max(dp[j - 1][i - 1], abs(b[i - 1] - loc) + abs(a[j - 1] - b[i - 1])));
		}
	}
	cout << dp[n][k] << endl;
}