#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, m, prv[N], nxt[N];
long long r, a[N], b[N];

bool bad(int x) {
	if (prv[x] >= 1 && b[prv[x]] + r >= a[x]) return 0;
	if (nxt[x] <= m && b[nxt[x]] - r <= a[x]) return 0;
	return 1;
}

bool ok() {
	for (int i = 1; i <= n; i ++) {
		if (bad(i)) return 0;
	}
	return 1;
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	for (int i = 1; i <= m; i ++) scanf("%I64d", &b[i]);
	sort(b + 1, b + m + 1);
	m = unique(b + 1, b + m + 1) - b - 1;
	for (int i = 1; i <= n; i ++) {
		prv[i] = lower_bound(b + 1, b + m + 1, a[i] + 1) - b - 1;
		nxt[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
	}
	long long st = -1, en = 2e9 + 1;
	while (en - st > 1) {
		r = (st + en) / 2;
		if (ok()) en = r;
		else st = r;
	}
	printf("%I64d\n", en);
	return 0;
}