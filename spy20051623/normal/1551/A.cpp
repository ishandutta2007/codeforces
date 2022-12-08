#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int x = n / 3, y = n - 2 * x;
	if (y - x >= 2)++x, y -= 2;
	printf("%d %d\n", y, x);
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