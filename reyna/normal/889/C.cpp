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

const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
int dp[N], sum[N], f[N], inv[N];
int pw(int a, int b) { return b != 0 ? pw((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod : 1; }
int main() {
	f[0] = inv[0] = 1;
	for (int j = 1; j < N; ++j) f[j] = f[j - 1] * (LL) j % mod, inv[j] = pw(f[j], mod - 2);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			dp[i] = 1;
		} else {
			dp[i] = (sum[i] - sum[max(0, i - k)] + mod) % mod * (LL) f[i - 2] % mod;
		}
		sum[i + 1] = (sum[i] + dp[i] * (LL) inv[i - 1]) % mod;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = (res + (LL) dp[i] * f[n - i] % mod * f[n - 1] % mod * inv[n - i] % mod * inv[i - 1] % mod) % mod;
	cout << (f[n] - res + mod) % mod << endl;
}