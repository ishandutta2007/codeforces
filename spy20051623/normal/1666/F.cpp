#include <bits/stdc++.h>

using namespace std;
const int N = 5005;
const int mod = 998244353;
int a[N], b[N], s[N];
long long dp[N][N];

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

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		b[i] = s[i] = 0;
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++b[a[i]];
	}
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + b[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (b[i]) dp[1][i] = s[i - 1];
	}
	for (int i = 2; i <= n / 2; ++i) {
		long long sum = 0;
		for (int j = 1; j <= n; ++j) {
			if (b[j]) {
				dp[i][j] = (dp[i][j] + sum) % mod;
				if (s[j - 1] > i + i - 3) sum = (sum + b[j] * dp[i - 1][j] % mod * (s[j - 1] - (i + i - 3))) % mod;
			}
		}
	}
	long long ans = dp[n / 2][a[n]];
	for (int i = 1; i <= n; ++i) {
		ans = ans * ifac[b[i]] % mod;
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
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}