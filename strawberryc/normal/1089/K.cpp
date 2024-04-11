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

inline char get()
{
	char c;
	while ((c = getchar()) != '+' && c != '-' && c != '?');
	return c;
}

typedef long long ll;

const int M = 3e5 + 5, MAXN = 1e6, N = 4e6 + 5;

int q, t[M], d[M];

struct node
{
	int l, r; ll sum, tim;
	
	friend inline node operator + (node a, node b)
	{
		if (!a.sum && !b.sum) return (node) {a.l, b.r, 0, 0};
		if (!b.sum) return (node) {a.l, b.r, a.sum, a.tim};
		if (!a.sum) return (node) {a.l, b.r, b.sum, b.tim + a.r - a.l + 1};
		if (a.tim <= a.r - a.l + 1)
			return (node) {a.l, b.r, a.sum + b.sum, b.tim + a.r - a.l + 1};
		ll delta = a.tim - (a.r - a.l + 1), emp = b.tim - b.sum;
		if (delta <= emp)
			return (node) {a.l, b.r, a.sum + b.sum, b.tim + a.r - a.l + 1};
		return (node) {a.l, b.r, a.sum + b.sum,
			b.tim + a.r - a.l + 1 + delta - emp};
	}
} T[N];

void build(int l, int r, int p)
{
	T[p] = (node) {l, r, 0, 0};
	if (l == r) return;
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
}

void change(int l, int r, int pos, int v, int p)
{
	if (l == r) return (void) (T[p].sum += v, T[p].tim += v);
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, p2);
	else change(mid + 1, r, pos, v, p3);
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
	int i, x, y;
	char op;
	q = read();
	build(1, MAXN, 1);
	For (i, 1, q)
	{
		op = get(); x = read();
		if (op == '+')
		{
			t[i] = x; d[i] = y = read();
			change(1, MAXN, x, y, 1);
		}
		else if (op == '-') change(1, MAXN, t[x], -d[x], 1);
		else printf("%I64d\n",
			std::max(0ll, ask(1, MAXN, 1, x, 1).tim - x + 1));
	}
	return 0;
}