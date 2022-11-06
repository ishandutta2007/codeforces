#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

const int N = 2000005;

int fac[N], inv[N];

int inverse(int a) {
	return a == 1 ? 1ll : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int binom(int n, int m) {
	return (long long)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (long long)fac[i - 1] * i % MOD;
		inv[i] = inverse(fac[i]);
	}
	int ans = 0;
	int n;
	scanf("%d", &n);
	int leaf = 0;
	for (int k = n; k < 2 * n; ++k) {
		int delta = (long long)binom(k - 1, n - 1) * (2 * n - k) * 2 % MOD;
		(leaf += (long long)binom(k - 1, n - 1) * 2 % MOD) %= MOD;
		(ans += delta) %= MOD;
	}
	(ans += (leaf * 2 - 1) % MOD) %= MOD;
	printf("%d\n", ans);
	return 0;
}