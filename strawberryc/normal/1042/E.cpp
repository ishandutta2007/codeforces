#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e6 + 5, ZZQ = 998244353;

int n, m, f[N], inv[N];

struct node
{
	int x, y, val;
} a[N];

inline bool comp(node x, node y)
{
	return x.val < y.val;
}

int main()
{
	int i, j, tn = 0, r, c, p = 1, sum2 = 0, sumx = 0, sumy = 0, sum = 0;
	n = read(); m = read();
	For (i, 1, n) For (j, 1, m)
		c = read(), a[++tn] = {i, j, c};
	n = tn;
	std::sort(a + 1, a + n + 1, comp);
	r = read(); c = read();
	For (i, 1, n) if (a[i].x == r && a[i].y == c) n = i;
	inv[1] = 1;
	For (i, 2, n) inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	For (i, 1, n)
	{
		while (p < i && a[p].val < a[i].val)
		{
			sum2 = (1ll * a[p].x * a[p].x +
				1ll * a[p].y * a[p].y + sum2) % ZZQ;
			sumx = (sumx + a[p].x) % ZZQ;
			sumy = (sumy + a[p].y) % ZZQ;
			sum = (sum + f[p]) % ZZQ;
			p++;
		}
		int delta = (1ll * a[i].x * a[i].x +
			1ll * a[i].y * a[i].y) % ZZQ * (p - 1) % ZZQ;
		delta = (delta + sum2) % ZZQ;
		delta = (delta - 2ll * a[i].x * sumx % ZZQ + ZZQ) % ZZQ;
		delta = (delta - 2ll * a[i].y * sumy % ZZQ + ZZQ) % ZZQ;
		f[i] = 1ll * (delta + sum) * inv[p - 1] % ZZQ;
	}
	std::cout << f[n] << std::endl;
	return 0;
}