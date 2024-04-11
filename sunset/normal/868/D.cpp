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

const int MAXN = 205;
const int lim = 30;

struct String
{
	set <int> s[lim + 1];
	char l[lim], r[lim], c[MAXN];
	int len, ans;

	inline void Init()
	{
		for (int i = 0; i < len; i ++)
		{
			int cur = 0;
			for (int j = i; j < len && j - i + 1 <= lim; j ++)
				cur = cur << 1 | c[j] - '0', s[j - i + 1].insert(cur);
		}
	}

	inline void Get()
	{
		ans = 1;
		while (s[ans].size() == 1 << ans)
			ans ++;
		printf("%d\n", ans - 1);
	}
} a[MAXN];

int n, m;
char t[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", a[i].c), a[i].len = strlen(a[i].c);
		for (int j = 0; j < min(a[i].len, lim); j ++)
			a[i].l[j] = a[i].c[j], a[i].r[j] = a[i].c[a[i].len - j - 1];
		a[i].Init();
		a[i].len = min(a[i].len, lim << 1);
	}
	m = Read();
	for (int q = 1; q <= m; q ++)
	{
		int i = n + q, x = Read(), y = Read(), z = 0;
		a[i].len = a[x].len + a[y].len;
		for (int j = 0; j < min(a[i].len, lim); j ++)
			a[i].l[j] = j < a[x].len ? a[x].l[j] : a[y].l[j - a[x].len],
			a[i].r[j] = j < a[y].len ? a[y].r[j] : a[x].r[j - a[y].len];
		for (int j = 1; j <= lim; j ++)
		{
			for (auto t : a[x].s[j])
				a[i].s[j].insert(t);
			for (auto t : a[y].s[j])
				a[i].s[j].insert(t);
		}
		for (int j = min(a[x].len, lim) - 1; ~j; j --)
			t[z ++] = a[x].r[j];
		for (int j = 0; j < min(a[y].len, lim); j ++)
			t[z ++] = a[y].l[j];
		for (int _i = 0; _i < z; _i ++)
		{
			int cur = 0;
			for (int j = _i; j < z && j - _i + 1 <= lim; j ++)
				cur = cur << 1 | t[j] - '0', a[i].s[j - _i + 1].insert(cur);
		}
		a[i].Get();
		a[i].len = min(a[i].len, lim << 1);
	}
}