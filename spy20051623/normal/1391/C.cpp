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

long long getF(int x) {
	long long s = 1;
	for (int i = 1; i <= x; ++i) {
		s = s * i % mod;
	}
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << ((getF(n) - quickpow(2, n - 1)) % mod + mod) % mod << '\n';
	return 0;
}