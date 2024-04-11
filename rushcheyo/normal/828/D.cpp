#include <cstdio>

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", (n - 1) / k * 2 + ((n - 1) % k >= 1) + ((n - 1) % k >= 2));
	for (int i = 2; i <= (n - 1) / k; i++)
		for (int j = 1; j <= k; j++)
			printf("%d %d\n", (i - 1) * k + j, (i - 2) * k + j);
	for (int i = 1; i <= (n - 1) % k; i++)
	{
		printf("%d %d\n", n, (n - 1) / k * k + i);
		printf("%d %d\n", (n - 1) / k * k + i, ((n - 1) / k - 1) * k + i);
	}
	for (int i = (n - 1) % k + 1; i <= k; i++)
		printf("%d %d\n", n, ((n - 1) / k - 1) * k + i);
	return 0;
}