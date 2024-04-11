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

const int N = (int) 805, mod = (int) 1e9 + 7;
long long mod2 = (LL) mod * mod;
long long dp[N], odp[N];
void sadd(long long &x, int y) {
	x += y;
	while (x >= mod) {
		x -= mod;
	}
}
int main() {
//	dp[1] = 1;
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int h = 2; h <= n; ++h) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		for (int xl = 0; xl <= n + 1; ++xl)
			for (int xr = 0; xr + xl <= n + 1; ++xr) {
				dp[xl + xr]	= (dp[xl + xr] + (LL) odp[xl] * odp[xr]) % mod;
				while (dp[xl + xr] >= mod2) dp[xl + xr] -= mod2;
			}
		for (int xl = 0; xl <= n + 1; ++xl) dp[xl] %= mod;
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		for (int xl = 0; xl <= n + 1; ++xl) {
			sadd(dp[xl + 1], odp[xl]);
			sadd(dp[xl], odp[xl]);
			sadd(dp[xl], odp[xl] * (LL) xl * 2 % mod);
			if (xl) sadd(dp[xl - 1], (LL) xl * (xl - 1) % mod * odp[xl] % mod);
		}
	}
	cout << dp[1] << endl;
}