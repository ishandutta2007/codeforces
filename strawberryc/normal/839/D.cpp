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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 2e5 + 5, M = 1e6 + 5, rqy = 1e9 + 7;

int n, a[N], m, f[M], p2[N], ans;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), m = Max(m, a[i]), f[a[i]]++;
	p2[0] = 1;
	for (int i = 1; i <= n; i++) p2[i] = (p2[i - 1] + p2[i - 1]) % rqy;
	for (int i = 1; i <= m; i++)
		for (int j = i << 1; j <= m; j += i)
			f[i] += f[j];
	for (int i = 1; i <= m; i++) if (f[i])
		f[i] = 1ll * f[i] * p2[f[i] - 1] % rqy;
	for (int i = m; i >= 1; i--)
		for (int j = i << 1; j <= m; j += i)
			f[i] = (f[i] - f[j] + rqy) % rqy;
	for (int i = 2; i <= m; i++) ans = (1ll * i * f[i] + ans) % rqy;
	return std::cout << ans << std::endl, 0;
}