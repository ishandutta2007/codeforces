#include <bits/stdc++.h>

using namespace std;

int a[500];

void solve() {
	int n;
	scanf("%d", &n);
	int sum = 0, odd = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
		if (a[i] & 1) odd = i + 1;
	}
	for (int i = 2; i * i <= sum; ++i) {
		if (sum % i == 0) {
			printf("%d\n", n);
			for (int j = 1; j <= n; ++j) {
				printf("%d ", j);
			}
			puts("");
			return;
		}
	}
	printf("%d\n", n - 1);
	for (int i = 1; i <= n; ++i) {
		if (i != odd) printf("%d ", i);
	}
	puts("");
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