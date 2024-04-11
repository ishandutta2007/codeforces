#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define p2 p << 1
#define p3 p << 1 | 1
using namespace std;

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

typedef long long ll;

template <class T>
T Max(T a, T b) {return a > b ? a : b;}

const int N = 1e5 + 5, M = N << 2;
int n, m, a[N], smax[M];
ll sum[M];

void upt(int p)
{
	sum[p] = sum[p2] + sum[p3];
	smax[p] = Max(smax[p2], smax[p3]);
}

void build(int l, int r, int p)
{
	if (l == r) return (void) (sum[p] = smax[p] = a[l]);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	upt(p);
}

void change(int l, int r, int pos, int v, int p)
{
	if (l == r) return (void) (sum[p] = smax[p] = v);
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, p2);
	else change(mid + 1, r, pos, v, p3);
	upt(p);
}

void modify(int l, int r, int s, int e, int v, int p)
{
	if (l == r) return (void) (sum[p] %= v, smax[p] %= v);
	if (l == s && r == e && smax[p] < v) return;
	int mid = l + r >> 1;
	if (e <= mid) modify(l, mid, s, e, v, p2);
	else if (s >= mid + 1) modify(mid + 1, r, s, e, v, p3);
	else modify(l, mid, s, mid, v, p2),
		modify(mid + 1, r, mid + 1, e, v, p3);
	upt(p);
}

ll ask(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return sum[p];
	int mid = l + r >> 1;
	if (e <= mid) return ask(l, mid, s, e, p2);
	else if (s >= mid + 1) return ask(mid + 1, r, s, e, p3);
	else return ask(l, mid, s, mid, p2)
		+ ask(mid + 1, r, mid + 1, e, p3);
}

int main()
{
	int i, op, x, y, z;
	n = read(); m = read();
	For (i, 1, n) a[i] = read();
	build(1, n, 1);
	while (m--)
	{
		op = read(); x = read(); y = read();
		if (op == 3) change(1, n, x, y, 1);
		else if (op == 2) z = read(), modify(1, n, x, y, z, 1);
		else printf("%lld\n", ask(1, n, x, y, 1));
	}
	return 0;
}