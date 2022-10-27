#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 1e9 + 7;
LL mpow(LL a, LL x){
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL fac[N], inv[N], mu[N];
int q, n, f;
LL c(LL x, LL y){
	return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
}
LL solve(LL d) {
	if(n/d-1 >= f-1)
		return c(n/d-1, f-1);
	return 0;
}
int main() {
	fac[0] = 1, inv[0] = 1;
	for (int i = 1; i < N; i ++) fac[i] = fac[i-1] * i % MOD;
	for (int i = 1; i < N; i ++) inv[i] = mpow(fac[i], MOD - 2); 
	mu[1] = 1;
	for (int i = 1; i < N; i ++) {
		for (int j = i + i; j < N; j += i) {
			mu[j] -= mu[i];
		}
	}
	scanf("%d", &q);
	while (q --) {
		scanf("%d%d", &n, &f);
		LL res = 0;
		for (int d = 1; d * d <= n; d ++) {
			if (n % d == 0) {
				res = (res + solve(d) * mu[d]) % MOD;
				if (n/d != 1 && n/d != d) res = (res + solve(n/d) * mu[n/d]) % MOD;
			}
		}		
		res = (res % MOD + MOD) % MOD;
		printf("%lld\n", res);
	}
}