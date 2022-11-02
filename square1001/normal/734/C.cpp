#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int m, p; long long n, x, s, a[200009], b[200009], c[200009], d[200009];
int main() {
	scanf("%lld %d %d", &n, &m, &p);
	scanf("%lld %lld", &x, &s);
	a[0] = x; b[0] = 0; c[0] = 0; d[0] = 0;
	for (int i = 1; i <= m; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	for (int i = 1; i <= p; i++) scanf("%lld", &c[i]);
	for (int i = 1; i <= p; i++) scanf("%lld", &d[i]);
	long long ret = n * x;
	for (int i = 0; i <= m; i++) {
		int ptr = lower_bound(d, d + p + 1, s - b[i] + 1) - d - 1;
		if (ptr >= 0) ret = min(ret, max(n - c[ptr], 0LL) * a[i]);
	}
	printf("%lld\n", ret);
	return 0;
}