#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

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
inline void Swap(T &a, T &b) {a ^= b; b ^= a; a ^= b;}

const int N = 2e5 + 5, L = 1e6 + 5;

int n, m, a[N], b[N], c[N], d[N], tot, apia, A[N], ans[N];

struct node
{
	int op, x, y, z;
} q[L], que[L];

void clean(int x)
{
	for (; x <= n; x += x & -x)
		A[x] = 0;
}

void change(int x, int v)
{
	for (; x <= n; x += x & -x)
		A[x] += v;
}

int ask(int x)
{
	int res = 0;
	for (; x; x -= x & -x)
		res += A[x];
	return res;
}

void zzq_fenzhi(int l, int r)
{
	if (l == r) return;
	int mid = l + r >> 1, p = l, tot = 0;
	zzq_fenzhi(l, mid); zzq_fenzhi(mid + 1, r);
	for (int i = mid + 1; i <= r; i++)
	{
		while (p <= mid && q[p].x <= q[i].x)
		{
			if (!q[p].op) change(q[p].y, q[p].z);
			que[++tot] = q[p++];
		}
		que[++tot] = q[i];
		if (q[i].op)
		{
			if (q[i].op & 1) ans[q[i].op >> 1] -= ask(q[i].y);
			else ans[q[i].op >> 1] += ask(q[i].y);
		}
	}
	for (int i = l; i <= mid; i++) if (!q[i].op) clean(q[i].y);
	for (int i = p; i <= mid; i++) que[++tot] = q[i];
	for (int i = 1; i <= tot; i++) q[l + i - 1] = que[i];
}

int main()
{
	int la, ra, lb, rb, x, y, op;
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[read()] = i;
	for (int i = 1; i <= n; i++) c[i] = b[a[i]];
	for (int i = 1; i <= n; i++) d[c[i]] = i;
	for (int i = 1; i <= n; i++)
		q[++tot] = (node) {0, i, c[i], 1};
	while (m--)
	{
		op = read();
		if (op == 2)
		{
			x = read(); y = read();
			int tx = d[x], ty = d[y];
			Swap(d[x], d[y]); Swap(c[tx], c[ty]);
			q[++tot] = (node) {0, tx, x, -1};
			q[++tot] = (node) {0, ty, y, -1};
			q[++tot] = (node) {0, tx, y, 1};
			q[++tot] = (node) {0, ty, x, 1};
		}
		else
		{
			la = read(); ra = read(); lb = read(); rb = read();
			apia++;
			q[++tot] = (node) {apia << 1, ra, rb, 0};
			q[++tot] = (node) {apia << 1, la - 1, lb - 1, 0};
			q[++tot] = (node) {(apia << 1) + 1, ra, lb - 1, 0};
			q[++tot] = (node) {(apia << 1) + 1, la - 1, rb, 0};
		}
	}
	zzq_fenzhi(1, tot);
	for (int i = 1; i <= apia; i++)
		printf("%d\n", ans[i]);
	return 0;
}