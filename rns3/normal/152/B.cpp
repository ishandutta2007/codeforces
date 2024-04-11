#include <bits/stdc++.h>
using namespace std;

#define N 10010

int xx, yy, x, y, n, m, k;

int main() {
	scanf("%d %d\n%d %d\n%d", &n, &m, &x, &y, &k);
	int step, x1, y1;
	long long ans = 0;
	for (int i = 1; i <= k; i ++) {
		scanf("%d %d", &xx, &yy);
		if (xx > 0) {
			if (yy > 0) {
				step = max(0, min((n - x) / xx, (m - y) / yy));
			}
			else {
				if (!yy) step = max(0, (n - x) / xx);
				else step = max(0, min((n - x) / xx, (y - 1) / (-yy)));
			}
		}
		else {
			if (yy > 0) {
				if (!xx) step = max(0, (m - y) / yy);
				else step = max(0, min((x - 1) / (-xx), (m - y) / yy));
			}
			else {
				if (!xx) step = max(0, (y - 1) / (-yy));
				else if (!yy) step = max(0, (x - 1) / (-xx));
				else step = max(0, min((x - 1) / (-xx), (y - 1) / (-yy)));
			}
		}
		ans += 1ll * step;
		x += xx * step;
		y += yy * step;
	}
	printf("%I64d\n", ans);
	return 0;
}