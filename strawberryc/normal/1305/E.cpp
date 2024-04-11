#include <bits/stdc++.h>

const int N = 5005;

int n, m, sum, ans[N];

int main()
{
	int i = 1, E = 20001;
	std::cin >> n >> m;
	while (m > 0 && i <= n)
	{
		int delta = (i - 1) / 2;
		if (m >= delta) ans[i] = i;
		else for (int j = 2; j < i; j++)
			if ((i - j) / 2 == m) {ans[i] = j + i - 1; break;}
		m -= delta; i++;
	}
	if (m > 0) return puts("-1"), 0;
	while (i <= n) ans[i] = E, E += 10000, i++;
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return puts(""), 0;
}