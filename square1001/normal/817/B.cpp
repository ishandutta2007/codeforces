#include <cstdio>
#include <algorithm>
int n, a[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	std::sort(a, a + n);
	if (a[0] == a[1] && a[1] == a[2]) {
		int c = 0;
		for (int i = 0; i < n; i++) c += (a[i] == a[0] ? 1 : 0);
		printf("%lld\n", 1LL * c * (c - 1) * (c - 2) / 6);
	}
	else if (a[1] == a[2]) {
		int c = 0;
		for (int i = 0; i < n; i++) c += (a[i] == a[1] ? 1 : 0);
		printf("%lld\n", 1LL * c * (c - 1) / 2);
	}
	else {
		int c = 0;
		for (int i = 0; i < n; i++) c += (a[i] == a[2] ? 1 : 0);
		printf("%d\n", c);
	}
	return 0;
}