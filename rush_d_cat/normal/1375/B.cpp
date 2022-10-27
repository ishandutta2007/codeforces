#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 302;
int t, n, m, a[N][N], b[N][N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) b[i][j] = 3;
		for (int i = 2; i < n; i ++) for (int j = 2; j < m; j ++) b[i][j] = 4;
		b[1][1] = b[1][m] = b[n][1] = b[n][m] = 2;

		bool ok = 1;
		for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j++) {
			if (b[i][j] < a[i][j]) ok = 0;
		}
		if (ok == 0) {
			printf("NO\n");
		} else {
			printf("YES\n");
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) {
					printf("%d ", b[i][j]);
				}
				printf("\n");
			}
		}
	}
}