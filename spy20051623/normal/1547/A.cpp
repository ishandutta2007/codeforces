#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x1, y1, x2, y2, x3, y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	int add = 0;
	if (x1 == x2 && x1 == x3 && y3 > min(y1, y2) && y3 < max(y1, y2))add = 2;
	if (y1 == y2 && y1 == y3 && x3 > min(x1, x2) && x3 < max(x1, x2))add = 2;
	printf("%d\n", abs(x1 - x2) + abs(y1 - y2) + add);
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