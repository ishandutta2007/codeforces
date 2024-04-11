#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

int n, b[N], g[N], c[N << 1], ans[N << 1];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &b[i], &g[i]);
		b[i] --;
		g[i] --;
		c[g[i]] = b[i];
		c[b[i]] = g[i];
	}
	for (int i = 0; i < 2 * n; i += 2) {
		if (!ans[i]) {
			ans[i] = 1;
			ans[i ^ 1] = 2;
			int k = c[i ^ 1];
			while (!ans[k]) {
				ans[k] = 1;
				ans[k ^ 1] = 2;
				k = c[k ^ 1];
			}
		}
	}
	for (int i = 1; i <= n; i ++) printf("%d %d\n", ans[b[i]], ans[g[i]]);
}