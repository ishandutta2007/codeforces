#include <bits/stdc++.h>

using namespace std;

int a[10005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	if (a[1] == 1) {
		printf("%d", n + 1);
		for (int i = 1; i <= n; ++i) {
			printf(" %d", i);
		}
		printf("\n");
		return;
	}
	if (a[n] == 0) {
		for (int i = 1; i <= n; ++i) {
			printf("%d ", i);
		}
		printf("%d", n + 1);
		printf("\n");
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] == 0 && a[i + 1] == 1) {
			for (int j = 1; j <= i; ++j) {
				printf("%d ", j);
			}
			printf("%d", n + 1);
			for (int j = i + 1; j <= n; ++j) {
				printf(" %d", j);
			}
			printf("\n");
			return;
		}
	}
	printf("-1\n");
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