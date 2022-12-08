#include <bits/stdc++.h>

using namespace std;

char s[100005];
int a[100005];

const int mod = 1e9 + 7;

long long quickpow(long long x, long long y) {
	long long res = 1;
	x %= mod;
	while (y) {
		if (y & 1) res = res * x % mod;
		y >>= 1;
		x = x * x % mod;
	}
	return res;
}

long long inv(long long n) {
	return quickpow(n, mod - 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
	reverse(a, a + n);
	long long ans = 0;
	const long long inv9 = inv(9);
	for (int i = 0; i < n; ++i) {
		ans = (ans + a[i] * (1ll * (n - i) * (n - i - 1) / 2 % mod * quickpow(10, i) % mod +
							 (i * quickpow(10, i) % mod - (quickpow(10, i) - 1) * inv9 % mod) * inv9)) % mod;
	}
	ans = (ans % mod + mod) % mod;
	printf("%lld\n", ans);
	return 0;
}