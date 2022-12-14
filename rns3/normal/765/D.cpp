#include <bits/stdc++.h>
using namespace std;

#define N 101010

int n;
int f[N], g[N], h[N];

bool vis[N];

int main() {
	scanf("%d", &n);
	int m = 0;
	for (int i = 1; i <= n; i ++) scanf("%d", &f[i]), vis[f[i]] = 1;
	for (int i = 1; i <= n; i ++) {
		if (f[f[i]] != f[i]) {
			puts("-1");
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i ++) if (vis[i]) g[i] = ++cnt, h[cnt] = i;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i ++) printf("%d ", g[f[i]]);puts("");
	for (int i = 1; i <= cnt; i ++) printf("%d ", h[i]);puts("");
	return 0;
}