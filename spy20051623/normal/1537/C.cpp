#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (n == 2) {
		printf("%d %d \n", a[0], a[1]);
		return;
	}
	int minm = 0x3f3f3f3f;
	int p = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] - a[i] < minm) {
			minm = a[i + 1] - a[i];
			p = i;
		}
	}
	for (int i = p + 1; i < n; ++i) {
		printf("%d ", a[i]);
	}
	for (int i = 0; i <= p; ++i) {
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