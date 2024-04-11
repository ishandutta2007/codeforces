#include <bits/stdc++.h>
using namespace std;

#define N 1010

const int mod = 1e9 + 7;

int f[N];
char s[N];

int a[N], b[N];

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

void prep() {
	a[0] = a[1] = 1;
	for (int i = 2; i < N; i ++) a[i] = 1ll * a[i-1] * i % mod;
	for (int i = 0; i < N; i ++) b[i] = expmod(a[i], mod - 2);
	f[1] = 0;
	for (int i = 2; i < N; i ++) {
		int h = 0;
		for (int j = 1; j < N; j <<= 1) if (j & i) h ++;
		f[i] = f[h] + 1;
	}
}

int comb(int u, int v) {
	if (v < 0 || u < v) return 0;
	int rlt = a[u];
	rlt = 1ll * rlt * b[v] % mod;
	rlt = 1ll * rlt * b[u-v] % mod;
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	prep();
	gets(s);
	int k;
	scanf("%d", &k);
	if (k == 0) {
		puts("1");
		return 0;
	}
	int n = strlen(s);
	if (k == 1) {
		printf("%d\n", n - 1);
		return 0;
	}
	int ans = 0;
	for (int c = 1; c < N; c ++) if (f[c] == k - 1) {
		int to = c;
		for (int i = 0; i < n; i ++) {
			if (s[i] == '1') {
				ans = (ans + comb(n - i - 1, to)) % mod;
				to --;
				if (to < 0) break;
			}
		}
	}
	int gas = 0;
	for (int i = 0; i < n; i ++) if (s[i] == '1') gas ++;
	if (f[gas] == k - 1) ans ++;
	ans %= mod;
	printf("%d\n", ans);

	return 0;
}