#include <bits/stdc++.h>
using namespace std;
#define N 505

int n, m, a[N], b[N], f[N], g[N], bf[N], ans[N];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) scanf("%d", &b[i]);
	a[0] = -1; f[0] = 0; g[0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i - 1; j >= 0; j --) if (a[i] > a[j] && f[j] + 1 >= f[i]) {
			for (int k = g[j] + 1; k <= m; k ++) if (a[i] == b[k]) {
				if (f[i] < f[j] + 1) f[i] = f[j] + 1, g[i] = k, bf[i] = j;
				else if (g[i] > k) g[i] = k, bf[i] = j;
			}
		}
	}
	int mx = 0, k = 0;
	for (int i = 1; i <= n; i ++) if (f[i] > mx) mx = f[i], k = i;
	printf("%d\n", mx);
	if (!mx) return 0;
	for (int i = mx; i; i --) ans[i] = a[k], k = bf[k];
	for (int i = 1; i < mx; i ++) printf("%d ", ans[i]);
	printf("%d\n", ans[mx]);
	return 0;
}