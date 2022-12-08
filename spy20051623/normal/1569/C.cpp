#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int a[200005];

long long inv[200005];

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < 200005; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

long long fac[200005], ifac[200005];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 200005; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

long long A(int n, int m) {
	return fac[n] * ifac[n - m] % mod;
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n, greater<int>());
	if (a[0] - a[1] > 1) {
		printf("0\n");
		return;
	}
	if (a[0] == a[1]) {
		printf("%lld\n", fac[n]);
		return;
	}
	int cnt = 1;
	for (int i = 2; i < n; ++i) {
		if (a[i] == a[i - 1]) ++cnt;
		else break;
	}
	long long ans = fac[n];
	for (int i = cnt; i < n; ++i) {
		ans -= fac[n - 1 - cnt] * A(i, cnt) % mod;
		ans %= mod;
	}
	ans = (ans + mod) % mod;
	printf("%lld\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	invWork();
	facWork();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}