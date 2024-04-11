#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1000000 + 10;
LL pw[10] = {0}, pw2[N];
void fwt(int n, LL a[], LL res[]) {
	int tot = pw[n];
	for (int i = 0; i < tot; i ++) res[i] = a[i];
	for (int i = 0; i < n; i ++) {
		for (int mask = tot - 1; mask >= 0; mask --) {
			int x = (mask / pw[i]) % 10;
			if (x < 9) {
				(res[mask] += res[mask + pw[i]]) %= MOD;
			}
		}
	}
}
void ufwt(int n, LL a[], LL res[]) {
	int tot = pw[n];
	for (int i = 0; i < tot; i ++) res[i] = a[i];
	for (int i = n-1; i >= 0; i --) {
		for (int mask = 0; mask < tot; mask ++) {
			int x = (mask / pw[i]) % 10;
			if (x < 9) {
				res[mask] -= res[mask + pw[i]];
				res[mask] = (res[mask] % MOD + MOD) % MOD;
			}
		}
	}
}
int n;
LL val[N], cnt1[N], cnt2[N], cnt3[N];
int main() {
	pw[0] = 1; pw2[0] = 1;
	for (int i = 1; i <= 6; i ++)
		pw[i] = pw[i-1] * 10;
	for (int i = 1; i < N; i ++) 
		pw2[i] = pw2[i-1] * 2 % MOD;

	scanf("%d",&n);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &val[i]);
		cnt1[ val[i] ] ++;
		(cnt2[ val[i] ] += val[i]) %= MOD;
		cnt3[ val[i] ] = (cnt3[val[i]] + 1LL * val[i] * val[i]) % MOD;
	}
	fwt(6,cnt1,cnt1);
	fwt(6,cnt2,cnt2);
	fwt(6,cnt3,cnt3);
	//printf("# %d\n", cnt2[123]);
	for (int i = 0; i < pw[6]; i ++) {
		val[i] = 0;
		if (cnt1[i] >= 2) (val[i] += (1LL * cnt2[i] * cnt2[i] % MOD - cnt3[i]) * pw2[cnt1[i] - 2]) %= MOD;
		if (cnt1[i] >= 1) (val[i] += 1LL * cnt3[i] * pw2[cnt1[i] - 1] % MOD) %= MOD;
		val[i] = (val[i] % MOD + MOD) % MOD;
 	}
	//printf("# %d\n", val[555]);
	ufwt(6,val,val);
	// printf("! %d\n", val[555]);
	LL ans = 0;
	for (int x = 0; x < pw[6]; x ++) {
		LL tmp = x * (1LL * val[x]);
		ans = ans ^ tmp;
	}
	cout << ans << endl;
}