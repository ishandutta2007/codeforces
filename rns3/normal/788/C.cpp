#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

#define N 1010

int a[N*N], b[N*N];

int m, n, x[N*N], y[N], k;

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &k, &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	int nn = 0;
	for (int i = 1; i <= n; i ++) if (i == 1 || x[i] > x[i-1]) x[++nn] = x[i];
	n = nn;
	for (int i = 1; i <= n; i ++) {
		x[i] -= k;
		if (!x[i]) {
			puts("1");
			return 0;
		}
	}
	if (x[1] > 0 || x[n] < 0) {
		puts("-1");
		return 0;
	}
	m = 0;
	nn = 0;
	for (int i = 1; i <= n; i ++) {
		if (x[i] > 0) x[++nn] = x[i];
		else y[++m] = -x[i];
	}
	n = nn;
	sort(x + 1, x + n + 1);
	sort(y + 1, y + m + 1);
	a[0] = 0, b[0] = 0;
	int ans = INF;
	int to = min(N * N - 1, (x[1] + y[1]) * max(x[n], y[m]));
	for (int t = 1; t <= to; t ++) {
		a[t] = INF;
		for (int i = 1, tt; i <= n; i ++) {
			tt = t - x[i];
			if (tt < 0) break;
			a[t] = min(a[t], a[tt] + 1);
		}
		b[t] = INF;
		for (int i = 1, tt; i <= m; i ++) {
			tt = t - y[i];
			if (tt < 0) break;
			b[t] = min(b[t], b[tt] + 1);
		}
		if (a[t] + b[t] < ans) ans = a[t] + b[t];
	}
	printf("%d\n", ans);

	return 0;
}