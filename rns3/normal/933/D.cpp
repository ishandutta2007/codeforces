#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int three, two, six, five, seven;

long long m;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * a * rlt % mod;
		b >>= 1;
		a = 1ll * a * a % mod;
	}
	return rlt;
}

int pow_2(int n) {
	int rlt = 1ll * n * (n + 1) % mod;
	rlt = 1ll * rlt * (2 * n + 1) % mod;
	rlt = 1ll * rlt * six % mod;
	return rlt;
}

int pow_4(int n) {
	int rlt = 0;//n*(n+1)*(2*n+1)*(3*n^2+3*n-1)/30
	rlt = 1ll * n * (n + 1) % mod;
	rlt = 1ll * rlt * (2 * n + 1) % mod;
	rlt = 1ll * rlt * ((3 * (1ll * n * n % mod) + 3 * n + 1ll * mod - 1) % mod) % mod;
	rlt = 1ll * rlt * five % mod;
	rlt = 1ll * rlt * six % mod;
	return rlt;
}

int pow_6(int n) {
	int rlt = 0;//n*(n+1)*(2*n+1)*(3*n^4+6*n^3-3*n+1)/42
	rlt = 1ll * n * (n + 1) % mod;
	rlt = 1ll * rlt * (2 * n + 1) % mod;
	int m = 1ll * n * n % mod;
	rlt = 1ll * rlt * ((3ll * m * m % mod) + ((6ll * m % mod) * n % mod) - 3 * n + 1) % mod;
	rlt = 1ll * rlt * seven % mod;
	rlt = 1ll * rlt * six % mod;
	rlt = (rlt + mod) % mod;
	return rlt;
}

int sum(long long h, int j, int x) {
	int n = sqrt(h);
	if (j == 0) return (n * 2 + 1) % mod;
	if (j == 1) {
		int rlt = 0;
		int y = 1ll * x * x % mod;
		rlt = 1ll * y * n % mod;
		rlt = (rlt + pow_2(n)) % mod;
		rlt = (rlt * 2ll + y) % mod;
		return rlt;
	}
	if (j == 2) {
		int rlt = 0;
		int y = 1ll * x * x % mod;
		rlt = (1ll * y * y % mod) * n % mod;
		rlt = (rlt + 2ll * y * pow_2(n) % mod) % mod;
		rlt = (rlt + pow_4(n)) % mod;
		rlt = (rlt * 2 + 1ll * y * y) % mod;
		return rlt;
	}
	if (j == 3) {
		int rlt = 0;
		int y = 1ll * x * x % mod;//2
		int z = 1ll * y * y % mod;//3
		int w = 1ll * z * y % mod;//6
		rlt = 1ll * w * n % mod;
		rlt = (rlt + 3ll * z * pow_2(n)) % mod;
		rlt = (rlt + 3ll * y * pow_4(n)) % mod;
		rlt = (rlt + pow_6(n)) % mod;
		rlt = (rlt * 2ll + w) % mod;
		return rlt;
	}
}

int main() {
	//freopen("r.in", "r", stdin);
	three = expmod(3, mod - 2);
	two = expmod(2, mod - 2);
	five = expmod(5, mod - 2);
	seven = expmod(7, mod - 2);
	six = 1ll * three * two % mod;

	scanf("%I64d", &m);
	int s[5];
	memset(s, 0, sizeof s);
	for (int i = 0; ; i ++) {
		if (1ll * i * i > m) break;
		for (int j = 0; j <= 3; j ++) {
			if (i == 0) s[j] = (s[j] + sum(m - 1ll * i * i, j, i)) % mod;
			else s[j] = (s[j] + (2 * sum(m - 1ll * i * i, j, i)) % mod) % mod;
		}
	}

	int n = m % mod;

	long long ans = 0;
	ans = 2ll * s[3] % mod;
	ans = (ans + 1ll * s[2] * (-3ll * n - 6) % mod) % mod;
	ans = (ans + 1ll * s[1] * (3ll * n + 4) % mod) % mod;
	ans = (ans + (1ll * s[0] * (1ll * n * (n + 1) % mod) % mod) * (n + 2) % mod) % mod;
	ans = 1ll * ans * six % mod;
	ans = (mod + ans) % mod;
	printf("%I64d\n", ans);

	return 0;
}