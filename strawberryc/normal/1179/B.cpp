#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

int n, m;

int main()
{
	read(n); read(m);
	for (int i = 1; (i << 1) <= n; i++)
	{
		int st = i, ed = n - i + 1;
		for (int j = 1; j <= m; j++)
			printf("%d %d\n%d %d\n", st, j, ed, m - j + 1);
	}
	if (n & 1)
	{
		for (int i = 1; (i << 1) <= m; i++)
			printf("%d %d\n%d %d\n", (n >> 1) + 1, i, (n >> 1) + 1, m - i + 1);
		if (m & 1) std::cout << (n >> 1) + 1 << " " << (m >> 1) + 1 << std::endl;
	}
	return 0;
}