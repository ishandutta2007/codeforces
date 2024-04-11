#include <bits/stdc++.h>
using namespace std;

#define N 101

char a[N][N];
int n, m, vis[N] = {0};

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", a[i] + 1);
	}
	for (int j = 1; j <= m; j ++) {
		int ma = 0;
		for (int i = 1; i <= n; i ++) {
			ma = max(ma, (int)a[i][j]);
		}
		for (int i = 1; i <= n; i ++) if (a[i][j] == ma) vis[i] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) ans += vis[i];
	printf("%d\n", ans);
	return 0;
}