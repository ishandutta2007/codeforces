#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, d, ans = 0;
		scanf("%d %d", &n, &d);
		int a[n];
		for (int j = 0; j < n; ++j) scanf("%d", &a[j]);
		ans += a[0];
		for (int j = 1; j < n; ++j) {
			if (j * a[j] <= d) {
				d -= j * a[j];
				ans += a[j];
			} else {
				ans += d / j;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}