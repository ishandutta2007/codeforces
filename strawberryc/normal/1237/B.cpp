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

int n, a[N], b[N], tb[N], mx, ans;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]), tb[b[i]] = i;
	for (int i = 1; i <= n; i++)
		if (mx > tb[a[i]]) ans++;
		else mx = tb[a[i]];
	return std::cout << ans << std::endl, 0;
}