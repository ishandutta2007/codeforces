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

const int N = (int) 707, mod = (int) 0;
int dp[N][N][2], a[N], can[N][N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			can[i][j] = (__gcd(a[i], a[j]) > 1);
	for (int l = n; l >= 0; --l)
		for (int r = l; r <= n; ++r) {
			for (int root = 0; root <= 1; ++root) {
				int last = (root == 0 ? l - 1 : r);
				if (last == -1 || last == n) continue;
				if (r - l == 0) {
					dp[l][r][root] = 1;
				} else if (r - l == 1) {
					if (can[l][last])
						dp[l][r][root] = 1;
				} else {
					for (int m = l; m < r; ++m) {
						if (can[m][last] && dp[l][m][1] && dp[m + 1][r][0]) {
							dp[l][r][root] = 1;
							break;
						}
					}
				}
			}
		}
	for (int m = 0; m < n; ++m)
		if (dp[0][m][1] && dp[m + 1][n][0]) {
			cout << "Yes\n";
			return 0;
		}
	cout << "No\n";
}