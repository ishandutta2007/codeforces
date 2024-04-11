#include <bits/stdc++.h>
using namespace std;
int a[200005];
int mod = 1000000007;
long long ppp[200005];

long long quickpow(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

long long inv(long long a) {
	return quickpow(a, mod - 2);
}

long long c(long long n, long long m) {
	long long res = 1;
	if (n < m)
		return 0;
	for (int i = 1; i <= m; ++i) {
		res = res * (n + 1 - i) % mod;
		res = res * ppp[i] % mod;
	}
	return res;
}

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, m, k, i, j, res;
	for (i = 0; i < 200005; ++i)
		ppp[i] = inv(i);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a + n);
		res = 0;
		for (i = 0; i < n; ++i) {
			j = upper_bound(a, a + n, a[i] + k) - 1 - a - i;
			res = (res + c(j, m - 1)) % mod;
		}
		cout << res << endl;
	}
	return 0;
}