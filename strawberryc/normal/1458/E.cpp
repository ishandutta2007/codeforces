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

const int N = 2e5 + 5, L = 1e7 + 5, INF = 1e9 + 1e7;

int n, m, q, cnt, ToT, rt;
std::map<int, int> curs;
bool ans[N];

struct elem
{
	int x, y, i; bool ty;
} a[N];

struct node
{
	int lc, rc, sum;
} T[L];

int change(int l, int r, int pos, int &p)
{
	if (!p) p = ++ToT;
	if (l == r) return !T[p].sum ? ++T[p].sum : 0;
	int mid = l + r >> 1, res;
	if (pos <= mid) res = change(l, mid, pos, T[p].lc);
	else res = change(mid + 1, r, pos, T[p].rc);
	T[p].sum = T[T[p].lc].sum + T[T[p].rc].sum;
	return res;
}

int getmex(int l, int r, int cnt, int p)
{
	if (l == r) return l;
	int mid = l + r >> 1, delta = mid - l + 1 - T[T[p].lc].sum;
	if (cnt <= delta) return getmex(l, mid, cnt, T[p].lc);
	else return getmex(mid + 1, r, cnt - delta, T[p].rc);
}

int main()
{
	int x, y;
	read(n); read(m);
	for (int i = 1; i <= n; i++)
		read(x), read(y), a[++q] = (elem) {x, y, i, 0};
	for (int i = 1; i <= m; i++)
		read(x), read(y), a[++q] = (elem) {x, y, i, 1};
	std::sort(a + 1, a + q + 1, [&](elem u, elem v)
		{return u.x < v.x;});
	a[0].x = -1;
	for (int le = 1; le <= q;)
	{
		int ri = le; bool is = 0;
		while (ri <= q && a[le].x == a[ri].x)
			is |= !a[ri].ty, ri++;
		int dx = a[le].x - a[le - 1].x - is; curs.clear(); cnt += dx;
		if (is)
		{
			int nxt = getmex(0, INF, cnt + 1, rt);
			bool lef = 1;
			for (int i = le; i < ri; i++)
				if (!a[i].ty && a[i].y <= nxt) lef = 0;
			if (lef)
			{
				cnt++; curs[nxt] = 1;
				for (int i = le; i < ri; i++)
					if (!a[i].ty) change(0, INF, a[i].y, rt);
			}
			else for (int i = le; i < ri; i++)
			{
				if (!a[i].ty)
					cnt -= change(0, INF, a[i].y, rt) && a[i].y < nxt;
			}
			for (int i = le; i < ri; i++) if (!a[i].ty) curs[a[i].y] = 1;
		}
		else curs[getmex(0, INF, cnt, rt)] = 1;
		for (int i = le; i < ri; i++)
			if (a[i].ty) ans[a[i].i] = !curs[a[i].y];
		le = ri;
	}
	for (int i = 1; i <= m; i++) puts(ans[i] ? "WIN" : "LOSE");
	return 0;
}