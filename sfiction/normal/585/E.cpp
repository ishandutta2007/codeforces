#include <cstdio>

typedef long long ll;

const int MAXA = 1E7 + 10, MAXN = 5E5 + 10, MAXD = 8;
const ll MOD = 1E9 + 7;

int lpf[MAXA + 1], mob[MAXA + 1];
int pcnt, prime[MAXA / 10];
int cnt[MAXA];

void EulerSieve(){
	pcnt = 0;
	for (int i = 2; i <= MAXA; ++i){
		if (!lpf[i])
			lpf[i] = prime[pcnt++] = i;
		for (int j = 0; j < pcnt && prime[j] <= MAXA / i; ++j){
			lpf[prime[j] * i] = prime[j];
			if (i % prime[j] == 0)
				break;
		}
	}
}

ll exp2[MAXN];
int n, a[MAXN];

int main(){
	EulerSieve();
	exp2[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		exp2[i] = (exp2[i - 1] << 1) % MOD;

	scanf("%d", &n);
	mob[1] = -1;
	int len, div[1 << MAXD];
	for (int u, i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		len = div[0] = 1;
		for (int p, t = a[i]; t > 1; ){
			for (p = lpf[t]; t % p == 0; t /= p);
			for (int j = 0; j < len; ++j){
				div[j + len] = div[j] * p;
				mob[div[j + len]] = -mob[div[j]];
				++cnt[div[j + len]];
			}
			len <<= 1;
		}
	}

	ll ans = 0;
	for (int i = 2; i < MAXA; ++i)
		ans += mob[i] * (exp2[cnt[i]] - 1) * (n - cnt[i]) % MOD;
	printf("%I64d\n", (ans % MOD + MOD) % MOD);
	return 0;
}