#include <bits/stdc++.h>

using namespace std;

int a[1000];

void solve() {
	int n;
	scanf("%d", &n);
	int ans = (1LL << 31) - 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		ans &= a[i];
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