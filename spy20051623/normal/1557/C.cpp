#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

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

void solve() {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	int p = n & 1;
	long long x = quickpow(2, n - 1);
	long long ans = 1;
	for (int i = 1; i <= k; ++i) {
		if (p) ans = (1 + x) * ans % mod;
		else ans = (quickpow(2, (i - 1) * n) + (x + mod - 1) % mod * ans) % mod;
	}
	printf("%lld\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}