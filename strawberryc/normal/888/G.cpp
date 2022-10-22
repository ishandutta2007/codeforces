#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)

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

const int N = 2e5 + 5, M = 8e6 + 5;

int n, a[N], ToT;

int xth1(int l, int r, int x)
{
	while (l <= r)
	{
		int mid = l + r >> 1;
		if ((a[mid] >> x) & 1) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}

struct node
{
	int lc, rc;
	
	void init()
	{
		lc = rc = 0;
	}
} T[M];

void ins(int num)
{
	int i, u = 1;
	Rof (i, 30, 0)
	{
		int x = (num >> i) & 1;
		if (x)
		{
			if (!T[u].rc) T[T[u].rc = ++ToT].init();
			u = T[u].rc;
		}
		else
		{
			if (!T[u].lc) T[T[u].lc = ++ToT].init();
			u = T[u].lc;
		}
	}
}

int minxor(int num)
{
	int i, res = 0, u = 1;
	Rof (i, 30, 0)
	{
		int x = (num >> i) & 1;
		if ((x && T[u].rc) || (!x && T[u].lc))
			u = x ? T[u].rc : T[u].lc;
		else u = x ? T[u].lc : T[u].rc, res |= 1 << i;
	}
	return res;
}

ll jiejuediao(int l, int r, int x)
{
	if (l > r || x == -1) return 0;
	int i, j, mid = xth1(l, r, x); ll res;
	res = jiejuediao(l, mid - 1, x - 1) + jiejuediao(mid, r, x - 1);
	if (mid != l && mid != r + 1)
	{
		T[ToT = 1].init();
		For (i, l, mid - 1) ins(a[i]);
		int delta = 2147483647;
		For (i, mid, r) delta = Min(delta, minxor(a[i]));
		res += delta;
	}
	return res;
}

int main()
{
	int i;
	n = read();
	For (i, 1, n) a[i] = read();
	std::sort(a + 1, a + n + 1);
	std::cout << jiejuediao(1, n, 30) << std::endl;
	return 0;
}