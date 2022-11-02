#include <cstdio>
const long long inf = 1LL << 62;
int n, a, x, y, vs1[400009], vs2[400009]; unsigned long long vp1[400009], vp2[400009];
unsigned long long hashing(long long z) {
	z ^= z >> 12;
	z ^= z << 25;
	z ^= z >> 27;
	return z * 0x2545F4914F6CDD1D;
}
int main() {
	scanf("%d %d %*d", &n, &a);
	for (int i = 0; i < 2 * n; ++i) vp1[i] = inf, vp2[i] = inf;
	for (int i = 0; i < n; ++i) {
		scanf("%*d %d %d", &x, &y);
		unsigned long long z1 = 1ULL * x * a - y;
		int h1 = hashing(z1) % (2 * n);
		for (int j = h1; ; j = (j + 1 == 2 * n ? 0 : j + 1)) {
			if (vp1[j] == inf || vp1[j] == z1) {
				vp1[j] = z1;
				++vs1[j];
				break;
			}
		}
		unsigned long long z2 = 2000000007ULL * x + y;
		int h2 = hashing(z2) % (2 * n);
		for (int j = h2; ; j = (j + 1 == 2 * n ? 0 : j + 1)) {
			if (vp2[j] == inf || vp2[j] == z2) {
				vp2[j] = z2;
				++vs2[j];
				break;
			}
		}
	}
	long long ret = 0;
	for (int i = 0; i < 2 * n; ++i) {
		ret += 1LL * vs1[i] * (vs1[i] - 1);
		ret -= 1LL * vs2[i] * (vs2[i] - 1);
	}
	printf("%lld\n", ret);
	return 0;
}