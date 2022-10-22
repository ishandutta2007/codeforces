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

const int N = 2e5 + 5;

int n, b[N];

int main()
{
	int now = 0;
	read(n);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= n; i++)
	{
		int res = b[i] + now;
		printf("%d ", res); now = std::max(now, res);
	}
	return puts(""), 0;
}