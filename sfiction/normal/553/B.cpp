/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 553B
 */
/*
 * resort>=3
 * nf[n]1f[i - 1]22f[i - 2]
 */
#include <cstdio>

typedef long long ll;

const int MAXN = 60;

ll a[MAXN];
int b[MAXN];

int main(){
	int n;
	ll k;
	scanf("%d%I64d", &n, &k);
	a[0] = a[1] = 1;
	for (int i = 2; i <= n; ++i)
		a[i] = a[i - 1] + a[i - 2];
	for (int i = 1; i <= n; ++i){
		if (k <= a[n - i]){
			b[i] = i;
		}
		else{
			k -= a[n - i];
			b[i] = i + 1;
			b[i + 1] = i;
			++i;
		}
	}
	for (int i = 1; i < n; ++i)
		printf("%d ", b[i]);
	printf("%d\n", b[n]);
	return 0;
}