#include <cstdio>

typedef long long ll;

int main(){
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	int ans = 0;
	for (int i = 2; i <= 60; ++i){
		ll t = (1ll << i) - 1;
		for (int j = i - 2; j >= 0; --j){
			ll t1 = t ^ 1ll << j;
			ans += a <= t1 && t1 <= b;
		}
	}
	printf("%d\n", ans);
	return 0;
}