#include <cstdio>

int main()
{
	int a, b, ans = 0, P = 1000000007;
	scanf("%d%d", &a, &b);
	for (int q = 1; q < b; q++)
		ans = (ans + 1ll * q * (1ll * a * b % P + b + 2) % P * a) % P;
	ans = 1ll * ans * (P + 1) / 2 % P;
	printf("%d\n", ans);
	return 0;
}