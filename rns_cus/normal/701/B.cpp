#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, dx, dy, vis[100100], flag[100100];

long long calc(int dx, int dy) {
	return 1ll * (n - dx) * (n - dy);
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &x, &y);
		if (!vis[x]) vis[x] = 1, dx ++;
		if (!flag[y]) flag[y] = 1, dy ++;
		printf("%I64d\n", calc(dx, dy));
    }
	return 0;
}