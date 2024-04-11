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

typedef long long ll;

const int N = 2e5 + 5;

int n, m;
ll a[N], b[N];

int main()
{
	ll g = -1;
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
		if (g == -1) g = a[i] - a[i - 1];
		else g = std::__gcd(a[i] - a[i - 1], g);
	for (int i = 1; i <= m; i++)
	{
		read(b[i]); ll res = a[1] + b[i];
		if (n > 1) res = std::__gcd(res, g);
		printf("%lld ", res);
	}
	return puts(""), 0;
}