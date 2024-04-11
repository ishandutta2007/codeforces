#include <cstdio>

typedef long long ll;

const int MAXN = 2E5 + 10, MAXA = 1E6 + 10;
const ll MOD = 1E9 + 7;

int n, K, Q;
ll inv[MAXN], com[MAXN], cominv[MAXN];
ll comK[MAXN];

ll tot;
int c[MAXA];
int cnt[MAXA];

void preWork(){
	inv[0] = 0, inv[1] = 1;
	com[0] = com[1] = 1;
	cominv[0] = cominv[1] = 1;
	for (int i = 2; i < MAXN; ++i){
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		com[i] = com[i - 1] * i % MOD;
		cominv[i] = cominv[i - 1] * inv[i] % MOD;
	}

	comK[K - 1] = 1;
	for (int i = K; i < MAXN; ++i)
		comK[i] = comK[i - 1] * i % MOD * inv[i - K + 1] % MOD;

	for (int i = 1; i < MAXA; ++i){
		c[i] += i;
		for (int j = i << 1; j < MAXA; j += i)
			c[j] -= c[i];
	}
}

void update(int i){
	tot = (tot + comK[cnt[i]] * (ll)c[i]) % MOD;
//	printf("%d, %d %d, %I64d\n", i, cnt[i], c[i], tot);
	++cnt[i];
}

int main(){
	scanf("%d%d%d", &n, &K, &Q);
	preWork();

	tot = 0;
	for (int t, i = 0; i < n + Q; ++i){
		scanf("%d", &t);
//		printf("update %d:\n", t);
		for (int j = 1; j * j <= t; ++j)
			if (t % j == 0){
				update(j);
				if (j * j != t)
					update(t / j);
			}

		if (i >= n)
			printf("%I64d\n", tot);
	}
	return 0;
}