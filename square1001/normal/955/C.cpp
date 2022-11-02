#include <cmath>
#include <cstdio>
#pragma warning(disable : 4996)
using namespace std;
long long power(long long a, int b) {
	long long ret = 1;
	while (b) {
		if (b & 1) ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}
long long count(long long x, int d) {
	long long l = -1, r = (long long)pow(10.0, 18.2 / d) + 1;
	while (r - l > 1) {
		long long m = (l + r) >> 1;
		if (x >= power(m, d)) l = m;
		else r = m;
	}
	return r;
}
bool prime[66]; int mobius[66];
int main() {
	for (int i = 2; i <= 60; ++i) prime[i] = true;
	for (int i = 2; i <= 60; ++i) {
		if (!prime[i]) continue;
		for (int j = i * 2; j <= 60; j += i) prime[j] = false;
	}
	for (int i = 1; i <= 60; ++i) mobius[i] = 1;
	for (int i = 2; i <= 60; ++i) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= 60; j += i * i) mobius[j] = 0;
		for (int j = i; j <= 60; j += i) mobius[j] *= -1;
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		long long L, R;
		scanf("%lld%lld", &L, &R);
		bool one = (L == 1);
		if (L == 1) L = 2;
		long long ret = 0;
		for (int i = 2; i <= 60; ++i) {
			if (mobius[i] == 0) continue;
			long long ans = count(R, i) - count(L - 1, i);
			ret -= ans * mobius[i];
		}
		printf("%lld\n", ret + (one ? 1 : 0));
	}
	return 0;
}