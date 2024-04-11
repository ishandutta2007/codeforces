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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 2e5 + 5, M = N << 2, L = 4e7 + 5;

int n, lst[M], ToT;
ll lstans;

void change(int l, int r, int pos, int v, int p)
{
	if (l == r) return (void) (lst[p] = v);
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, p2);
	else change(mid + 1, r, pos, v, p3);
	lst[p] = Min(lst[p2], lst[p3]);
}

int mex(int l, int r, int x, int p)
{
	if (l == r) return lst[p] < x ? l : l + 1;
	int mid = l + r >> 1;
	return lst[p2] < x ? mex(l, mid, x, p2) : mex(mid + 1, r, x, p3);
}

struct node
{
	int lc, rc; ll add, sum;
} T[L];

std::vector<int> rt1[N], rt2[N], tm[N];

void ins(int y, int &x, int l, int r, int s, int e, ll v)
{
	if (e < l || s > r) return;
	T[x = ++ToT] = T[y]; T[x].sum += v * (Min(r, e) - Max(l, s) + 1);
	if (s <= l && r <= e) return (void) (T[x].add += v);
	int mid = l + r >> 1;
	ins(T[y].lc, T[x].lc, l, mid, s, e, v);
	ins(T[y].rc, T[x].rc, mid + 1, r, s, e, v);
}

ll query(int l, int r, int s, int e, int p)
{
	if (e < l || s > r) return 0;
	if (s <= l && r <= e) return T[p].sum;
	int mid = l + r >> 1;
	return query(l, mid, s, e, T[p].lc)
		+ query(mid + 1, r, s, e, T[p].rc) + T[p].add * (Min(r, e) - Max(l, s) + 1);
}

void addint(int k, int l, int r, ll v, int i)
{
	int pre1 = rt1[k][rt1[k].size() - 1], pre2 = rt2[k][rt2[k].size() - 1],
		nxt1 = 0, nxt2 = 0;
	ins(pre1, nxt1, 1, n, l, r, v); ins(pre2, nxt2, 1, n, l, r, v * (1 - i));
	rt1[k].push_back(nxt1); rt2[k].push_back(nxt2); tm[k].push_back(i);
}

ll queryans(int k, int l, int r)
{
	int th = std::upper_bound(tm[k].begin(), tm[k].end(), r) - tm[k].begin() - 1;
	return query(1, n, l, r, rt1[k][th]) * r + query(1, n, l, r, rt2[k][th]);
}

struct elem
{
	int k, l, r;
	
	friend inline bool operator < (elem a, elem b)
	{
		return a.k < b.k;
	}
};

std::set<elem> orz;

int main()
{
	int a, l, r, k;
	read(n);
	for (int i = 0; i <= n; i++) rt1[i].push_back(0), rt2[i].push_back(0),
		tm[i].push_back(0);
	for (int i = 1; i <= n; i++)
	{
		read(a); read(l); read(r); read(k);
		a = (a + lstans) % (n + 1); l = (l + lstans) % i + 1;
		r = (r + lstans) % i + 1; k = (k + lstans) % (n + 1);
		if (l > r) std::swap(l, r);
		std::set<elem>::iterator it = orz.lower_bound((elem) {a, 0, 0});
		change(0, n, a, i, 1);
		if (it != orz.end() && it->k == a)
		{
			int L = it->l, R = it->r; std::set<elem>::iterator ti = it; ti++;
			addint(a, L, R, -1, i);
			orz.erase(it); int ft = ti == orz.end() ? 20050131 : ti->k, pl;
			if (ti != orz.end()) pl = ti->l;
			while (L <= R)
			{
				int l = L, r = R, cur = mex(0, n, r, 1);
				while (l <= r)
				{
					int mid = l + r >> 1;
					if (mex(0, n, mid, 1) > cur) l = mid + 1;
					else r = mid - 1;
				}
				if (ft > cur) orz.insert((elem) {cur, r + 1, R});
				else orz.erase(ti), orz.insert((elem) {cur, pl, R});
				addint(cur, r + 1, R, 1, i); R = r;
			}
		}
		int cur = a == 0, pl; addint(cur, i, i, 1, i);
		if (orz.empty() || orz.begin()->k > cur) orz.insert((elem) {cur, i, i});
		else pl = orz.begin()->l, orz.erase(orz.begin()),
			orz.insert((elem) {cur, pl, i});
		printf("%lld\n", lstans = queryans(k, l, r));
	}
	return 0;
}