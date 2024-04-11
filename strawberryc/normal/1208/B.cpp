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

const int N = 2005;

int n, a[N], b[N], m, cnt[N], tmp[N], ans;

int main()
{
	read(n); ans = n;
	for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
	std::sort(b + 1, b + n + 1);
	m = std::unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
	for (int i = 0; i <= n; i++)
	{
		if (cnt[a[i]]) break;
		if (i) cnt[a[i]]++;
		for (int j = 1; j <= m; j++) tmp[j] = cnt[j];
		for (int j = n + 1; j > i; j--)
		{
			if (tmp[a[j]]) break;
			if (j <= n) tmp[a[j]]++;
			if (j - i - 1 < ans) ans = j - i - 1;
		}
	}
	return std::cout << ans << std::endl, 0;
}