#include <bits/stdc++.h>

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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e5 + 5, M = 1e7 + 5;

int n, ToT, R;
bool ans;

struct inv
{
	int l, r, x, y;
} a[N];

struct node
{
	int lc, rc, add, mx;
} T[M];

std::vector<inv> eq[N];

inline bool comp(inv a, inv b)
{
	return a.r < b.r;
}

void down(int p)
{
	if (!T[p].lc) T[p].lc = ++ToT;
	if (!T[p].rc) T[p].rc = ++ToT;
	T[T[p].lc].add += T[p].add; T[T[p].lc].mx += T[p].add;
	T[T[p].rc].add += T[p].add; T[T[p].rc].mx += T[p].add;
	T[p].add = 0;
}

void change(int l, int r, int s, int e, int v, int &p)
{
	if (!p) p = ++ToT;
	if (e < l || s > r) return;
	if (s <= l && r <= e) return (void) (T[p].add += v, T[p].mx += v);
	int mid = l + r >> 1; down(p);
	change(l, mid, s, e, v, T[p].lc);
	change(mid + 1, r, s, e, v, T[p].rc);
	T[p].mx = Max(T[T[p].lc].mx, T[T[p].rc].mx);
}

int ask(int l, int r, int s, int e, int p)
{
	if (e < l || s > r || !p) return 0;
	if (s <= l && r <= e) return T[p].mx;
	int mid = l + r >> 1; down(p);
	return Max(ask(l, mid, s, e, T[p].lc), ask(mid + 1, r, s, e, T[p].rc)); 
}

void jiejuediao()
{
	for (int i = 1; i <= ToT; i++) T[i].lc = T[i].rc = T[i].add = T[i].mx = 0;
	ToT = R = 0;
	std::sort(a + 1, a + n + 1, comp);
	for (int i = 1; i <= n; i++) eq[i].clear();
	for (int i = 1, p = 1; i <= n; i++)
	{
		int l = 1, r = n;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (a[mid].r < a[i].l) l = mid + 1;
			else r = mid - 1;
		}
		if (r) eq[r].push_back(a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		change(1, 1e9, a[i].x, a[i].y, 1, R);
		for (int j = 0; j < eq[i].size(); j++)
			if (ask(1, 1e9, eq[i][j].x, eq[i][j].y, R)) ans = 1;
	}
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].l), read(a[i].r), read(a[i].x), read(a[i].y);
	jiejuediao();
	for (int i = 1; i <= n; i++) std::swap(a[i].l, a[i].x),
		std::swap(a[i].r, a[i].y);
	jiejuediao();
	return puts(ans ? "NO" : "YES"), 0;
}