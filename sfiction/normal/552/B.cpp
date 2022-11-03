/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 552B
 */
#include <cstdio>

int main(){
	long long n, k, ans = 0;

	scanf("%I64d", &n);
	for (k = 1; n >= k; k *= 10)
		ans += n - k + 1;
	printf("%I64d", ans);

	return 0;
}