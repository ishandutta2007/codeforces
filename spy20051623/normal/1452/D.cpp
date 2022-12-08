#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long inv(long long n) {
	return quickpow(n, mod - 2);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	long long sum[2] = {1, 1};
	long long ans = 1;
	for (int i = 3; i <= n; ++i) {
		ans = sum[i % 2 ^ 1] + i % 2;
		sum[i % 2] += ans;
		sum[i % 2] %= mod;
	}
	printf("%lld\n", (long long) (ans * inv(quickpow(2, n)) % mod));
	return 0;
}