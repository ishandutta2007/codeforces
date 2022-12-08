#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a[3], m;
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &m);
	sort(a, a + 3);
	int mn = max(0, a[2] - a[0] - a[1] - 1);
	int mx = max(0, a[0] - 1) + max(0, a[1] - 1) + max(0, a[2] - 1);
	if (m >= mn && m <= mx) puts("YES");
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