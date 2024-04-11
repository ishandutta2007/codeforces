#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, p;
	scanf("%d", &n);
	bool ans = true;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p);
		bool ok = false;
		for (int j = 2; j <= i + 1; ++j) {
			if (p % j != 0) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			ans = false;
		}
	}
	if (ans) puts("YES");
	else puts("NO");
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