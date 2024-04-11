#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 3e5 + 5, M = N << 1, L = 3e7 + 5;

int n, m, k, tmp, arr[M], rt[N], pos[M], ToT;

struct interval
{
	int l, r, p;
} a[N];

struct node
{
	int lc, rc, val;
} T[L];

inline bool comp(interval a, interval b)
{
	return a.r < b.r;
}

void ins(int y, int &x, int l, int r, int p, int val)
{
	T[x = ++ToT] = T[y];
	if (l == r) return (void) (T[x].val = Max(T[x].val, val));
	int mid = l + r >> 1;
	if (p <= mid) ins(T[y].lc, T[x].lc, l, mid, p, val);
	else ins(T[y].rc, T[x].rc, mid + 1, r, p, val);
	T[x].val = Min(T[T[x].lc].val, T[T[x].rc].val);
}

int query(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return T[p].val;
	int mid = l + r >> 1;
	if (e <= mid) return query(l, mid, s, e, T[p].lc);
	else if (s >= mid + 1) return query(mid + 1, r, s, e, T[p].rc);
	else return Min(query(l, mid, s, mid, T[p].lc),
		query(mid + 1, r, mid + 1, e, T[p].rc));
}

int main()
{
	int i, _a, _b, x, y;
	n = read(); m = read(); k = read();
	For (i, 1, k) a[i].l = read(), a[i].r = read(), a[i].p = read();
	For (i, 1, k) arr[(i << 1) - 1] = a[i].l, arr[i << 1] = a[i].r;
	std::sort(arr + 1, arr + (k << 1) + 1);
	tmp = std::unique(arr + 1, arr + (k << 1) + 1) - arr - 1;
	For (i, 1, k)
	{
		a[i].l = std::lower_bound(arr + 1, arr + tmp + 1, a[i].l) - arr;
		a[i].r = std::lower_bound(arr + 1, arr + tmp + 1, a[i].r) - arr;
	}
	std::sort(a + 1, a + k + 1, comp);
	For (i, 1, k)
	{
		ins(rt[i - 1], rt[i], 1, n, a[i].p, a[i].l);
		pos[a[i].r] = i;
	}
	For (i, 1, tmp) if (!pos[i]) pos[i] = pos[i - 1];
	while (m--)
	{
		_a = read(); _b = read(); x = read(); y = read();
		x = std::lower_bound(arr + 1, arr + tmp + 1, x) - arr;
		y = std::upper_bound(arr + 1, arr + tmp + 1, y) - arr - 1;
		puts(x > y || query(1, n, _a, _b, rt[pos[y]]) < x ? "no" : "yes");
		fflush(stdout);
	}
	return 0;
}