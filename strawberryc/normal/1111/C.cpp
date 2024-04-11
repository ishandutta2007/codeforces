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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 4e6 + 5;

int n, k, a, b, ToT, Root;

struct node
{
	int lc, rc, sum;
	ll val;
} T[N];

void upt(int l, int r, int p)
{
	ll ls = T[p].lc ? T[T[p].lc].val : a,
		rs = T[p].rc ? T[T[p].rc].val : a;
	T[p].sum = T[T[p].lc].sum + T[T[p].rc].sum;
	T[p].val = Min(1ll * b * T[p].sum * (r - l + 1), ls + rs);
}

void change(int l, int r, int pos, int v, int &p)
{
	if (!p) p = ++ToT;
	if (l == r)
	{
		T[p].sum += v;
		T[p].val = 1ll * b * T[p].sum;
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, T[p].lc);
	else change(mid + 1, r, pos, v, T[p].rc);
	upt(l, r, p);
}

int main()
{
	n = read(); k = read(); a = read(); b = read();
	while (k--) change(1, 1 << n, read(), 1, Root);
	std::cout << T[1].val << std::endl;
	return 0;
}