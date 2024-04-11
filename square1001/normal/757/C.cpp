#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
typedef unsigned long long ull;
int n, m, c, x; ull p[1000009];
int main() {
	scanf("%d %d", &n, &m);
	ull t = 10101010101010101;
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		t = t ^ (t << 13);
		t = t ^ (t >> 7);
		t = t ^ (t << 17);
		for (int j = 0; j < c; j++) {
			scanf("%d", &x);
			p[--x] += t;
		}
	}
	std::sort(p, p + m);
	int ret = 1, c = 1;
	for (int i = 0; i < m; i++) {
		if (i >= 1 && p[i - 1] != p[i]) c = 1;
		ret = 1LL * ret * c++ % 1000000007;
	}
	printf("%d\n", ret);
	return 0;
}