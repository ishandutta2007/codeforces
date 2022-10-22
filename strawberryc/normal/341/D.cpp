#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Bitr(x, n) for (; x <= n; x += x & -x)
#define Bitl(x) for (; x; x -= x & -x)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

typedef long long ll;

inline ll readll()
{
	ll res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1005;

int n, m;
ll A[4][N][N];

int which(int x, int y) {return ((x << 1) ^ (y & 1)) & 3;}

void change(int x, int y, ll v)
{
	int o = which(x, y);
	Bitr(x, n)
	{
		int z = y;
		Bitr(z, n) A[o][x][z] ^= v;
	}
}

ll ask(int x, int y)
{
	int o = which(x, y);
	ll res = 0;
	Bitl(x)
	{
		int z = y;
		Bitl(z) res ^= A[o][x][z];
	}
	return res;
}

int main()
{
	int i, op, xl, yl, xr, yr; ll x;
	n = read(); m = read();
	while (m--)
	{
		op = read(); xl = read(); yl = read();
		xr = read(); yr = read();
		if (op == 2)
		{
			x = readll();
			change(xl, yl, x);
			change(xl, yr + 1, x);
			change(xr + 1, yl, x);
			change(xr + 1, yr + 1, x);
		}
		else printf("%I64d\n",
			ask(xr, yr) ^ ask(xl - 1, yr) ^ ask(xr, yl - 1)
			^ ask(xl - 1, yl - 1));
	}
	return 0;
}