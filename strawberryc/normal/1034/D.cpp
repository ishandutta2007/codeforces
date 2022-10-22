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

typedef long long ll;

const int N = 3e5 + 5, INF = 1e9;

int n, k, a[N];
ll res, ans;

struct elem
{
	int l, r, col;
	
	friend inline bool operator < (elem a, elem b)
	{
		return a.l < b.l || (a.l == b.l && a.r < b.r);
	}
};

struct node
{
	int x, y;
};

std::vector<node> ft[N];
std::set<elem> orz;

void spl(int x)
{
	std::set<elem>::iterator it = orz.lower_bound((elem) {x + 1, 0, 0}); it--;
	elem tmp = *it; if (x == tmp.r) return;
	orz.erase(it); orz.insert((elem) {tmp.l, x, tmp.col});
	orz.insert((elem) {x + 1, tmp.r, tmp.col});
}

void split(int l, int r, int i)
{
	if (l > 1) spl(l - 1); spl(r);
	std::set<elem>::iterator it = orz.lower_bound((elem) {l, 0, 0});
	for (; it != orz.end() && it->r <= r;)
	{
		if (it->col) ft[i].push_back((node) {it->col, it->l - it->r - 1});
		std::set<elem>::iterator ti = it; ti++; orz.erase(it); it = ti;
	}
	ft[i].push_back((node) {i, r - l + 1});
	orz.insert((elem) {l, r, i});
}

ll calc(int mid)
{
	int it = 0, sum = 0; ll sumx = 0, res = 0; ans = 0;
	for (int i = 1; i <= n; i++) a[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < ft[i].size(); j++)
		{
			a[ft[i][j].x] += ft[i][j].y;
			if (ft[i][j].x < it) sumx += 1ll * ft[i][j].y * ft[i][j].x;
			else sum += ft[i][j].y, sumx += 1ll * ft[i][j].y * it;
		}
		while (it < i && sum - a[it] >= mid) sum -= a[it++], sumx += sum;
		res += it; ans += sumx;
	}
	return res;
}

int main()
{
	int l, r;
	read(n); read(k);
	orz.insert((elem) {1, INF, 0});
	for (int i = 1; i <= n; i++) read(l), read(r), split(l, r - 1, i);
	int L = 0, R = INF;
	while (L <= R)
	{
		int mid = L + R >> 1;
		if (calc(mid) >= k) L = mid + 1;
		else R = mid - 1;
	}
	return std::cout << (res = calc(R), ans) - (res - k) * R << std::endl, 0;
}