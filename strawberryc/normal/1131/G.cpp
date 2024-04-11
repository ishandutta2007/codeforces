#include <bits/stdc++.h>

// 20030830

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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 1e7 + 5, M = 25e4 + 5;
const ll INF = 1e18;

int m, n, q, len[M], a[N], tol[N], tor[N], top, stk[N], fa[N], cnt[N];
ll w[N], f[N], vt[N];

std::vector<int> h[M], c[M];

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

void zm(int x, int y)
{
	int ix = cx(x), iy = cx(y);
	if (ix != iy) fa[iy] = ix;
}

int main()
{
	m = read(); read();
	for (int i = 1; i <= m; i++)
	{
		len[i] = read();
		for (int j = 0; j < len[i]; j++)
			h[i].push_back(read());
		for (int j = 0; j < len[i]; j++)
			c[i].push_back(read());
	}
	q = read();
	while (q--)
	{
		int id = read(), mul = read();
		for (int i = 0; i < len[id]; i++)
			a[++n] = h[id][i], w[n] = 1ll * c[id][i] * mul, fa[n] = n;
	}
	for (int i = 1; i <= n; i++)
	{
		int wt = Max(1, i - a[i] + 1);
		tol[i] = wt == i ? i : tol[cx(wt)];
		while (top && tol[stk[top]] >= tol[i]) zm(i, stk[top--]);
		stk[++top] = i;
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	top = 0;
	for (int i = n; i >= 1; i--)
	{
		int wt = Min(n, i + a[i] - 1);
		tor[i] = wt == i ? i : tor[cx(wt)];
		while (top && tor[stk[top]] <= tor[i]) zm(i, stk[top--]);
		cnt[tor[stk[++top] = i]]++;
	}
	vt[top = 0] = INF;
	for (int i = 1; i <= n; i++)
	{
		top++;
		vt[top] = Min(vt[top - 1], f[i - 1] + w[i]);
		f[i] = Min(vt[top], f[tol[i] - 1] + w[i]);
		while (cnt[i]--) top--;
	}
	std::cout << f[n] << std::endl;
	return 0;
}