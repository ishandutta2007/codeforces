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
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

const int N = 5e5 + 5, M = 25;

int n, a[N], q, ans[N], bas[M], pos[M];

struct query
{
	int l, r, id;
} que[N];

inline bool comp(query a, query b)
{
	return a.r < b.r;
}

void ins(int x, int id)
{
	for (int i = 20; i >= 0; i--)
	{
		if (!((x >> i) & 1)) continue;
		if (bas[i] == -1) return (void) (bas[i] = x, pos[i] = id);
		else
		{
			if (pos[i] < id) Swap(pos[i], id), Swap(bas[i], x);
			x ^= bas[i];
		}
	}
}

int maxxor(int l)
{
	int res = 0;
	for (int i = 20; i >= 0; i--)
		if (bas[i] != -1 && pos[i] >= l && (res ^ bas[i]) > res)
			res ^= bas[i];
	return res;
}

int main()
{
	memset(bas, -1, sizeof(bas));
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	q = read();
	for (int i = 1; i <= q; i++)
		que[i].l = read(), que[i].r = read(), que[i].id = i;
	std::sort(que + 1, que + q + 1, comp);
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		ins(a[i], i);
		while (p <= q && que[p].r <= i)
			ans[que[p].id] = maxxor(que[p].l), p++;
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}