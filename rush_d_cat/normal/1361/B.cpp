#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
typedef long long LL;
const LL MOD = 1e9 + 7;

int t;
int n, p, k[N], sgn[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &p);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &k[i]); sgn[i] = 0;
		}
		if (p == 1) {
			if (n % 2 == 0) {
				printf("0\n");
			} else {
				printf("1\n");
			}
			continue;
		}
		sort(k + 1, k + 1 + n);
		LL A = 0; sgn[n] = 1;
		for (int i = n; i >= 1; i --) {
			if (i == n) {
				A ++; continue;
			}
			int d = k[i + 1] - k[i];

			if (A && d) {
				for (int it = 1; it <= d; it ++) {
					A *= p; 	
					if (A >= n) {
						for (int x = i; x >= 1; x --) sgn[x] = -1;
						break;
					}
				}
			} 
			if (sgn[1] == -1) {
				break;
			}
			if (A > 0) {
				-- A; sgn[i] = -1;
			} else if (A == 0) { 
				++ A; sgn[i] = +1;
			}

		}
		LL ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (sgn[i] == -1) {
				ans = ans - mpow(p, k[i]);
			} else {
				ans = ans + mpow(p, k[i]);
			}
		}
		ans = (ans % MOD + MOD) % MOD;
		printf("%lld\n", ans);
	}
}