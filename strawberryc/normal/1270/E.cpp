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

const int N = 1005;

int n, m, X[N], Y[N];

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(X[i]), read(Y[i]);
	while (1)
	{
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= n; i++)
			(X[i] + Y[i] & 1 ? c1 : c0)++;
		if (c0 && c1)
		{
			std::cout << c1 << std::endl;
			for (int i = 1; i <= n; i++) if (X[i] + Y[i] & 1)
				printf("%d ", i);
			return puts(""), 0;
		}
		for (int i = 1; i <= n; i++)
		{
			int x = X[i] + Y[i], y = X[i] - Y[i];
			X[i] = x - (c1 > 0) >> 1; Y[i] = y - (c1 > 0) >> 1;
		}
	}
	return 0;
}