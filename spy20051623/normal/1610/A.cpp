#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x == 1 && y == 1) puts("0");
	else if (x == 1 || y == 1) puts("1");
	else puts("2");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}