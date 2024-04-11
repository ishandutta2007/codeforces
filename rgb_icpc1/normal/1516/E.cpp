#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MK = 405;

int dp[MK][MK], _dp[MK][MK];
int c[MK][MK];

int modExp(int a, int n) {
	int r = 1;
	for (; n; n /= 2) {
		if (n & 1) r = 1LL * r * a % MOD;
		a = 1LL * a * a % MOD;
	}
	return r;
}

void init() {
	for (int i = 0; i < MK; i ++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j ++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
}

int C(int n, int m) {
	int res = 1;
	for (int i = n - m + 1; i <= n; i ++) res = 1LL * res * i % MOD;
	for (int i = 1; i <= m; i ++) res = 1LL * res * modExp(i, MOD - 2) % MOD;
	return res;
}

int n, k;
int rlt[MK];

int main() {
	
	init();
	cin >> n >> k;
	
	for (int i = 0; i <= 2 * k; i ++) _dp[i][0] = 1;
	_dp[2][0] = _dp[2][1] = 1;
	
	for (int i = 3; i <= 2 * k; i ++) {
		for (int j = 1; j <= min(C(i, 2), k); j ++) {
			_dp[i][j] = (_dp[i - 1][j] + 1LL * (i - 1) * _dp[i - 1][j - 1] % MOD) % MOD;
		}
	}
	
	for (int i = 0; i <= 2 * k; i ++) {
		for (int j = 0; j <= k; j ++) {
			dp[i][j] = 0;
			for (int l = 0; l <= i; l ++) {
				(dp[i][j] += 1LL * ((l & 1) ? (MOD - 1) : 1) * c[i][l] % MOD * _dp[i - l][j] % MOD) %= MOD;
				
			}
		}
	}
	
	for (int i = 0; i <= 2 * k; i ++) {
		int cc = C(n, i);
		for (int j = 0; j <= k; j ++) {
			(rlt[j] += 1LL * dp[i][j] * cc % MOD) %= MOD;
		}
	}
	
	for (int i = 1; i <= k; i ++) if (i >= 2) (rlt[i] += rlt[i - 2]) %= MOD;

	for (int i = 1; i <= k; i ++) cout << rlt[i] << " \n"[i == k];
}