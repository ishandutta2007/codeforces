#include <cstdio>
#include <algorithm>
using namespace std;
int logtwo(int x) {
	int ans = 0;
	while (x != 0) ++ans, x >>= 1;
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int a[n], mn = -1000000000, ans = 0;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) {
			if (a[i] < mn) ans = max(ans, logtwo(mn - a[i]));
			else mn = a[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}