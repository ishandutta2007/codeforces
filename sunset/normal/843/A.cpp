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

const int MAXN = 100005;

int a[MAXN], l[MAXN], n, m;
vector <int> ans[MAXN];
bool v[MAXN];

inline void Dfs(int x)
{
	if (v[x])
		return ;
	v[x] = 1; ans[m].pb(x);
	Dfs(a[x]);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = l[i] = Read();
	sort(l + 1, l + n + 1);
	for (int i = 1; i <= n; i ++)
		a[i] = lower_bound(l + 1, l + n + 1, a[i]) - l;
	for (int i = 1; i <= n; i ++)
		if (!v[i])
			m ++, Dfs(i);
	printf("%d\n", m);
	for (int i = 1; i <= m; i ++)
	{
		printf("%d", ans[i].size());
		for (auto x : ans[i])
			printf(" %d", x);
		putchar(10);
	}
}