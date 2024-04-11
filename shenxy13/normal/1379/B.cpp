#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int h = 0; h < T; ++h) {
		long long l, r, m;
		scanf("%lld %lld %lld", &l, &r, &m);
		long long x = m, y = m;
		x += l - r, y += r - l;
		for (long long i = l; i <= r; ++i) {
			if ((x - 1) / i != y / i) {
				long long k = y / i * i;
				long long a = l, b = l;
				while (k + a - b != m) {
					if (k + a - b < m) ++a;
					else ++b;
				}
				printf("%lld %lld %lld\n", i, a, b);
				break;
			}
		}
	}
	return 0;
}