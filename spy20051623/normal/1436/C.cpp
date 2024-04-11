#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long inv[10000];

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < 10000; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

long long fac[10000], ifac[10000];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 10000; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

long long C(int n, int m) {
	return n < m ? 0 : fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
//	freopen("in.txt", "r", stdin);
	invWork(), facWork();
	int n, x, p;
	scanf("%d%d%d", &n, &x, &p);
	int l = 0, r = n, a = 0, b = 0;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (p > mid) ++a, l = mid + 1;
		else if (p < mid) ++b, r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", C(x - 1, a) * C(n - x, b) % mod * fac[a] % mod * fac[b] % mod * fac[n - a - b - 1] % mod);
	return 0;
}