#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int ans = 1, x;
		scanf("%d", &x);
		while (x) ans *= 2, x &= x - 1;
		printf("%d\n", ans);
	}
	return 0;
}