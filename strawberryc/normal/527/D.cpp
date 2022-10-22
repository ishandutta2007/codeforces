#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define p2 p << 1
#define p3 p << 1 | 1

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

const int N = 2e5 + 5, M = N << 1, L = M << 2;

int n, a[N], b[N], m, real[M], maxv[L], add[L];

struct node
{
	int x, w;
} st[N];

inline bool comp(node a, node b)
{
	return a.x < b.x;
}

void down(int p)
{
	add[p2] += add[p]; add[p3] += add[p];
	add[p] = 0;
}

void upt(int p)
{
	maxv[p] = Max(maxv[p2] + add[p2], maxv[p3] + add[p3]);
}

void change(int l, int r, int s, int e, int v, int p)
{
	if (l == s && r == e) return (void) (add[p] += v);
	int mid = l + r >> 1; down(p);
	if (e <= mid) change(l, mid, s, e, v, p2);
	else if (s >= mid + 1) change(mid + 1, r, s, e, v, p3);
	else change(l, mid, s, mid, v, p2),
		change(mid + 1, r, mid + 1, e, v, p3);
	upt(p);
}

void modify(int l, int r, int pos, int v, int p)
{
	if (l == r)
	{
		maxv[p] = Max(maxv[p] + add[p], v);
		return (void) (add[p] = 0);
	}
	int mid = l + r >> 1; down(p);
	if (pos <= mid) modify(l, mid, pos, v, p2);
	else modify(mid + 1, r, pos, v, p3);
	upt(p);
}

int ask(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return maxv[p] + add[p];
	int mid = l + r >> 1, res; down(p);
	if (e <= mid) res = ask(l, mid, s, e, p2);
	else if (s >= mid + 1) res = ask(mid + 1, r, s, e, p3);
	else res = Max(ask(l, mid, s, mid, p2),
		ask(mid + 1, r, mid + 1, e, p3));
	return upt(p), res;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		st[i].x = read(), st[i].w = read();
	std::sort(st + 1, st + n + 1, comp);
	for (int i = 1; i <= n; i++)
	{
		real[++m] = a[i] = st[i].x - st[i].w;
		real[++m] = b[i] = st[i].x + st[i].w;
	}
	std::sort(real + 1, real + m + 1);
	int tm = std::unique(real + 1, real + m + 1) - real - 1;
	m = tm;
	for (int i = 1; i <= n; i++)
	{
		a[i] = std::lower_bound(real + 1, real + m + 1, a[i]) - real;
		b[i] = std::lower_bound(real + 1, real + m + 1, b[i]) - real;
	}
	for (int i = 1; i <= n; i++)
	{
		modify(1, m, b[i], ask(1, m, 1, Min(a[i], b[i]), 1) + 1, 1);
		if (b[i] < a[i]) change(1, m, b[i] + 1, a[i], 1, 1);
	}
	std::cout << ask(1, m, 1, m, 1) << std::endl;
	return 0;
}