#include <bits/stdc++.h>

// 0830

typedef long long ll;

inline ll readll()
{
	ll res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e5 + 5;

int n, q, cnt;
ll s[N], ans[N], now;

struct query
{
	int id; ll orz;
} a[N], b[N];

inline bool comp(query a, query b)
{
	return a.orz < b.orz;
}

int main()
{
	ll x, y;
	std::cin >> n; cnt = n;
	for (int i = 1; i <= n; i++)
		s[i] = readll();
	std::sort(s + 1, s + n + 1);
	std::cin >> q;
	for (int i = 1; i <= q; i++)
		x = readll(), y = readll(), a[i] = (query) {i, y - x};
	for (int i = 1; i < n; i++)
		b[i] = (query) {i, s[i + 1] - s[i]};
	std::sort(b + 1, b + n, comp);
	std::sort(a + 1, a + q + 1, comp);
	int p = 1;
	for (int i = 1; i <= q; i++)
	{
		while (p < n && b[p].orz <= a[i].orz)
			cnt--, now += b[p].orz, p++;
		ans[a[i].id] = now + (a[i].orz + 1) * cnt;
	}
	for (int i = 1; i <= q; i++) printf("%I64d ", ans[i]);
	return puts(""), 0;
}