#include<bits/stdc++.h>
using namespace std;

#define N 300030
int n, a[N];

#define M 4000
int runs, p[M], phi[M], mu[M];
void ppm() {
	phi[1] = 1, mu[1] = 1;
	for (int i = 2; i < M; i ++) {
		if (!phi[i]) p[++runs] = i, phi[i] = i - 1, mu[i] = -1;
		for (int j = 1; j <= runs && i * p[j] < M; j ++) {
			int k = i * p[j];
			phi[k] = phi[i] * (p[j] - 1);
			if (i % p[j] == 0) {
				phi[k] = phi[i] * p[j]; break;
			}
			mu[k] = -mu[i];
		}
	}
}

int cnt[M*M];

int main() {
	ppm();
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int d = a[1];
	for (int i = 2; i <= n; i ++) d = __gcd(d, a[i]);
	for (int i = 1; i <= n; i ++) a[i] /= d;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; p[j] * p[j] <= a[i]; j ++) if (a[i] % p[j] == 0) {
			cnt[p[j]] ++;
			while (a[i] % p[j] == 0) a[i] /= p[j];
		}
		if (a[i] > 1) cnt[a[i]] ++;
	}
	int ans = *max_element(cnt, cnt + M * M);
	if (ans == 0) puts("-1");
	else printf("%d\n", n - ans);
	return 0;
}