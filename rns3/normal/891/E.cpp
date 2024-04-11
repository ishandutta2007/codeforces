#include <bits/stdc++.h>

using namespace std;



const int mod = 1e9 + 7;



int expmod(int a, int b) {

	int rlt = 1;

	while (b) {

		if (b & 1) rlt = 1ll * rlt * a % mod;

		b >>= 1;

		a = 1ll * a * a % mod;

	}

	return rlt;

}



#define N 5050



int n, k, a[N];



int b[N];



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

	b[0] = 1;

	for (int i = 1; i <= n; i ++) {

		for (int j = n; j; j --) b[j] = (1ll * a[i] * b[j] - b[j-1]) % mod, b[j] = (b[j] + mod) % mod;

		b[0] = 1ll * a[i] * b[0] % mod;

	}

	int rn = expmod(n, mod - 2);



	int now = expmod(n, k);

	int ans = 0;

	for (int i = 0; i <= min(k, n); i ++) {

		ans = (ans + 1ll * now * b[i]) % mod;

		now = 1ll * now * (k - i) % mod;

		now = 1ll * now * rn % mod;

	}

	ans = 1ll * expmod(rn, k) * ans % mod;



	int mul = 1;

	for (int i = 1; i <= n; i ++) mul = 1ll * mul * a[i] % mod;

	ans = (mul - ans) % mod;

	ans = (ans + mod) % mod;

	printf("%d\n", ans);



	return 0;

}