#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

int a[300000], s[2], b[300000], n, m, a1, d;

int power(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % m) if (b & 1) c = 1ll * c * a % m;
	return c;
}

int main() {
	m = rd(), n = rd();
	for (int i = 1; i <= n; i ++) {
		a[i] = rd();
		s[0] = (1ll * s[0] + a[i]) % m;
		s[1] = (1ll * s[1] + 1ll * a[i] * a[i] % m) % m;
	}
	sort(a + 1, a + n + 1);
	//printf("%d\n", s[1]);
	if (n == 1) return printf("%d 0\n", a[1]), 0;
	for (int i = 2; i <= n; i ++) {
		int d = (a[i] - a[1] + m) % m;
		a1 = 1LL * (s[0] - 1LL * n * (n - 1) / 2 % m * d % m + m) % m * power(n, m - 2) % m;
		int sum = 1ll * n * a1 % m * a1 % m;
		sum = (sum + 1ll * n * (n - 1) % m * d % m * a1 % m) % m;
		sum = (sum + 1ll * n * (n - 1) * (2 * n - 1) / 6 % m * d % m * d % m) % m;
		//printf("%d %d %d %d\n", a1, d, sum, s[1]);
		if (sum == s[1]) {
			b[1] = a1;
			for (int j = 2; j <= n; j ++) b[j] = (b[j - 1] + d) % m;
			sort(b + 1, b + n + 1);
		//	for (int j = 1; j <= n; j ++) printf("%d ", b[j]);puts("");
			bool flag = 1;
			for (int j = 1; j <= n; j++) {
				if (a[j] != b[j]) { flag = 0; break; }
			}
			if (flag) return printf("%d %d\n", a1, d), 0;
		}
	}
	return puts("-1"), 0;
}