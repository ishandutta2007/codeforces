#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, l, r, s, k;
	scanf("%d%d%d%d", &n, &l, &r, &s);
	k = r - l + 1;
	if (k * (k + 1) / 2 > s) {
		printf("-1\n");
		return;
	}
	if (k * (n + n - k + 1) / 2 < s) {
		printf("-1\n");
		return;
	}
	int a[505];
	for (int i = l; i <= r; ++i) {
		a[i] = i - l + 1;
	}
	s -= k * (k + 1) / 2;
	int tmp = n - a[r];
	for (int i = r; i >= l; --i) {
		if (s > tmp) {
			a[i] += tmp;
			s -= tmp;
		} else {
			a[i] += s;
			s = 0;
			break;
		}
	}
	int h[505] = {0};
	for (int i = l; i <= r; ++i) {
		h[a[i]] = 1;
	}
	int p = 1;
	for (int i = 1; i <= n; ++i) {
		if (i >= l && i <= r)
			continue;
		while (h[p])
			++p;
		a[i] = p;
		h[p] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}