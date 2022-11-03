#include <cstdio>

typedef long long ll;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	ll ans = 0;
	if (k >= n / 2)
		ans = n * (ll)(n - 1) / 2;
	else{
		for (int i = 1; i <= k; ++i)
			ans += (n - 2 * i) * 2 + 1;
	}
	printf("%I64d\n", ans);
	return 0;
}