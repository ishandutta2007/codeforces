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

const int N = 105, M = 5e4 + 5, L = 4e6 + 5, rqy = 998244353, I2 = 499122177;
const ll ET = (1ll << 60) - 1;

int n, na, nb, ans;

struct seg
{
	int rt, lc[M], rc[M], dep[M], ToT;
	bool mark[M];
	ll num[M];
	
	void orznc(int T, ll l, ll r, ll s, ll e, ll x, int &p)
	{
		if (e < l || s > r) return;
		if (!p) dep[p = ++ToT] = T, num[p] = x;
		if (s <= l && r <= e) return (void) (mark[p] = 1);
		ll mid = l + r >> 1;
		orznc(T - 1, l, mid, s, e, x, lc[p]);
		orznc(T - 1, mid + 1, r, s, e, x | (1ll << T - 1), rc[p]);
	}
} A, B;

struct elem
{
	int dep; ll num;
} a[L];

inline bool comp(elem a, elem b)
{
	return a.num < b.num || (a.num == b.num && a.dep > b.dep);
}

int main()
{
	ll l, r, lst = -1; int d;
	read(na);
	while (na--) read(l), read(r), A.orznc(60, 0, ET - 1, l, r, 0, A.rt);
	read(nb);
	while (nb--) read(l), read(r), B.orznc(60, 0, ET - 1, l, r, 0, B.rt);
	for (int p = 1; p <= A.ToT; p++)
		for (int q = 1; q <= B.ToT; q++)
			if (A.dep[p] == B.dep[q] && (A.mark[p] || B.mark[q]))
			{
				int T = A.dep[p];
				a[++n] = (elem) {T, A.num[p] ^ B.num[q]};
			}
	std::sort(a + 1, a + n + 1, comp);
	for (int i = 1; i <= n; i++)
	{
		if (lst != -1 && d >= a[i].dep && (lst >> d) == (a[i].num >> d))
			continue;
		d = a[i].dep; lst = a[i].num;
		ans = (lst % rqy * ((1ll << d) % rqy) + ans) % rqy;
		ans = (((1ll << d) % rqy) * (((1ll << d) - 1) % rqy)
			% rqy * I2 + ans) % rqy;
	}
	return std::cout << ans << std::endl, 0;
}