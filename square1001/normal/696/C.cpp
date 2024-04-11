#include <cstdio>
#pragma warning(disable : 4996)
const int mod = 1000000007;
int modpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int n; long long a[100009];
int main() {
	scanf("%d", &n);
	bool flag = false;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (!(a[i] & 1)) flag = true;
	}
	int z = 2;
	for (int i = 0; i < n; i++) {
		z = modpow(z, a[i] % (mod - 1));
	}
	int pz = 1LL * z * modpow(2, mod - 2) % mod;
	int p = 1LL * (!flag ? pz + mod - 1 : pz + 1) * modpow(3, mod - 2) % mod;
	z = 1LL * z * modpow(2, mod - 2) % mod;
	printf("%d/%d\n", p, z);
	return 0;
}