#include <bits/stdc++.h>
using namespace std;

int R, d, n, x, y, r;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &R, &d);
	scanf("%d", &n);
	int ans = 0;
	while (n --) {
		scanf("%d %d %d", &x, &y, &r);
		int dist = x * x + y * y;
		if (R - d + r <= R - r && (R - d + r) * (R - d + r) <= dist && dist <= (R - r) * (R - r)) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}