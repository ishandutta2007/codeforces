#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, k, a[N], ans;
bool vis[N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		if (a[i] % k) {
			ans ++, vis[i] = 1; continue;
		}
		int j = lower_bound(a + 1, a + n + 1, a[i] / k) - a;
		if (a[j] != a[i] / k) {
			ans ++, vis[i] = 1; continue;
		}
        if (!vis[j]) {
			ans ++, vis[i] = 1; continue;
        }
	}
	printf("%d\n", ans);
	return 0;
}