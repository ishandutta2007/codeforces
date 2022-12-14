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
const int N = (int) 55, mod = (int) 0;
int dp[N][2], a[N];
int32_t main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
	}
	for (int j = 0; j < n; ++j) {
		int x = a[n - j - 1];
		for (int turn = 0; turn <= 1; ++turn) {
			dp[j + 1][turn] = max(dp[j][turn] - x, -dp[j][turn ^ 1] + x);
		}
		sum += x;
	}
	cout << (sum - dp[n][0]) / 2 << ' ' << (sum + dp[n][0]) / 2;
}