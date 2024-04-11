#include <bits/stdc++.h>
using namespace std;

#define N 20
#define M 111

int n, m, f[N], g[N], st[N], en[N];
char s[N][M];
bool vis[M];

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = n; i >= 1; i --) gets(s[i]);
	bool tag = 0;
	while (!tag) {
		for (int j = 1; j <= m && !tag; j ++) if(s[n][j] == '1') tag = 1;
		if (!tag) n --;
		if (!n) {
			puts("0");
			return 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		st[i] = m, en[i] = 0;
		for (int j = 1; j <= m; j ++) if (s[i][j] == '1') st[i] = min(st[i], j), en[i] = max(en[i], j);
		if (en[i]) vis[i] = 1;
		else vis[i] = 0;
	}
	if (n == 1) {
		printf("%d\n", en[1]);
		return 0;
	}
	f[1] = 0;
	g[1] = m + 1;
	for (int i = 2; i <= n; i ++) {
        if (vis[i-1]) {
			f[i] = min(f[i-1] + en[i-1] * 2 + 1, g[i-1] + m + 2);
			g[i] = min(f[i-1] + m + 2, g[i-1] + (m + 1 - st[i-1]) * 2 + 1);
        }
        else {
            f[i] = min(f[i-1] + 1, g[i-1] + m + 2);
			g[i] = min(g[i-1] + 1, f[i-1] + m + 2);
        }
	}
	int ans = min(f[n] + en[n], g[n] + (m + 1 - st[n]));
	printf("%d\n", ans);
	return 0;
}