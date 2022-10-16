#include <cstdio>

const int N = 355;

int n;
int b[N];
int c[N][N];
int a[N][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1, k = 0; j <= n; j++, k = (k + i - 1) % n)
			c[i][j] = k;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = (b[i] + c[i][j] + n - c[i][i]) % n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%d%c", a[i][j], " \n"[j == n]);
	return 0;
}