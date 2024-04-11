#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	scanf("%d%d", &x, &y);
	int ans = x + y;
	if (abs(x - y) > 1)
		ans += abs(x - y) - 1;
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