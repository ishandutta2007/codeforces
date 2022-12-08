#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 305, P = 1e9 + 7;
int n, a[N], sze[N], cnt;
int fac[N], inv[N], f[N][N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for(int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
}

int C(int x, int y) { return x >= y? fac[x] * inv[y] % P * inv[x - y] % P : 0; }

signed main() {
	n = get();
	init(n);
	for(int i = 1; i <= n; i++) {
		a[i] = get();
		for(int j = 2; j * j <= a[i]; j++) while(a[i] % (j * j) == 0) a[i] /= j * j;
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1, j; i <= n; i = j + 1) {
		j = i;
		while(a[j + 1] == a[j]) ++j;
		sze[++cnt] = j - i + 1;
	}
	f[1][sze[1] - 1] = fac[sze[1]];
	for(int i = 1, sum = sze[1]; i < cnt; i++, sum += sze[i]) 
		for(int k = 1; k <= sze[i + 1]; k++)
			for(int j = 0; j < sum; j++)
				for(int l = 0; l <= min(k, j); l++)
					(f[i + 1][j - l + sze[i + 1] - k] += f[i][j] * fac[sze[i + 1]] % P * C(sze[i + 1] - 1, k - 1) % P * C(j, l) % P * C(sum - j + 1, k - l) % P) %= P;
	printf("%lld\n", f[cnt][0]);
	return 0;
}