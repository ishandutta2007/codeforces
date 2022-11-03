#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAXN = 2E5 + 10;
const int MOD = 1E9 + 7;

ll inv[MAXN];
ll fac[MAXN], facinv[MAXN];

void getInv(int n = MAXN - 1, ll m = MOD){
	inv[0] = 0, inv[1] = 1;
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= n; ++i){
		inv[i] = inv[m % i] * (m - m / i) % m;
		fac[i] = fac[i - 1] * i % m;
		facinv[i] = facinv[i - 1] * inv[i] % m;
	}
}

ll C(int n, int m){
	return n < m || m < 0 ? 0 : fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}

char s[MAXN];
int pre[MAXN], suf[MAXN];

int main(){
	getInv();

	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + (s[i] == '(');
	for (int i = n; i >= 1; --i)
		suf[i] = suf[i + 1] + (s[i] == ')');
	ll ans = 0;
	for (int i = 1; i <= n; ++i){
		if (s[i] != ')')
			continue;

		ans += C(pre[i - 1] + suf[i + 1], suf[i + 1] + 1);
	}
	printf("%lld\n", ans % MOD);
	return 0;
}