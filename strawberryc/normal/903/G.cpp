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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 2e5 + 5, M = N << 2;

int n, m, q, a[N], ecnt, nxt[N], adj[N], go[N], val[N];
ll T[M], add[M], b[N], ioi[N];

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
}

void build(int l, int r, int p)
{
	add[p] = 0;
	if (l == r) return (void) (T[p] = b[l]);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p] = Min(T[p2], T[p3]);
}

void down(int p)
{
	add[p2] += add[p]; add[p3] += add[p];
	add[p] = 0;
}

void upt(int p)
{
	T[p] = Min(T[p2] + add[p2], T[p3] + add[p3]);
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

int main()
{
	int x, y, z;
	n = read(); m = read(); q = read();
	for (int i = 1; i < n; i++)
		a[i] = read(), b[i + 1] = read();
	while (m--) x = read(), y = read(), z = read(),
		add_edge(x, y, z);
	build(1, n, 1);
	for (int i = 1; i <= n; i++)
	{
		for (int e = adj[i], v = go[e]; e; e = nxt[e], v = go[e])
			change(1, n, 1, v, val[e], 1);
		ioi[i] = T[1] + add[1];
	}
	for (int i = 1; i <= n; i++) b[i] = a[i] + ioi[i];
	build(1, n, 1);
	std::cout << T[1] + add[1] << std::endl;
	while (q--)
	{
		x = read(); y = read();
		change(1, n, x, x, y - a[x], 1);
		a[x] = y;
		printf("%I64d\n", T[1] + add[1]);
	}
	return 0;
}