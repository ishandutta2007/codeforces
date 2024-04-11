#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, p[N][N];
double f[N], g[N];
bool vis[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", p[j] + i);
	for (int i = 1; i < n; ++i) g[i] = f[i] = 1;
	for (;;) {
		int k = -1;
		double ans = 1e100;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && (k == -1 || f[j] / (1 - g[j]) < ans)) k = j, ans = f[j] / (1 - g[j]);
		if (k == 1) {
			printf("%.15lf\n", ans);
			break;
		}
		vis[k] = true;
		for (int j = 1; j <= n; ++j) {
			if (vis[j]) continue;
			f[j] += g[j] * p[k][j] * ans / 100;
			g[j] *= (1 - p[k][j] / 100.);
		}
	}
}