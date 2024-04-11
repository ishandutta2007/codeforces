#include <bits/stdc++.h>

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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 3e5 + 5, I = 1e9, L = 4e6 + 5;

int n, a[N], ToT, ri[N], rt, mn = I, f[N];

struct node
{
	int lc, rc, mx;
} T[L];

void change(int l, int r, int pos, int v, int &p)
{
	if (!p) p = ++ToT;
	T[p].mx = Max(T[p].mx, v);
	if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, T[p].lc);
	else change(mid + 1, r, pos, v, T[p].rc);
}

int ask(int l, int r, int s, int e, int p)
{
	if (!p || e < l || s > r || l > r) return 0;
	if (s <= l && r <= e) return T[p].mx;
	int mid = l + r >> 1;
	return Max(ask(l, mid, s, e, T[p].lc),
		ask(mid + 1, r, s, e, T[p].rc));
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), a[i + n] = a[i + n * 2] = a[i];
	for (int i = n * 3; i >= 1; i--)
	{
		ri[i] = ask(1, I, 1, (a[i] - 1) / 2, rt);
		change(1, I, a[i], I - i, rt);
		if (ri[i]) ri[i] = I - ri[i];
		if (ri[i] && ri[i] < mn) mn = ri[i];
		f[i] = mn == I ? -1 : mn - i;
	}
	for (int i = 1; i <= n; i++) printf("%d ", f[i]);
	return puts(""), 0;
}