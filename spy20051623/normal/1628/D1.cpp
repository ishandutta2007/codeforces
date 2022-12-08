#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

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

const long long inv2 = inv(2);

long long p[2005][2005];

void solve() {
	long long n, m, k;
	cin >> n >> m >> k;
	cout << p[n][m] * k % mod << '\n';
}

void init() {
	for (int i = 1; i <= 2000; ++i) {
		for (int j = 1; j < i; ++j) {
			p[i][j] = (p[i - 1][j - 1] + p[i - 1][j]) * inv2 % mod;
		}
		p[i][i] = i;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}