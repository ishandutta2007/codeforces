#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
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

const int N = 2e5 + 5, M = N << 2, E = 6, C = 35;

int n, k, a[N][E], q, Cm, tmp[E];

struct node
{
	int val[C], dis;
	
	friend inline node operator + (node a, node b)
	{
		int i;
		node res; res.dis = Max(a.dis, b.dis);
		For (i, 0, Cm)
		{
			res.val[i] = Max(a.val[i], b.val[i]);
			res.dis = Max(res.dis, a.val[i] + b.val[Cm ^ i]);
		}
		return res;
	}
} T[M];

node get_x(int *a)
{
	int i, S;
	node res; res.dis = 0;
	For (S, 0, Cm)
	{
		res.val[S] = 0;
		For (i, 1, k)
			if ((S >> i - 1) & 1) res.val[S] += a[i];
			else res.val[S] -= a[i];
	}
	return res;
}

void build(int l, int r, int p)
{
	if (l == r) return (void) (T[p] = get_x(a[l]));
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p] = T[p2] + T[p3];
}

void change(int l, int r, int pos, int *val, int p)
{
	if (l == r) return (void) (T[p] = get_x(val));
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, val, p2);
	else change(mid + 1, r, pos, val, p3);
	T[p] = T[p2] + T[p3];
}

node ask(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return T[p];
	int mid = l + r >> 1;
	if (e <= mid) return ask(l, mid, s, e, p2);
	else if (s >= mid + 1) return ask(mid + 1, r, s, e, p3);
	else return ask(l, mid, s, mid, p2)
		+ ask(mid + 1, r, mid + 1, e, p3);
}

int main()
{
	int i, j, x, y, op;
	n = read(); k = read();
	For (i, 1, n) For (j, 1, k) a[i][j] = read();
	Cm = (1 << k) - 1;
	build(1, n, 1);
	q = read();
	while (q--)
	{
		op = read(); x = read();
		if (op == 1)
		{
			For (i, 1, k) tmp[i] = read();
			change(1, n, x, tmp, 1);
		}
		else y = read(), printf("%d\n", ask(1, n, x, y, 1).dis);
	}
	return 0;
}