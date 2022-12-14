
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

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1 << 22, mod = (int) 998244353;
int f[N], inv[N], dp[N];
int pw(int a, int b) { return b == 0 ? 1 : (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod; }
int comb(int n, int r) {
	if (n == r) return 1;
	if (n - r < 0 || n < 0 || r < 0) return 0;	
	return f[n] * (LL) inv[r] % mod * inv[n - r] % mod;
}
int main() {
	f[0] = inv[0] = 1;
	for (int j = 1; j < N; ++j) f[j] = f[j - 1] * (LL) j % mod, inv[j] = pw(f[j], mod - 2);
	int n, m; 
	cin >> n >> m;
	dp[0] = 0;
	int to_sum = 0, c_sum = comb(m-1,m-1);
	int invm1 = pw(m+1, mod - 2);
	for (int k = 1; k <= n; ++k) {
		dp[k] = 1;
	//	for (int i = 1; i <= k; ++i) {
		//	dp[k] = (dp[k] + (LL) (i * (LL) comb(k-i+m-1, m-1)) % mod * pw(comb(k+m, m), mod - 2) % mod) % mod;
	//	}
		dp[k] = (dp[k] + to_sum * (LL) pw(comb(k+m, m), mod-2)) % mod;
		dp[k] = (dp[k] + (LL) (n - k) % mod * invm1) % mod;
		dp[k] = dp[k] * (LL) (m + k) % mod * pw(k, mod - 2) % mod;
		to_sum = (to_sum + (LL) dp[k] * comb(k+m-1, m-1)) % mod;
		c_sum = (c_sum + comb(k+m-1, m-1)) % mod;
		to_sum = (to_sum + c_sum) % mod;
	}
	cout << (1 + dp[n]) << endl;
}