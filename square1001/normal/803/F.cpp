#include <cstdio>
#pragma warning(disable : 4996)
const int mod = 1000000007;
int n, x, c[100009], d[100009], r[100009], pw[100009]; bool sq[100009], prime[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x), c[x]++;
	pw[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		pw[i] = pw[i - 1] * 2;
		if (pw[i] >= mod) pw[i] -= mod;
	}
	for (int i = 2; i <= 100000; i++) prime[i] = true;
	for (int i = 2; i <= 100000; i++) {
		if (!prime[i]) continue; r[i]++;
		for (int j = i * 2; j <= 100000; j += i) prime[j] = false, r[j]++;
	}
	for (int i = 2; i * i <= 100000; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= 100000; j += i * i) sq[j] = true;
	}
	for (int i = 2; i <= 100000; i++) {
		if (sq[i]) continue;
		for (int j = i; j <= 100000; j += i) {
			d[i] += c[j];
			if (d[i] >= mod) d[i] -= mod;
		}
	}
	int ret = pw[n];
	for (int i = 2; i <= 100000; i++) {
		if (sq[i]) continue;
		if (r[i] & 1) {
			ret -= pw[d[i]] - 1;
			if (ret < 0) ret += mod;
		}
		else {
			ret += pw[d[i]] - 1;
			if (ret >= mod) ret -= mod;
		}
	}
	ret--;
	if (ret < 0) ret += mod;
	printf("%d\n", ret);
	return 0;
}