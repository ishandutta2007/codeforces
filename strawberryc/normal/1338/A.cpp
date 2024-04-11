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

int n, ans;

int maxbit(int n)
{
	int res = 0;
	while (n) n >>= 1, res++;
	return res;
}

int main()
{
	int x, mx, T; read(T);
	while (T--)
	{
		read(n); ans = 0;
		for (int i = 1; i <= n; i++)
		{
			read(x); mx = i == 1 ? x : std::max(mx, x);
			ans = std::max(ans, maxbit(mx - x));
		}
		printf("%d\n", ans);
	}
	return 0;
}