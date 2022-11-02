#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, x, a[N][22], nxt[N][22], b[22];
bool vis[1<<22];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		vis[x] = 1;
		for (int j = 0; j < 20; j ++) {
			if (x & (1 << j)) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for (int i = n; i >= 1; i --) {
		for (int j = 0; j < 20; j ++) {
			nxt[i][j] = nxt[i+1][j];
			if (a[i][j]) nxt[i][j] = i;
		}
	}
	for (int i = 1; i <= n; i ++) {
		int cnt = 0;
        for (int j = 0; j < 20; j ++) if (nxt[i][j]) b[cnt++] = nxt[i][j];
		sort(b, b + cnt);
		cnt = unique(b, b + cnt) - b;

		int rlt = 0;
		for (int j = 0; j < cnt; j ++) {
			for (int k = 0; k < 20; k ++) if (nxt[i][k] && nxt[i][k] <= b[j]) rlt |= (1 << k);
			vis[rlt] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << 20); i ++) if (vis[i]) ans ++;
	printf("%d\n", ans);
	return 0;
}