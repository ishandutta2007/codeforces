#include <bits/stdc++.h>
using namespace std;

#define N 101010

const int INF = 1e9;

int b[N];

int a[N];
int le[N], ri[N];

int main() {
	//freopen("r.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1, x, y; i <= n; i ++) {
		scanf("%d %d", &x, &y);
		a[x] ++;
		a[y+1] --;
	}
	for (int i = 1; i <= m; i ++) a[i] += a[i-1];
	for (int i = 1; i <= m; i ++) b[i] = INF;
	int now = 0;
	for (int i = 1; i <= m; i ++) {
		int j = lower_bound(b + 1, b + m + 1, a[i] + 1) - b;
		b[j] = a[i];
		now = max(now, j);
		le[i] = now;
	}
	for (int i = 1; i <= m; i ++) b[i] = INF;
	now = 0;
	for (int i = m; i >= 1; i --) {
		int j = lower_bound(b + 1, b + m + 1, a[i] + 1) - b;
		b[j] = a[i];
		now = max(now, j);
		ri[i] = now;
	}
//	for (int i = 1; i <= m; i ++) printf("%d ", a[i]);puts("");
//	for (int i = 1; i <= m; i ++) printf("%d ", le[i]);puts("");
//	for (int i = 1; i <= m; i ++) printf("%d ", ri[i]);puts("");
	int ans = 0;
	for (int i = 1; i <= m; i ++) ans = max(ans, le[i] + ri[i]);
	printf("%d\n", ans - 1);

	return 0;
}