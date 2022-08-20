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

const int MAXN = 200005;

struct Edge
{
	int u, v, w;
	bool operator < (const Edge &b) const { return w > b.w; }
} e[MAXN];

int n, m, ans, f[MAXN], s[MAXN];

inline int Find(int x)
{
	while (x ^ f[x])
		x = f[x] = f[f[x]];
	return x;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		f[i] = i;
	for (int i = 1; i <= m; i ++)
		e[i].u = Read(), e[i].v = Read(), e[i].w = Read();
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i ++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w, fu = Find(u), fv = Find(v);
		if (fu ^ fv)
		{
			if (s[fu] && s[fv])
				continue;
			f[fu] = fv, s[fv] |= s[fu], ans += w;
		}
		else
		{
			if (!s[fu])
				s[fu] = 1, ans += w;
		}
	}
	return printf("%d\n", ans), 0;
}