#include <bits/stdc++.h>

using namespace std;

int a[400005];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + k, greater<int>());
	int ans = 0, s = n;
	for (int i = 0; i < k; ++i) {
		if (s > n - a[i]) ++ans, s -= n - a[i];
		else break;
	}
	printf("%d\n", ans);
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