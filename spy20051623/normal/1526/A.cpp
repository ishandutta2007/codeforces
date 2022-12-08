#include <bits/stdc++.h>

using namespace std;

int a[1005];
int b[1005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n + n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n + n);
	for (int i = 0; i < n; ++i) {
		b[i + i] = a[i];
		b[i + i + 1] = a[i + n];
	}
	for (int i = 0; i < n + n; ++i) {
		printf("%d ", b[i]);
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