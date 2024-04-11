#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define M 100100

int n, x, f[M], last[M];
int runs, p[N], vis[N], cnt, a[N], b[N];

void get_prime() {
	for (int i = 2; i < N; i ++) {
		if (vis[i]) continue;
		p[++runs] = i;
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

void bunhae(int m) {
	cnt = 0;
	for (int i = 1; i <= runs && p[i] * p[i] <= m; i ++) {
		if (m % p[i]) continue;
        a[++cnt] = p[i], b[cnt] = 0;
        while (m % a[cnt] == 0) m /= a[cnt], b[cnt] ++;
	}
	if (m > 1) a[++cnt] = m, b[cnt] = 1;
}

int main() {
//	freopen("d.in", "r", stdin);
	get_prime();
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		if (x == 1) continue;
		bunhae(x);
		for (int j = 1; j <= cnt; j ++) {
			f[i] = max(f[i], f[last[a[j]]] + 1);
			last[a[j]] = i;
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; i ++) ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}