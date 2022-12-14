#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		long long a[n], ans = 0;
		for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		for (int i = 1; i < n; ++i) {
			if (a[i] < a[i - 1]) ans += a[i - 1] - a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}