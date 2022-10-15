#include <cstdio>
#define Maxn 100005
#define Max(x, y) ((x) > (y) ? (x) : (y)) 

int n, m, ans, a[Maxn], pre[Maxn];

int main() {
	scanf("%d%d", &n, &m);
	a[0] = 0;
	a[n + 1] = m;
	a[n + 2] = m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n + 1; i++) {
		if (i & 1) {
			pre[i] = pre[i - 1] + (a[i] - a[i - 1]);
		} else {
			pre[i] = pre[i - 1];
		}
	}
	ans = pre[n + 1];
	for (int i = 0; i <= n + 1; i++) {
		if ((i > 0 && a[i - 1] < a[i] - 1) || (i <= n && a[i + 1] > a[i] + 1)) {
			ans = Max(ans, pre[i] + (a[n + 1] - a[i]) - (pre[n + 1] - pre[i]) - 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF1000B Light It Up.