#include <bits/stdc++.h>
using namespace std;
#define N 111

int n, k, p[N], q[N], s[N], f[N], g[N];

int run(int h[]) {
	for (int i = 1; i <= n; i ++) p[i] = i;
	for (int i = 0; i <= k; i ++) {
		bool same = 1;
		for (int j = 1; j <= n; j ++) if (p[j] != s[j]) same = 0;
		if (same) return i;
		for (int j = 1; j <= n; j ++) q[j] = p[h[j]];
		for (int j = 1; j <= n; j ++) p[j] = q[j];
	}
	return k + 1;
}

bool ok(int x, int y) {
	if (!x || !y) return 0;
	if (x == 1 && y == 1) return k == 1;
	return x <= k && (x - k) % 2 == 0 || y <= k && (y - k) % 2 == 0;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &f[i]), g[f[i]] = i;
	for (int i = 1; i <= n; i ++) scanf("%d", &s[i]);
	int x = run(f), y = run(g);
	if (ok(x, y)) puts("YES");
	else puts("NO");
	return 0;
}