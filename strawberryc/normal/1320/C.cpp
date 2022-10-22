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

typedef long long ll;

const int N = 2e5 + 5, M = 4e6 + 5;
const ll INF = 1e18;

int n, m, p, b[N], cb[N];
ll mx[M], add[M], ans = -INF;

std::vector<int> w[M];

struct elem
{
	int a, ca;
} a[N];

struct mons
{
	int x, y, z;
} arr[N];

inline bool comp(elem x, elem y)
{
	return x.a < y.a;
}

inline bool pmoc(mons x, mons y)
{
	return x.x < y.x;
}

void build(int l, int r, int p)
{
	if (l == r)
	{
		mx[p] = -INF;
		for (int i = 0; i < w[l].size(); i++)
			mx[p] = std::max(mx[p], -1ll * w[l][i]);
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	mx[p] = std::max(mx[p2], mx[p3]);
}

void change(int l, int r, int s, int e, int v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return (void) (add[p] += v, mx[p] += v);
	int mid = l + r >> 1; add[p2] += add[p]; add[p3] += add[p];
	mx[p2] += add[p]; mx[p3] += add[p]; add[p] = 0;
	change(l, mid, s, e, v, p2);
	change(mid + 1, r, s, e, v, p3);
	mx[p] = std::max(mx[p2], mx[p3]);
}

int main()
{
	int x, y;
	read(n); read(m); read(p);
	for (int i = 1; i <= n; i++) read(a[i].a), read(a[i].ca);
	std::sort(a + 1, a + n + 1, comp);
	for (int i = 1; i <= m; i++) read(b[i]), read(cb[i]), w[b[i]].push_back(cb[i]);
	for (int i = 1; i <= p; i++) read(arr[i].x), read(arr[i].y), read(arr[i].z);
	std::sort(arr + 1, arr + p + 1, pmoc);
	build(1, 1000000, 1);
	for (int i = 1, k = 1; i <= n; i++)
	{
		while (k <= p && arr[k].x < a[i].a)
		{
			if (arr[k].y < 1000000) change(1, 1000000, arr[k].y + 1, 1000000,
				arr[k].z, 1);
			k++;
		}
		ans = std::max(ans, mx[1] - a[i].ca);
	}
	return std::cout << ans << std::endl, 0;
}