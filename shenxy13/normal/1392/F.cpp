#include <cstdio>
#include <algorithm>
using namespace std;
inline void read(long long &x) {
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
}
int main() {
	long long n;
	read(n);
	long long h[n], sum = 0, l, u, m, rem;
	for (int i = 0; i < n; ++i) read(h[i]);
	for (int i = 0; i < n; ++i) sum += h[i];
	l = 0, u = 1000000000000;
	while (l != u) {
		m = (l + u + 1) / 2;
		if (n * (2 * m + n - 1) <= 2 * sum) l = m;
		else u = m - 1;
	}
	rem = sum - n * (2 * l + n - 1) / 2;
	for (int i = 0; i < n; ++i) h[i] = l + i;
	for (int i = 0; i < rem; ++i) ++h[i];
	for (int i = 0; i < n; ++i) printf("%lld ", h[i]);
	return 0;
}