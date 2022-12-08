#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005];

void solve() {
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i) {
		if (i + x > n && i - x < 1 && a[i] != b[i]) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
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