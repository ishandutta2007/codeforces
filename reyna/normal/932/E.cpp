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

const int N = (int) 5005, mod = (int) 1e9 + 7;
int dp[N][N], inv[N];
int pw(int a, int b) { return b == 0 ? 1 : pw((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod; }
int main() {
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int j = 1; j < N; ++j) inv[j] = pw(j, mod - 2);
	for (int sz = 1; sz <= k; ++sz)
		for (int col = 1; col <= sz; ++col)
			dp[sz][col] = (dp[sz - 1][col] * (LL) col + dp[sz - 1][col - 1] * (LL) (n - (col - 1))) % mod;
	int res = 0;
	for (int col = 1; col <= min(n, k); ++col) {
		res = (res + dp[k][col] * (LL) pw(2, n - col)) % mod;
		/*int comb = 1;
		
		for (int j = 0; j < min(n - k, col); ++j) {
			res = (res - comb * (LL) dp[k][sz] % mod + mod);
			if (res >= mod) res -= mod;
			cout << " : ) " << sz << ' ' << j << ' ' << comb << ' ' << comb * dp[k][sz] << endl;
			comb = comb * (LL) (n - col - j) % mod * inv[j + 1] % mod;
		}*/
	}
	cout << res << endl;
}