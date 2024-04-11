#include <bits/stdc++.h>

const int N = 110, M = N * N;

int n, ans[N], f[M], a[N], b[N];

void add(int v) {printf("+ %d\n", v); fflush(stdout);}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n + 1; i++) f[i * (i - 1) >> 1] = i;
	scanf("%*d%*d");
	for (int i = 1; i <= n - 4; i++) add(n - i), scanf("%d%d", &a[i], &b[i]);
	add(3); scanf("%d%d", &a[n - 3], &b[n - 3]);
	add(1); scanf("%d%d", &a[n - 2], &b[n - 2]);
	add(2); scanf("%d%d", &a[n - 1], &b[n - 1]);
	add(1); scanf("%d%d", &a[n], &b[n]);
	ans[1] = f[a[n] - a[n - 1]] - 1;
	ans[3] = (b[n] - b[n - 1]) - (b[n - 2] - b[n - 3]) - 1;
	ans[2] = (b[n] - b[n - 1]) / (ans[3] + 1) - 1;
	ans[4] = (b[n - 1] - b[n - 2]) / (ans[3] + 1) - (ans[1] + 1) - (n > 4);
	for (int i = n - 3; i >= 2; i--)
	{
		int x = n - i;
		ans[x + 2] = (b[i] - b[i - 1] - ans[x - 2] * ans[x - 1] - ans[x - 1]
			* (ans[x + 1] + 1)) / (ans[x + 1] + 1) - (i > 2);
	}
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return puts(""), 0;
}