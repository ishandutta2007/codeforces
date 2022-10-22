#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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

const int N = 2e5 + 5, INF = 0x3f3f3f3f;

int n, q, a[N], T[N], l[N], r[N], sm[N], tot, pos[N], cnt[N], ans;

int main()
{
	memset(l, INF, sizeof(l));
	read(n); read(q); ans = n;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		r[a[i]] = i; if (l[a[i]] == INF) l[a[i]] = i;
	}
	for (int i = 1; i <= 200000; i++) if (r[i])
		sm[l[i]]++, sm[r[i]]--;
	for (int i = 1; i < n; i++) sm[i] += sm[i - 1];
	for (int i = 1; i < n; i++) if (!sm[i]) pos[++tot] = i;
	pos[++tot] = n;
	for (int i = 1; i <= tot; i++)
	{
		int it = 0;
		for (int j = pos[i - 1] + 1; j <= pos[i]; j++)
			if ((++cnt[a[j]]) > it) it = cnt[a[j]];
		ans -= it;
	}
	return std::cout << ans << std::endl, 0;
}