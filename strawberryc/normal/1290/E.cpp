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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 15e4 + 5, M = 6e5 + 5, INF = 0x3f3f3f3f;

int n, p[N], A[N];

void change(int x, int v)
{
	for (; x <= n; x += x & -x)
		A[x] += v;
}

int ask(int x)
{
	int res = 0;
	for (; x; x -= x & -x) res += A[x];
	return res;
}

struct elem
{
	int mx, cnt, md;
	
	friend inline elem operator + (elem a, elem b)
	{
		elem res;
		if (a.mx > b.mx) res = a, res.md = Max(a.md, b.mx);
		else if (a.mx < b.mx) res = b, res.md = Max(a.mx, b.md);
		else res = a, res.cnt = a.cnt + b.cnt, res.md = Max(a.md, b.md);
		return res;
	}
};

struct seg
{
	elem T[M]; int add[M], tag[M], cnt[M]; ll sum[M];
	
	void build(int l, int r, int p)
	{
		T[p] = (elem) {-INF, 0, -INF}; add[p] = 0; tag[p] = INF;
		if (l == r) return;
		int mid = l + r >> 1;
		build(l, mid, p2); build(mid + 1, r, p3);
	}
	
	void down(int p)
	{
		T[p2].mx += add[p]; T[p2].md += add[p]; sum[p2] += 1ll * cnt[p2] * add[p];
		add[p2] += add[p]; tag[p2] += add[p];
		T[p3].mx += add[p]; T[p3].md += add[p]; sum[p3] += 1ll * cnt[p3] * add[p];
		add[p3] += add[p]; tag[p3] += add[p];
		if (tag[p] < T[p2].mx) sum[p2] -= 1ll * T[p2].cnt * (T[p2].mx - tag[p]),
			tag[p2] = T[p2].mx = tag[p];
		if (tag[p] < T[p3].mx) sum[p3] -= 1ll * T[p3].cnt * (T[p3].mx - tag[p]),
			tag[p3] = T[p3].mx = tag[p];
		add[p] = 0; tag[p] = INF;
	}
	
	void upt(int p)
	{
		cnt[p] = cnt[p2] + cnt[p3]; sum[p] = sum[p2] + sum[p3];
		T[p] = T[p2] + T[p3];
	}
	
	void unlock(int l, int r, int pos, int v, int p)
	{
		if (l == r) return (void) (cnt[p] = T[p].cnt = 1, T[p].mx = sum[p] = v);
		int mid = l + r >> 1; down(p);
		if (pos <= mid) unlock(l, mid, pos, v, p2);
		else unlock(mid + 1, r, pos, v, p3);
		upt(p);
	}
	
	void change(int l, int r, int s, int e, int v, int p)
	{
		if (e < l || s > r) return;
		if (s <= l && r <= e) return (void) (add[p] += v, tag[p] += v,
			T[p].mx += v, T[p].md += v, sum[p] += 1ll * cnt[p] * v);
		int mid = l + r >> 1; down(p);
		change(l, mid, s, e, v, p2); change(mid + 1, r, s, e, v, p3);
		upt(p);
	}
	
	void modify(int l, int r, int s, int e, int v, int p)
	{
		if (e < l || s > r) return;
		if (s <= l && r <= e && v > T[p].md)
		{
			if (v < T[p].mx) sum[p] -= 1ll * T[p].cnt * (T[p].mx - v),
				tag[p] = T[p].mx = v;
			return;
		}
		int mid = l + r >> 1; down(p);
		modify(l, mid, s, e, v, p2); modify(mid + 1, r, s, e, v, p3);
		upt(p);
	}
} T1, T2;

int main()
{
	int x;
	read(n);
	for (int i = 1; i <= n; i++) read(x), p[x] = i;
	T1.build(1, n, 1); T2.build(1, n, 1);
	for (int i = 1; i <= n; i++)
	{
		change(p[i], 1); int c = ask(p[i]);
		T1.modify(1, n, 1, p[i], c, 1); T1.change(1, n, p[i], n, 1, 1);
		T2.modify(1, n, p[i], n, i - c + 1, 1); T2.change(1, n, 1, p[i], 1, 1);
		T1.unlock(1, n, p[i], i + 1, 1); T2.unlock(1, n, p[i], i + 1, 1);
		printf("%lld\n", T1.sum[1] + T2.sum[1] - 1ll * i * (i + 2));
	}
	return 0;
}