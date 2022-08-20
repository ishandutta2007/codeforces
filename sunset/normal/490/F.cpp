#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 200005;
const int MAXM = 8000005;

struct node { int l, r, lis, lds; } e[MAXM];
vector < int > G[MAXN];
int n, a[MAXN], ans, tot, b[MAXN], m, rt[MAXN];

inline void merge(int &x, int y)
{
	if (!x || !y) { x += y; return ; }
	e[x].lis = max(e[x].lis, e[y].lis);
	e[x].lds = max(e[x].lds, e[y].lds);
	ans = max(e[e[x].l].lis + e[e[y].r].lds, ans);
	ans = max(e[e[x].r].lds + e[e[y].l].lis, ans);
	merge(e[x].l, e[y].l);
	merge(e[x].r, e[y].r);
}

inline void modify(int &x, int l, int r, int p, int v, int t)
{
	if (!x) x = ++ tot;
	if (t) e[x].lds = max(e[x].lds, v);
	else e[x].lis = max(e[x].lis, v);
	if (l == r) return ;
	int mid = l + r >> 1;
	p <= mid ? modify(e[x].l, l, mid, p, v, t) : modify(e[x].r, mid + 1, r, p, v, t);
}

inline int query(int x, int l, int r, int ql, int qr, int t)
{
	if (!x) return 0;
	if (l == ql && r == qr) return t ? e[x].lds : e[x].lis;
	int mid = l + r >> 1;
	return qr <= mid ? query(e[x].l, l, mid, ql, qr, t) : ql > mid ? query(e[x].r, mid + 1, r, ql, qr, t) : max(query(e[x].l, l, mid, ql, mid, t), query(e[x].r, mid + 1, r, mid + 1, qr, t));
}

inline void dfs(int x, int fa)
{
	int lis1 = 0, lis2 = 0, lds1 = 0, lds2 = 0;
	for (auto y : G[x])
		if (y ^ fa)
		{
			dfs(y, x);
			lis2 = query(rt[y], 1, m, 1, a[x] - 1, 0);
			lds2 = query(rt[y], 1, m, a[x] + 1, m, 1);
			ans = max(ans, lis2 + lds1 + 1);
			ans = max(ans, lis1 + lds2 + 1);
			lis1 = max(lis1, lis2);
			lds1 = max(lds1, lds2);
			merge(rt[x], rt[y]);
		}
	modify(rt[x], 1, m, a[x], lis1 + 1, 0);
	modify(rt[x], 1, m, a[x], lds1 + 1, 1);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i ++) a[i] = b[i] = read();
	sort(b + 1, b + n + 1); m = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i ++) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
	for (int i = 1, x, y; i < n; i ++) x = read(), y = read(), G[x].pb(y), G[y].pb(x);
	dfs(1, 0);
	return printf("%d\n", ans), 0;
}