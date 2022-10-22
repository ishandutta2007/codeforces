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

const int N = 1e5 + 5;

int n, m, fir[N], lst[N], l, a[N];
ll ans;

int main()
{
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(l);
		for (int j = 1; j <= l; j++) read(a[j]);
		bool is = 1;
		for (int j = 1; j < l; j++) if (a[j] < a[j + 1]) is = 0;
		if (is) fir[++n] = a[1], lst[n] = a[l];
	}
	std::sort(fir + 1, fir + n + 1); std::sort(lst + 1, lst + n + 1);
	for (int i = 1, p = 1; i <= n; i++)
	{
		while (p <= n && fir[p] <= lst[i]) p++;
		ans += p - 1;
	}
	return std::cout << 1ll * m * m - ans << std::endl, 0;
}