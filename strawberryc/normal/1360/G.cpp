#include <bits/stdc++.h>

const int N = 55;

int n, m, a, b, ans[N][N];

void work()
{
	scanf("%d%d%d%d", &n, &m, &a, &b);
	if (n * a != m * b) return (void) puts("NO");
	puts("YES");
	memset(ans, 0, sizeof(ans));
	for (int i = 0, j = 0; i < n; i++, j = (j + a) % m)
		for (int k = 0; k < a; k++) ans[i][(j + k) % m] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) putchar(ans[i][j] + '0');
		puts("");
	}
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}