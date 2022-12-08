#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int minm = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i] < a[minm])
			minm = i;
	}
	b[minm] = a[minm];
	for (int i = minm + 1; i <= n; ++i) {
		b[i] = b[i - 1] + 1;
	}
	for (int i = minm - 1; i >= 1; --i) {
		b[i] = b[i + 1] + 1;
	}
	printf("%d\n", n - 1);
	for (int i = 1; i <= n; ++i) {
		if (i == minm)
			continue;
		printf("%d %d %d %d\n", i, minm, b[i], b[minm]);
	}
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