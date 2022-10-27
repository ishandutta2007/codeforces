#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 998244353;
int n, m;
int d[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL sum[N];
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i ++){
		scanf("%d", &d[i]); 
	}

	sort(d + 1, d + 1 + n);
	for (int i = 1; i <= n; i ++) {
		sum[i] = (sum[i-1] + d[i]) % MOD;
	}
	for (int i = 1; i <= m; i ++) {
		int a, b; scanf("%d%d", &a, &b);
		int pos = lower_bound(d + 1, d + 1 + n, b) - d;
		int x = n - pos + 1;

		if (x < a)
			printf("0\n");
		else {
			int y = n - x;
			LL ans = sum[n];
			LL small = sum[pos - 1];
			LL large = sum[n] - sum[pos - 1];
			//printf("small = %lld, large = %lld\n",small,large);
			//printf("x = %d, y = %d\n", x, y);
			ans -= small * a % MOD * mpow(x + 1, MOD - 2) % MOD;
			ans -= large * a % MOD * mpow(x, MOD - 2) % MOD;
			ans = (ans % MOD + MOD) % MOD;
			printf("%lld\n", ans);
		}
	}	
}
/*
a b

count(d >= b) = x

if x <= a 
	ans = 0

if x > a

# # # # 

*/