/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 559C
 */
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

const int MAXH = 2E5 + 100, MAXN = 2E3 + 10;
const ll MOD = 1E9 + 7;

ll fac[MAXH], inv[MAXH], facinv[MAXH];
pair<int, int> a[MAXN];

ll cnt[MAXN];

ll com(int x, int y){
	return fac[x + y] * facinv[x] % MOD * facinv[y] % MOD;
}

int main(){
	fac[0] = fac[1] = 1;
	inv[0] = 0, inv[1] = 1;
	facinv[0] = 1, facinv[1] = 1;
	for (int i = 2; i < MAXH; ++i){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		facinv[i] = facinv[i - 1] * inv[i] % MOD;
	}

	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	a[n] = make_pair(h, w);
	sort(a, a + n + 1);

	for (int i = 0; i <= n; ++i){
		cnt[i] = com(a[i].first - 1, a[i].second - 1);
		for (int j = 0; j < i; ++j)
			if (a[j].second <= a[i].second)
				cnt[i] = (cnt[i] - cnt[j] * com(a[i].first - a[j].first, a[i].second - a[j].second)) % MOD;
		cnt[i] = (cnt[i] + MOD) % MOD;
	}
	printf("%I64d\n", cnt[n]);

	return 0;
}