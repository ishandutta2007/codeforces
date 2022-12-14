#include <bits/stdc++.h>
using namespace std;
#define M 60
int a[M][M], ans[M], cnt, n, vis[M];

int main() {
//	freopen("B.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	}
	while (cnt < n) {
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			int mx = 0, mn = n + 1;
			for (int j = 0; j < n; j++) {
				if (a[i][j]) {
					if (mx < a[i][j]) mx = a[i][j];
					if (mn > a[i][j]) mn = a[i][j];
				}
			}
			if (mx == 0) {cnt++; ans[i] = n; break;}
			if (mx == mn) {
				ans[i] = mx; vis[i] = 1;
				for (int j = 0; j < n; j++) a[i][j] = 0;
				for (int j = 0; j < n; j++) a[j][i] = 0;
				cnt++;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
}