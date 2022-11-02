#include <bits/stdc++.h>
using namespace std;

int n, k, x, cnt, a[200200], b[200200];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		if (x < 0) a[++cnt] = i;
	}
	if (cnt > k) {
		puts("-1"); return 0;
	}
	if (!cnt) {
		puts("0"); return 0;
	}
	int ans = 2 * cnt;
	int runs = 0;
	for (int i = 1; i < cnt; i ++) b[runs++] = a[i+1] - a[i] - 1;
	sort(b, b + runs);
	int wd = cnt;
	for (int i = 0; i < runs; i ++) {
		if (wd + b[i] <= k) ans -= 2, wd += b[i];
		else break;
	}
	if (cnt + n - a[cnt] <= k) {
		int rlt = 2 * cnt - 1;
		wd = cnt + n - a[cnt];
		for (int i = 0; i < runs; i ++) {
			if (wd + b[i] <= k) rlt -= 2, wd += b[i];
			else break;
		}
		ans = min(ans, rlt);
	}
	printf("%d\n", ans);
	return 0;
}