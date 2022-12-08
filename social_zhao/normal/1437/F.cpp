#include<stdio.h>
#include<algorithm>

const int N = 5005, P = 998244353;
int n, a[N], fac[N], inv[N], lim[N], f[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = 1ll * res * x % P;
		x = 1ll * x * x % P, y >>= 1;
	}
	return res;
}

int A(int x, int y) {
	return 1ll * fac[x] * inv[x - y] % P;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + 1 + n);
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % P;
	for(int i = 1, l = 0; i <= n; i++) {
		while(2 * a[l + 1] <= a[i]) ++l;
		lim[i] = l;
	}
	if(lim[n] != n - 1) return 0 * printf("0\n");
	f[0] = 1, lim[0] = -1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= lim[i]; j++)
			f[i] = (f[i] + 1ll * f[j] * A(n - lim[j] - 2, lim[i] - lim[j] - 1) % P) % P;
	printf("%d\n", f[n]);
	return 0;
}