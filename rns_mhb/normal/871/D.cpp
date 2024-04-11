#include <bits/stdc++.h>
using namespace std;

#define N 10001000

int runs, p[N>>3], phi[N], mu[N], f[N];

void ppm(int n) {
	phi[1] = 1, mu[1] = 1;
	for (int i = 2; i <= n; i ++) {
		if (!phi[i]) p[++runs] = i, phi[i] = i - 1, mu[i] = -1, f[runs] = 1;
		for (int j = 1; j <= runs && i * p[j] <= n; j ++) {
			int k = i * p[j];
			f[j] ++;
			phi[k] = phi[i] * (p[j] - 1);
			if (i % p[j] == 0) {
				phi[k] = phi[i] * p[j]; break;
			}
			mu[k] = -mu[i];
		}
	}
}

int n;
long long g[N];

long long calc(int n) {
	g[1] = 1;
	for (int i = 2; i <= n; i ++) g[i] = g[i-1] + 2 * phi[i];
	return g[n];
}

int main() {
	scanf("%d", &n);
	ppm(n);
	long long m = calc(n);
	m = (m - 1) / 2;
	long long ans = 1ll * n * (n - 1) / 2 - m;
	m -= n - 1;
	int cnt = 0;
	for (int i = 1; i <= runs; i ++) if (p[i] * 2 > n && p[i] <= n) cnt ++;
	m -= 1ll * cnt * (n - 2) - 1ll * cnt * (cnt - 1) / 2;
	ans += 2 * m;
	while (runs && p[runs] * 2 > n) runs --;
	if (runs) {
		long long sum1 = 0, sum2 = 0;
		for (int i = 1; i <= runs; i ++) sum1 += f[i], sum2 += 1ll * f[i] * f[i];
		long long tmp = (sum1 * sum1 - sum2) / 2;
		for (int i = 1; i <= runs; i ++) {
			for (int j = 1; j < i && 1ll * p[i] * p[j] <= n; j ++) tmp -= 1ll * f[i] * f[j];
		}
		ans += tmp;
	}
	printf("%I64d\n", ans);

	return 0;
}