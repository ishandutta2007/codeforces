#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		int p;
		scanf("%1d", &p);
		if (p) ans += p + 1;
	}
	int p;
	scanf("%d", &p);
	ans += p;
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