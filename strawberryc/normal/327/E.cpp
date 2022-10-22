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

const int N = 26, C = (1 << 24) + 5, ZZQ = 1e9 + 7;

int n, a[N], k, b[N], f[C], sum[C], inx[C], Cm;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	k = read();
	for (int i = 1; i <= k; i++) b[i] = read();
	f[0] = 1;
	Cm = 1 << n;
	for (int i = 1; i <= n; i++) inx[1 << i - 1] = i;
	for (int S = 1; S < Cm; S++)
	{
		sum[S] = sum[S ^ (S & -S)] + a[inx[S & -S]];
		if (sum[S] == b[0] || sum[S] == b[1] || sum[S] == b[2])
			continue;
		for (int s = S; s; s ^= s & -s)
		{
			f[S] += f[S ^ (s & -s)];
			if (f[S] >= ZZQ) f[S] -= ZZQ;
		}
	}
	std::cout << f[Cm - 1] << std::endl;
	return 0;
}