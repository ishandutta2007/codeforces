#include <cstdio>

typedef long long ll;

const int N = 200010;
const ll P = 1e9 + 7;
ll n, ans, a[N], fac[N], inv[N], facinv[N];

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

ll C(int x, int y) {
	if (x == y || y == 0) return 1;
	return fac[x] * facinv[x - y] % P * facinv[y] % P;
}

void init() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	facinv[1] = 1;
	for (int i = 2; i < N; i ++) {
		fac[i] = fac[i - 1] * i % P;
		inv[i] = (P - P / i) * inv[P % i] % P;
		facinv[i] = facinv[i - 1] * inv[i] % P;
	}
}

int main() {
	n = rd(), init();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	if (n == 1) return printf("%I64d\n", a[1]), 0;
	if (n == 2) return printf("%I64d\n", (a[1] + a[2]) % P), 0;
	ans = 0;
	if (n & 1) {
		for (int i = 1; i < n; i ++) {
			if (ans & 1) a[i] -= a[i + 1]; else a[i] += a[i + 1];
			ans ^= 1, a[i] = (a[i] + P) % P;
		}
		n --;
	}
	ans = 0;
	int op = (n % 4 == 0 ? -1 : 1);
	for (int i = 1; i <= n; i += 2) ans = (ans + C(n / 2 - 1, i / 2) * (a[i] + op * a[i + 1]) % P) % P;
	printf("%I64d\n", (ans + P) % P);
	return 0;
}