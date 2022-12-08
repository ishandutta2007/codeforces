#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], c[N], d[N << 1];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		++c[a[i]];
	}
	int maxm = 0, cnt = 0;
	for (int i = 1; i <= 100; ++i) maxm = max(maxm, c[i]);
	for (int i = 1; i <= 100; ++i) if (c[i] == maxm) ++cnt;
	if (cnt > 1) {
		printf("%d\n", n);
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= 100; ++i) {
		if (c[i] == maxm) continue;
		memset(d, -1, sizeof d);
		d[N] = 0;
		int cur = 0;
		bool ok = false;
		for (int j = 1; j <= n; ++j) {
			if (c[a[j]] == maxm) b[j] = b[j - 1] + 1;
			else if (a[j] == i) b[j] = b[j - 1] - 1;
			else b[j] = b[j - 1];
			if (b[j]) ok = true;
			if (d[b[j] + N] == -1) d[b[j] + N] = j;
			else if (ok) cur = max(cur, j - d[b[j] + N] - 1);
		}
		if (cur > 0) ans = max(ans, cur + 1);
	}
	printf("%d\n", ans);
	return 0;
}