#include <bits/stdc++.h>

const int N = 40;

int n, m, L, R, a[N][N], S = 1, bi[N];

int main()
{
	std::cin >> L >> R;
	if (L == R)
	{
		puts("YES\n2 1");
		return printf("%d %d %d\n", 1, 2, L), 0;
	}
	if (L > 1) S = n = 2, a[1][2] = L - 1, R -= L - 1;
	else n = 1; R--;
	for (int T = 0; T < 20; T++)
	{
		bi[T] = ++n; a[S][n] = 1;
		for (int i = 0; i < T; i++) a[bi[i]][n] = 1 << i;
	}
	a[S][++n] = 1; int pre = 0;
	for (int T = 0; T < 20; T++) if ((R >> T) & 1)
		a[bi[T]][n] = pre + 1, pre += 1 << T;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i][j]) m++;
	puts("YES");
	std::cout << n << " " << m << std::endl;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i][j]) printf("%d %d %d\n", i, j, a[i][j]);
	return 0;
}