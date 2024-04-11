#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 100;
const ll MOD = 1E9 + 7;

int n, k;

char s[MAXN];

ll com[MAXN], inv[MAXN], cominv[MAXN];
ll a[MAXN], sum[MAXN];

void pre(){
	inv[0] = 0, inv[1] = 1;
	com[0] = com[1] = 1;
	cominv[0] = cominv[1] = 1;
	for (int i = 2; i < MAXN; ++i){
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		com[i] = com[i - 1] * i % MOD;
		cominv[i] = cominv[i - 1] * inv[i] % MOD;
	}

	ll e = 1;
	sum[1] = 0;
	for (int i = 2; i <= n - k + 1; ++i){
		a[i] = com[n - i] * cominv[k - 1] % MOD * cominv[n - i - k + 1] % MOD * e % MOD;
		sum[i] = (sum[i - 1] + a[i]) % MOD;
		e  = e * 10 % MOD;
	}
}

int main(){
	scanf("%d%d", &n, &k);
	scanf("%s", s);

	pre();
	ll ans = 0;
	if (k > 0){
		for (int i = 0; i < n; ++i){
			ans = (ans + (s[i] - '0') * sum[min(n - i, n - k + 1)]) % MOD;
		}
	}

	ll e = 1;
	for (int i = 1; i <= n - k; ++i){
		ans = (ans + com[n - i] * cominv[k] % MOD * cominv[n - i - k] % MOD * e % MOD * (s[n - i] - '0')) % MOD;
		e = e * 10 % MOD;
	}
	printf("%d\n", (int)ans);
	return 0;
}