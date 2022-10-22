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

const int N = 1e5 + 5;

int n, k, fa[N], ans;

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

bool zm(int x, int y)
{
	x = cx(x); y = cx(y);
	if (x != y) return fa[y] = x, 1;
	return 0;
}

int main()
{
	int x, y;
	read(n); read(k); ans = k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= k; i++)
	{
		read(x); read(y);
		if (zm(x, y)) ans--;
	}
	return std::cout << ans << std::endl, 0;
}