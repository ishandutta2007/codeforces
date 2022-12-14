#include <bits/stdc++.h>
using namespace std;
#define M 10000010
const int MOD = 1e9+7;

int minp[M], mu[M], p[M], cnt, P[M], sz[M];

void init() {
	P[0] = 1; P[1] = 2;
	for (int i = 2; i < M; i++) {
		P[i] = P[i-1] * 2 % MOD;
		if (!minp[i]) mu[i] = 1, p[cnt++] = i, minp[i] = i;
		else {
			if (minp[i/minp[i]] == minp[i]) mu[i] = 0;
			else mu[i] = -mu[i/minp[i]];
		}
		for (int j = 0; j < cnt && 1LL * p[j] * i < M; j++) {
			minp[i*p[j]] = p[j]; if (i % p[j] == 0) break;
		}
	}
}
int a[1010], n;
int main() {
//	freopen("E.in", "r", stdin);
	int x;
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		int m = 0;
		while (x > 1) {
			int t = minp[x]; a[m++] = minp[x]; while (x % t == 0) x /= t;
		}
		for (int j = 0; j < (1 << m); j++) {
			int t = 1;
			for (int k = 0; k < m; k++) if (j & (1 << k)) t *= a[k];
			sz[t]++;
		}
	}
	int ans = 0;
	for (int i = 2; i <= 10000000; i++) {
		int tmp = 1LL * (P[sz[i]] - 1) * (n - sz[i]) * mu[i] % MOD;
		ans += tmp; ans %= MOD; if (ans < 0) ans += MOD;
	}
	printf("%d\n", ans);
}