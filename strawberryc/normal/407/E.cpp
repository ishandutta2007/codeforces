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

const int N = 3e5 + 5, M = N << 2;

int n, rqy, q, a[N], ans, ansl, ansr, stk1[N], top1, stk2[N], top2;
ll mx[M], add[M];

std::map<int, int> orz;

void build(int l, int r, int p)
{
	mx[p] = add[p] = 0;
	if (l == r) return;
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
}

void down(int p)
{
	add[p2] += add[p]; mx[p2] += add[p];
	add[p3] += add[p]; mx[p3] += add[p];
	add[p] = 0;
}

void change(int l, int r, int s, int e, ll v, int p)
{
	if (e < l || s > r) return;
	if (s <= l && r <= e) return (void) (mx[p] += v, add[p] += v);
	int mid = l + r >> 1; down(p);
	change(l, mid, s, e, v, p2); change(mid + 1, r, s, e, v, p3);
	mx[p] = Min(mx[p2], mx[p3]);
}

int query(int l, int r, ll v, int p)
{
	if (l == r) return l;
	int mid = l + r >> 1; down(p);
	if (mx[p2] <= v) return query(l, mid, v, p2);
	else return query(mid + 1, r, v, p3);
}

int first(int l, int r, int s, int e, ll v, int p)
{
	if (e < l || s > r) return 0;
	if (s <= l && r <= e) return mx[p] <= v ? query(l, r, v, p) : 0;
	int mid = l + r >> 1; down(p);
	int tmp = first(l, mid, s, e, v, p2);
	return tmp ? tmp : first(mid + 1, r, s, e, v, p3);
}

void jiejuediao(int L, int R)
{
	orz.clear();
	top1 = top2 = 0; build(L, R, 1);
	int lst = L - 1; stk1[0] = stk2[0] = L - 1;
	for (int i = L; i <= R; i++)
	{
		while (top1 && a[stk1[top1]] > a[i])
		{
			change(L, R, stk1[top1 - 1] + 1, stk1[top1], a[stk1[top1]], 1);
			top1--;
		}
		stk1[++top1] = i;
		change(L, R, stk1[top1 - 1] + 1, stk1[top1], -a[i], 1);
		while (top2 && a[stk2[top2]] < a[i])
		{
			change(L, R, stk2[top2 - 1] + 1, stk2[top2], -a[stk2[top2]], 1);
			top2--;
		}
		stk2[++top2] = i;
		change(L, R, stk2[top2 - 1] + 1, stk2[top2], a[i], 1);
		change(L, R, i, i, 1ll * rqy * i, 1);
		if (orz.count(a[i])) lst = Max(lst, orz[a[i]]);
		orz[a[i]] = i;
		int lef = first(L, R, lst + 1, i, 1ll * rqy * (i + q), 1);
		if (i - lef + 1 > ans || (i - lef + 1 == ans && lef < ansl))
			ans = i - lef + 1, ansl = lef, ansr = i;
	}
}

int main()
{
	read(n); read(q); read(rqy);
	for (int i = 1; i <= n; i++) read(a[i]);
	if (rqy == 0)
	{
		for (int i = 1, j = 1; i <= n; i++)
		{
			if (i > 1 && a[i] != a[i - 1]) j = i;
			if (i - j + 1 > ans) ans = i - j + 1, ansl = j, ansr = i;
		}
		std::cout << ansl << " " << ansr << std::endl;
		return 0;
	}
	for (int i = 1; i <= n;)
	{
		int nxt = i;
		while (nxt <= n && (nxt == i || ((a[nxt] % rqy + rqy) % rqy ==
			(a[nxt - 1] % rqy + rqy) % rqy))) nxt++;
		jiejuediao(i, nxt - 1); i = nxt;
	}
	return std::cout << ansl << " " << ansr << std::endl, 0;
}