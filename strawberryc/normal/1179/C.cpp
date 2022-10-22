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

const int N = 3e5 + 5, M = 4e6 + 5;

int n, m, a[N], b[N], q, val[M], sum[M], minsuf[M];

void build(int l, int r, int p)
{
	if (l == r) return (void) (sum[p] = minsuf[p] = val[l]);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	sum[p] = sum[p2] + sum[p3];
	minsuf[p] = std::min(minsuf[p3], minsuf[p2] + sum[p3]);
}

void change(int l, int r, int pos, int v, int p)
{
	if (l == r) return (void) (sum[p] += v, minsuf[p] += v);
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, p2);
	else change(mid + 1, r, pos, v, p3);
	sum[p] = sum[p2] + sum[p3];
	minsuf[p] = std::min(minsuf[p3], minsuf[p2] + sum[p3]);
}

int ask(int l, int r, int bas, int p)
{
	if (l == r) return sum[p] + bas < 0 ? l : -1;
	int mid = l + r >> 1;
	if (minsuf[p3] + bas < 0) return ask(mid + 1, r, bas, p3);
	else return ask(l, mid, bas + sum[p3], p2);
}

int main()
{
	int op, i, x;
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i]), val[a[i]]--;
	for (int i = 1; i <= m; i++) read(b[i]), val[b[i]]++;
	build(1, 1000000, 1);
	read(q);
	while (q--)
	{
		read(op); read(i); read(x);
		if (op == 1) change(1, 1000000, a[i], 1, 1),
			change(1, 1000000, x, -1, 1), a[i] = x;
		else change(1, 1000000, b[i], -1, 1),
			change(1, 1000000, x, 1, 1), b[i] = x;
		printf("%d\n", ask(1, 1000000, 0, 1));
	}
	return 0;
}