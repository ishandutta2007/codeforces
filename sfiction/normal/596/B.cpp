#include <cstdio>

typedef long long ll;

int main(){
	int n;
	scanf("%d", &n);
	ll ans = 0;
	for (int pre = 0, x, i = 0; i < n; ++i){
		scanf("%d", &x);
		ans += x > pre ? x - pre : pre - x;
		pre = x;
	}
	printf("%I64d\n", ans);
	return 0;
}