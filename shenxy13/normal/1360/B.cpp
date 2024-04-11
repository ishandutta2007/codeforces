#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		int a[n], ans = 10000;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = 1; i < n; ++i) ans = min(ans, a[i] - a[i - 1]);
		printf("%d\n", ans);
	}
	return 0;
}