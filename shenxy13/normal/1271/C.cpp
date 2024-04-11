#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, sx, sy;
	scanf("%d %d %d", &n, &sx, &sy);
	int x[n], y[n];
	for (int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);
	sort(x, x + n);
	sort(y, y + n);
	int l = lower_bound(x, x + n, sx) - x, r = n - (upper_bound(x, x + n, sx) - x), u = lower_bound(y, y + n, sy) - y, d = n - (upper_bound(y, y + n, sy) - y);
	int ans = max(max(l, r), max(u, d));
	printf("%d\n", ans);
	if (ans == l) printf("%d %d", sx - 1, sy);
	else if (ans == r) printf("%d %d", sx + 1, sy);
	else if (ans == u) printf("%d %d", sx, sy - 1);
	else printf("%d %d", sx, sy + 1);
	return 0;
}