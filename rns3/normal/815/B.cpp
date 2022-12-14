#include <bits/stdc++.h>
using namespace std;
#define N 200005

const int mod = 1e9 + 7;
int ri[N] = {1}, a[N], c[N] = {1}, n, ans, m;
int b[N] = {1, -1};


int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 0; i < n; i ++) scanf("%d", a + i);
	ri[1] = 1;
	k = n % 4;
	m = n / 4 * 2 - (k == 0);
	for(i = 2; i <= m; i ++) {
		j = mod % i; k = mod / i;
		ri[i] = 1ll * k * (mod - ri[j]) % mod;
	}
	for(i = 1; i <= m; i ++) c[i] = 1ll * c[i - 1] * (m - i + 1) % mod * ri[i] % mod;
	k = n % 4;
	if(k == 1) for(i = 0; i < n; i += 2) ans = (ans + 1ll * c[i / 2] * a[i] % mod) % mod;
	else if(k == 2) {
		for(i = 0; i < n; i ++) ans = (ans + 1ll * c[i / 2] * a[i] % mod) % mod;
	}
	else if(k == 3) {
		ans = a[0];
		for(i = 1; i < n; i ++) {
			if(i % 2) ans = (ans + 2ll * c[i / 2] * a[i] % mod) % mod;
			else ans = (ans + 1ll * (c[i / 2] - c[i / 2 - 1] + mod) % mod * a[i]) % mod;
		}
	}
	else {
		for(i = 0; i < n; i ++) ans = (ans + 1ll * (mod + b[i % 2]) % mod * c[i / 2] % mod * a[i] % mod) % mod;
	}
	printf("%d", ans);
}