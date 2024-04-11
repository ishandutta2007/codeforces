#include <bits/stdc++.h>
using namespace std;

const int K = 1e6;
const int mod = 1e9 + 7;

long long n, m;

int main() {
	scanf("%I64d %I64d", &n, &m);
	int ans = 0;
	for (int i = 1; i <= m && (n / i) > K; i ++) ans = (ans + (n % i)) % mod;
	long long nn = n % mod;
	for (int k = K, st, en; k >= 0; k --) {
		if (!k) en = m % mod;
		else en = min(m, n / k) % mod;
		st = (min(m + 1, (n + k + 1) / (k + 1))) % mod;
		ans = (ans + nn * (en - st + 1) - k * ((1ll * (en + st) * (en - st + 1) / 2) % mod)) % mod;
		ans = (ans + mod) % mod;
	}
	printf("%d\n", ans);

	return 0;
}