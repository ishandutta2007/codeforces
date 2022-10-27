#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 10;
typedef long long LL;
const LL MOD = 998244353;
LL inv[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x >> 1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}

int n, a[N];
LL f[N], suf[N];
LL sum = 0;

int main() {
	for (int i = 0; i < N; i ++) inv[i] = mpow(i, MOD - 2);

	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	f[sum] = 0;
	for (int i = 0; i < sum; i ++) {
		LL p1 = (i * inv[sum] % MOD); 
		LL p2 = ((sum - i) * inv[sum] % MOD) * inv[n - 1] % MOD;
		LL p3 = ((sum - i) * inv[sum] % MOD) * (n - 2) % MOD * inv[n - 1] % MOD;
		f[i] = (p1 * (1 + (i>=1?f[i-1]:0) ) + p2 + p3) % MOD * mpow(((1 - p1 - p3) % MOD + MOD) % MOD, MOD - 2) % MOD;
		// printf("# %lld\n",f[i]);
	}

	suf[sum] = 0;
	for (int i = sum - 1; i >= 0; i --) suf[i] = (suf[i+1] + f[i]) % MOD; 

	LL res = 0;
	for (int i = 1; i <= n; i ++) {
		res = (res + suf[a[i]]) % MOD;
	}
	res = ((res - suf[0] * (n-1) % MOD) % MOD + MOD) % MOD;
	res = res * inv[n] % MOD;
	cout << res << endl;

}