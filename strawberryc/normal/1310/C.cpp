#include <bits/stdc++.h>

typedef long long ll;

const int N = 1005;
const ll INF = 1145141919810114514ll;

int n, m, lcp[N][N], rk[N][N], ri[N], tot;
ll k, f[N];
char s[N];

struct subs
{
	int l, r;
} a[N * N];

inline bool comp(subs a, subs b)
{
	int p = a.l + lcp[a.l][b.l], q = b.l + lcp[a.l][b.l];
	if (p > a.r || q > b.r) return a.r - a.l < b.r - b.l;
	return s[p] < s[q];
}

inline ll add(const ll &a, const ll &b)
{
	return a + b > INF ? INF : a + b;
}

ll calc(int mid)
{
	for (int i = 1; i <= n; i++)
	{
		ri[i] = i;
		while (ri[i] <= n && rk[i][ri[i]] < mid) ri[i]++;
	}
	memset(f, 0, sizeof(f)); f[n + 1] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = n; j >= 1; j--) f[j] = add(f[j], f[j + 1]);
		for (int j = 1; j <= n; j++) f[j] = ri[j] <= n ? f[ri[j] + 1] : 0;
		f[n + 1] = 0;
	}
	return f[1];
}

int main()
{
	std::cin >> n >> m >> k;
	scanf("%s", s + 1);
	for (int i = n; i >= 1; i--)
		for (int j = n; j >= 1; j--)
			if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			a[++tot] = (subs) {i, j};
	std::sort(a + 1, a + tot + 1, comp);
	for (int i = 1; i <= tot; i++) rk[a[i].l][a[i].r] = i;
	int l = 1, r = tot;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (calc(mid) >= k) l = mid + 1;
		else r = mid - 1;
	}
	for (int i = a[r].l; i <= a[r].r; i++) putchar(s[i]);
	return puts(""), 0;
}