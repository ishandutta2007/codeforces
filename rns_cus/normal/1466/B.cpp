#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, x[N];
bool vis[2*N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &x[i]);
		for (int i = 1; i <= n; i ++) {
			if (vis[x[i]]) x[i] ++;
			vis[x[i]] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= 2 * n + 2; i ++) if (vis[i]) ans ++, vis[i] = 0;
		printf("%d\n", ans);
    }

    return 0;
}