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

const int N = 105;

int n, k, x[N], y[N];

void work()
{
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
	for (int i = 1; i <= n; i++)
	{
		bool is = 1;
		for (int j = 1; j <= n; j++)
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) is = 0;
		if (is) return (void) puts("1");
	}
	puts("-1");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}