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

const int MAXN = 300005;
const int MAXM = 9000005;

struct Node { int l, r, s; } e[MAXM];
int n, tot, Q, ans, rt[MAXN];

inline void Modify(int &x, int y, int l, int r, int v)
{
	e[x = ++ tot] = e[y]; e[x].s ++;
	if (l == r)
		return ;
	int mid = l + r >> 1;
	if (v <= mid)
		Modify(e[x].l, e[y].l, l, mid, v);
	else
		Modify(e[x].r, e[y].r, mid + 1, r, v);
}

inline void Query(int x, int y, int l, int r, int v)
{
	if (e[x].s - e[y].s <= v)
		return ;
	if (l == r)
		return (void)(ans = min(ans, l));
	int mid = l + r >> 1;
	Query(e[x].l, e[y].l, l, mid, v);
	Query(e[x].r, e[y].r, mid + 1, r, v);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(); Q = Read();
	for (int i = 1; i <= n; i ++)
		Modify(rt[i], rt[i - 1], 1, n, Read());
	while (Q --)
	{
		int l = Read(), r = Read(), k = Read();
		ans = n + 1;
		Query(rt[r], rt[l - 1], 1, n, (r - l + 1) / k);
		if (ans == n + 1)
			ans = -1;
		printf("%d\n", ans);
	}
}