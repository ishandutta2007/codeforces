#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
int n, s, a[100009]; long long b[100009];
long long solve(int m) {
	for (int j = 0; j < n; j++) b[j] = a[j] + 1LL * (j + 1) * m;
	std::sort(b, b + n);
	long long res = 0;
	for (int j = 0; j < m; j++) res += b[j];
	return res;
}
int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int l = 0, r = n + 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (solve(m) <= s) l = m;
		else r = m;
	}
	printf("%d %d\n", l, solve(l));
	return 0;
}