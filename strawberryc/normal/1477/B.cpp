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

const int N = 2e5 + 5, M = N << 2;

int n, q, l[N], r[N], T[M], tag[M];
char s[N], f[N];

void build(int l, int r, int p)
{
	tag[p] = -1;
	if (l == r) return (void) (T[p] = f[l] - '0');
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p] = T[p2] + T[p3];
}

void down(int l, int r, int mid, int p)
{
	if (tag[p] != -1)
	{
		tag[p2] = tag[p]; tag[p3] = tag[p];
		T[p2] = tag[p] * (mid - l + 1);
		T[p3] = tag[p] * (r - mid);
		tag[p] = -1;
	}
}

void change(int l, int r, int s, int e, int v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return (void) (tag[p] = v, T[p] = v * (r - l + 1));
	int mid = l + r >> 1; down(l, r, mid, p);
	change(l, mid, s, e, v, p2); change(mid + 1, r, s, e, v, p3);
	T[p] = T[p2] + T[p3];
}

int ask(int l, int r, int s, int e, int p)
{
	if (e < l || s > r) return 0;
	if (s <= l && r <= e) return T[p];
	int mid = l + r >> 1; down(l, r, mid, p);
	return ask(l, mid, s, e, p2) + ask(mid + 1, r, s, e, p3);
}

void work()
{
	read(n); read(q);
	scanf("%s%s", s + 1, f + 1);
	for (int i = 1; i <= q; i++) read(l[i]), read(r[i]);
	build(1, n, 1);
	for (int i = q; i >= 1; i--)
	{
		int len = r[i] - l[i] + 1, c = ask(1, n, l[i], r[i], 1);
		if ((c << 1) == len) return (void) puts("NO");
		change(1, n, l[i], r[i], (c << 1) > len, 1);
	}
	for (int i = 1; i <= n; i++) if (ask(1, n, i, i, 1) + '0' != s[i])
		return (void) puts("NO");
	puts("YES");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}