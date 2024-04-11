#include <bits/stdc++.h>
using namespace std;
int a[300005];

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

long long inv(long long a) {
	return quickpow(a, mod - 2);
}

long long c(long long n, long long m) {
	long long res = 1;
	for (int i = 1; i <= m; ++i) {
		res = res * (n + 1 - i) % mod * inv(i) % mod;
	}
	return res;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, i;
	long long sum = 0;
	cin >> n;
	for (i = 0; i < 2 * n; ++i)
		cin >> a[i];
	sort(a, a + 2 * n);
	for (i = 0; i < n; ++i)
		sum += a[2 * n - 1 - i] - a[i];
	sum %= mod;
	sum = sum * c(2 * n, n) % mod;
	cout << sum << endl;
	return 0;
}