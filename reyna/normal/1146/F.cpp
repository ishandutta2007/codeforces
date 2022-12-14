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

const int N = (int) 1e6 + 6, mod = (int) 998244353;
int dp[N][3], p[N], leaf[N];
int mul(int x, int y) { return (LL) x * y % mod; }
int add(int x, int y) { return (x + y) % mod; }
int main() {
	int n;
	cin >> n;
	for (int j = 1; j < n; ++j)
		cin >> p[j], --p[j];
	for (int j = 0; j < n; ++j) leaf[j] = 1, dp[j][0] = 1;
	for (int j = n - 1; j >= 1; --j) {
		leaf[p[j]] = 0;
		if (leaf[j]) {
			dp[j][1] = dp[j][0];
		} else {
			dp[j][0] = add(dp[j][0], dp[j][2]);
			dp[j][1] = add(dp[j][1], dp[j][2]);
		}
		int q = p[j];
		dp[q][2] = add(mul(dp[q][2], dp[j][1]), add(mul(dp[q][2], dp[j][0]), mul(dp[q][1], dp[j][1])));
		dp[q][1] = add(mul(dp[q][1], dp[j][0]), mul(dp[j][1], dp[q][0]));
		dp[q][0] = mul(dp[q][0], dp[j][0]);
	}
	cout << add(dp[0][0], dp[0][2]) << endl;
}