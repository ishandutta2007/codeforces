#include <bits/stdc++.h>
using namespace std;

#define N 99

int n, k, a[N];
bool vis[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (vis[a[i]]) continue;
		vis[a[i]] = 1;
		cnt ++;
		ans ++;
		if (cnt == k + 1) {
			int rmh = -1, jj;
            for (int j = 1; j <= n; j ++) if (vis[j] && j != a[i]) {
                for (int k = i + 1; k <= n + 1; k ++) {
					if (a[k] == j || k == n + 1) {
                        if (rmh < k - i) rmh = k - i, jj = j;
						break;
					}
                }
            }
            cnt --;
            vis[jj] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}