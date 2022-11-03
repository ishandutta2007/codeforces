#include <cstdio>

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int i, ans = 0;
	for (i = (x - 1) / n + 1; i * (long long)i < x; ++i)
		ans += x % i == 0;
	printf("%d\n", ans = ans << 1 | i * (long long)i == x);
	return 0;
}