#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, m, a[N], q[N], ans;

int main() {
//	freopen("c.in", "r", stdin);
	int mn = 1e9;
	scanf("%d", &m);
	for (int i = 0; i < m; i ++) {
		scanf("%d", &q[i]);
		mn = min(mn, q[i]);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	sort(a, a + n);
	int buy = 0, free = 1;
	for (int i = n - 1; i >= 0; i --) {
		if (buy < mn) ans += a[i], buy ++;
		else {
			if (free) free --;
			else free = 1, buy = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}