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

const int N = 5e5 + 5, M = 4e6 + 17, L = 1e6;

int n, q, a[N], add[M], pts[M];
bool is[M];

struct elem
{
	int val, cnt;
	
	friend inline elem operator + (elem a, elem b)
	{
		if (a.val < b.val) return a;
		else if (a.val > b.val) return b;
		return (elem) {a.val, a.cnt + b.cnt};
	}
} T[M];

void build(int l, int r, int p)
{
	T[p].val = add[p] = 0;
	if (l == r) return (void) (T[p].cnt = pts[p] = is[l]);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p].cnt = pts[p] = pts[p2] + pts[p3];
}

void down(int p)
{
	add[p2] += add[p]; add[p3] += add[p];
	T[p2].val += add[p]; T[p3].val += add[p];
	add[p] = 0;
}

void modify(int l, int r, int pos, int v, int p)
{
	if (l == r) return (void) (pts[p] += v, T[p].cnt += v);
	int mid = l + r >> 1; down(p);
	if (pos <= mid) modify(l, mid, pos, v, p2);
	else modify(mid + 1, r, pos, v, p3);
	T[p] = T[p2] + T[p3];
}

void change(int l, int r, int s, int e, int v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return (void) (add[p] += v, T[p].val += v);
	int mid = l + r >> 1; down(p);
	change(l, mid, s, e, v, p2); change(mid + 1, r, s, e, v, p3);
	T[p] = T[p2] + T[p3];
}

elem ask(int l, int r, int s, int e, int p)
{
	if (e < l || s > r) return (elem) {-1, 0};
	if (s <= l && r <= e) return T[p];
	int mid = l + r >> 1; down(p);
	return ask(l, mid, s, e, p2) + ask(mid + 1, r, s, e, p3);
}

int main()
{
	int pos, x; read(n); read(q);
	for (int i = 1; i <= n; i++) read(a[i]), is[a[i]] = 1;
	build(1, L, 1);
	for (int i = 1; i < n; i++) if (a[i] < a[i + 1])
		change(1, L, a[i] + 1, a[i + 1], 1, 1);
	while (q--)
	{
		read(pos); read(x);
		modify(1, L, a[pos], -1, 1); modify(1, L, x, 1, 1);
		if (pos > 1)
		{
			if (a[pos - 1] < a[pos]) change(1, L, a[pos - 1] + 1, a[pos], -1, 1);
			if (a[pos - 1] < x) change(1, L, a[pos - 1] + 1, x, 1, 1);
		}
		if (pos < n)
		{
			if (a[pos] < a[pos + 1]) change(1, L, a[pos] + 1, a[pos + 1], -1, 1);
			if (x < a[pos + 1]) change(1, L, x + 1, a[pos + 1], 1, 1);
		}
		a[pos] = x; printf("%d\n", T[1].val ? 0 : T[1].cnt);
	}
	return 0;
}