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
inline T Abs(const T &a) {return a < 0 ? -a : a;}

const int N = 2e5 + 5, M = 1005;

int n, a[N], djq, cnt[M], ans = 1;

int main()
{
	int x;
	read(n); read(djq);
	for (int i = 1; i <= n; i++) read(x), a[i] = x, cnt[x % djq]++;
	for (int i = 0; i < djq; i++) if (cnt[i] > 1) return puts("0"), 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = 1ll * ans * Abs(a[i] - a[j]) % djq;
	return std::cout << ans << std::endl, 0;
}