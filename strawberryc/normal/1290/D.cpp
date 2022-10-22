#include <bits/stdc++.h>

const int N = 1030;

bool query(int x)
{
	char c;
	printf("? %d\n", x); fflush(stdout);
	while ((c = getchar()) != 'N' && c != 'Y');
	return c == 'Y';
}

int n, k, m, ans;
bool res[N];

int main()
{
	std::cin >> n >> k;
	if (k > 1) k /= 2; m = n / k;
	memset(res, true, sizeof(res));
	if (m == 1)
	{
		for (int i = 1; i <= n; i++) if (!query(i)) ans++;
		return printf("! %d\n", ans), 0;
	}
	for (int i = 0; i < m / 2; i++)
	{
		puts("R"); fflush(stdout);
		for (int j = 0; j < m; j++)
		{
			int x = (i + (j & 1 ? -1 : 1) * (j + 1 >> 1) + m) % m;
			for (int s = 1; s <= k; s++)
				if (res[x * k + s] && query(x * k + s)) res[x * k + s] = 0;
		}
	}
	for (int i = 1; i <= n; i++) ans += res[i];
	return printf("! %d\n", ans), 0;
}