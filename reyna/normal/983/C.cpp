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

const int N = (int) 2005, mod = (int) 0;
int add[9][10004], dp[9][10004], odp[9][10004], clear[9][10004], a[N], b[N];
int main() {
	int n;
	cin >> n;
	for (int x = 0; x <= 9999; ++x) {
		for (int s = 0; s < 9; ++s) {
			int nxt = 0, z = 1, nx = 0;
			for (int i = 0; i < 4; ++i) {
				int dig = (x / z) % 10;
				if (dig == s + 1) {
					dig = 0;
				}
				int d = (x / z) % 10;
				if (d == 0 && !nx) {
					nx = z * (s + 1);
				}
				nxt += z * dig;
				z *= 10;
			}
			if (nx) {
				add[s][x] = nx + x;
			} else {
				add[s][x] = -1;
			}
			clear[s][x] = nxt;
		}
	}
	for (int j = 0; j < n; ++j) cin >> a[j] >> b[j], --a[j], --b[j];
	memset(dp, 63, sizeof dp);
	dp[0][0] = 2 * n;
		for (int ss = 0; ss <= 1; ++ss) {
		for (int s = 0; s < 8; ++s)
			for (int i = 0; i < 10000; ++i) {
				dp[s + 1][clear[s + 1][i]] = min(dp[s + 1][clear[s + 1][i]], 1 + dp[s][i]);
			}
		for (int s = 8; s >= 1; --s)
			for (int i = 0; i < 10000; ++i) {
				dp[s - 1][clear[s - 1][i]] = min(dp[s - 1][clear[s - 1][i]], 1 + dp[s][i]);
			}
		}
	for (int j = 0; j < n; ++j) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 63, sizeof dp);
		for (int s = 0; s < 9; ++s) if (a[j] == s)
			for (int i = 0; i < 10000; ++i) {
				if (add[b[j]][i] != -1) {
					dp[s][add[b[j]][i]] = min(dp[s][add[b[j]][i]], odp[s][i]);	
				}
			}
		for (int ss = 0; ss <= 1; ++ss) {
		for (int s = 0; s < 8; ++s)
			for (int i = 0; i < 10000; ++i) {
				dp[s + 1][clear[s + 1][i]] = min(dp[s + 1][clear[s + 1][i]], 1 + dp[s][i]);
			}
		for (int s = 8; s >= 1; --s)
			for (int i = 0; i < 10000; ++i) {
				dp[s - 1][clear[s - 1][i]] = min(dp[s - 1][clear[s - 1][i]], 1 + dp[s][i]);
			}
		}
		
	}
	int res = 1e9;
	for (int j = 0; j < 9; ++j)
		res = min(res, dp[j][0]);
	cout << res << endl;
}