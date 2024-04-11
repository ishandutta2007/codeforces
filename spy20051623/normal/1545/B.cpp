#include <bits/stdc++.h>

using namespace std;

char s[100005];

const int mod = 998244353;

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

long long c(long long n, long long m) {
	long long res = 1;
	for (int i = 0; i < m; ++i) {
		res = res * (n - i) % mod;
		res = res * inv(i + 1) % mod;
	}
	return res;
}

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int c1 = 0, p = 0, r = 0, b;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (r)--r, ++c1;
		} else {
			if (!r)++r;
			else --r, ++p;
		}
	}
	if (r)--r, ++c1;
	b = n - c1 - p - p;
	printf("%lld\n", c(p + b, p));
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