#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	scanf("%d%d", &y, &x);
	if (x < y) printf("%d\n", x + y);
	else if (x == y) printf("%d\n", x);
	else printf("%d\n", x - x % y / 2);
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