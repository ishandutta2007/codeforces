#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	if ((n - 1) / 2 < k) {
		printf("-1\n");
		return;
	}
	int a[200];
	memset(a, 0, sizeof a);
	int i, j;
	for (i = n, j = 1; j <= k; --i, ++j) {
		a[j * 2] = i;
	}
	for (j = 1; j <= n; ++j) {
		if (!a[j]) {
			a[j] = i;
			--i;
		}
	}
	for (i = 1; i <= n; ++i)
		printf("%d ", a[i]);
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