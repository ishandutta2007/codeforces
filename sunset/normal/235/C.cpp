#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 2000005;

int n, m, tot = 1, lst = 1, rot = 1, f[MAXN], q[MAXN], cnt[MAXN], par[MAXN], val[MAXN], siz[MAXN], nxt[MAXN][26];
char s[MAXN];

inline void Extend(int w)
{
	int p = lst, np = ++ tot;
	val[np] = val[p] + 1, siz[np] = 1;
	while (p && !nxt[p][w])
		nxt[p][w] = np, p = par[p];
	if (!p)
		par[np] = rot;
	else
	{
		int q = nxt[p][w];
		if (val[q] == val[p] + 1)
			par[np] = q;
		else
		{
			int nq = ++ tot;
			val[nq] = val[p] + 1;
			mcpy(nxt[nq], nxt[q]);
			par[nq] = par[q], par[q] = par[np] = nq;
			while (p && nxt[p][w] == q)
				nxt[p][w] = nq, p = par[p];
		}
	}
	lst = np;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	scanf("%s", s + 1), n = strlen(s + 1), m = Read();
	for (int i = 1; i <= n; i ++)
		Extend(s[i] - 'a');
	for (int i = 2; i <= tot; i ++)
		cnt[val[i]] ++;
	for (int i = 1; i <= n; i ++)
		cnt[i] += cnt[i - 1];
	for (int i = tot; i > 1; i --)
		q[cnt[val[i]] --] = i;
	for (int i = tot - 1; i; i --)
		siz[par[q[i]]] += siz[q[i]];
	while (m --)
	{
		scanf("%s", s + 1), n = strlen(s + 1);
		for (int i = 2, j = 0; i <= n; f[i] = j += s[i] == s[j + 1], i ++)
			while (j && s[i] != s[j + 1])
				j = f[j];
		int q = n % (n - f[n]) == 0 ? n - f[n] : n, x = rot, cur = 0, ret = 0;
		for (int i = 1; i < n + q; i ++)
		{
			int w = s[i > n ? i - n : i] - 'a';
			while (x && !nxt[x][w])
				x = par[x], cur = val[x];
			if (nxt[x][w])
				x = nxt[x][w], cur ++;
			else
				x = rot, cur = 0;
			if (cur >= n)
			{
				while (x && val[par[x]] >= n)
					x = par[x], cur = val[x];
				ret += siz[x];
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}