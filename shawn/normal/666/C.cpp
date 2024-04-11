#include <bits/stdc++.h>

using namespace std;

int read() {
	char c = getchar(); int x = 0;
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void write(int x) {
	if (x < 0) {
		write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int m, n, ans[500][maxn], l, tot;
int id[maxn], fac[maxn], fac_inv[maxn], p25[maxn], p26[maxn], i26[maxn];
char s[maxn];

int power(int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = (1ll * c * a) % mod;
		a = (1ll * a * a) % mod;
		b >>= 1;
	}
	return c;
}

void prep() {
	int N = 1e5;
	fac[0] = fac_inv[0] = p25[0] = p26[0] = i26[0] = 1;
	for (int i = 1; i <= N; i ++) fac[i] = (1ll * fac[i - 1] * i) % mod;
	fac_inv[N] = power(fac[N], mod - 2);
	for (int i = N - 1; i > 0; i --) fac_inv[i] = (1ll * fac_inv[i + 1] * (i + 1)) % mod;
	for (int i = 1; i <= N; i ++) p25[i] = 1ll * p25[i - 1] * 25 % mod;
	int ii26 = power(26, mod - 2);
	for (int i = 1; i <= N; i ++) i26[i] = 1ll * i26[i - 1] * ii26 % mod;
	for (int i = 1; i <= N; i ++) p26[i] = 1ll * p26[i - 1] * 26 % mod;
}

int C(int x, int y) {
	return 1ll * fac[x] * fac_inv[y] % mod * fac_inv[x - y] % mod;
}

#define f ans[now]
void calc(int now) {
	int N = 1e5;
	for (int k = l; k <= N; k ++) {
		f[k] = (f[k - 1] + 1ll * C(k - 1, l - 1) * p25[k - l] % mod * i26[k]) % mod;
	}
}

void init() {
	m = read();
	scanf("%s", s);
	l = strlen(s);
	id[l] = ++tot;
	calc(tot);
}

void Main() {
	while (m--) {
		int op = read();
		if (op & 1) {
			scanf("%s", s);
			l = strlen(s);
			if (!id[l]) id[l] = ++tot, calc(tot);
		}
		else {
			n = read();
			if (n < l) puts("0");
			else write(1ll * ans[id[l]][n] * p26[n] % mod), putchar(10);
		}
	}
}

int main() {
	prep();
	init();
	Main();
	return 0;	
}