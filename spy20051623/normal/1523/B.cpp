#include <bits/stdc++.h>

using namespace std;

int a[10005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", n * 3);
	for (int i = 0; i < n; i += 2) {
		printf("1 %d %d\n", i + 1, i + 2);
		printf("2 %d %d\n", i + 1, i + 2);
		printf("1 %d %d\n", i + 1, i + 2);
		printf("1 %d %d\n", i + 1, i + 2);
		printf("2 %d %d\n", i + 1, i + 2);
		printf("1 %d %d\n", i + 1, i + 2);
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