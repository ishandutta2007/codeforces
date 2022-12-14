#include <bits/stdc++.h>
using namespace std;

#define N 101

int n, a[N];
bool vis[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort (a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i ++) if (!vis[i]) {
		ans ++;
		int now = 1;
		vis[i] = 1;
        for (int j = i + 1; j <= n; j ++) if (!vis[j]) {
            if (a[j] >= now) {
				vis[j] = 1;
				now ++;
            }
        }
	}
	printf("%d\n", ans);

	return 0;
}