#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long inv[400005];

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < 400005; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

long long fac[400005], ifac[400005];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 400005; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

long long C(int n, int m) {
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; ++i) {
		ans = (ans + C(a[i] + i, i + 1)) % mod;
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	invWork();
	facWork();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}