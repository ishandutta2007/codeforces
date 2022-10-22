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

int q;

int main()
{
	q = read();
	while (q--)
	{
		int x = read(), res = 0, tx = x;
		while (x) x >>= 1, res++; x = tx;
		if (x != (1 << res) - 1)
		    {printf("%d\n", (1 << res) - 1); continue;}
		int S = sqrt(x); res = 0;
		for (int i = 1; i <= S; i++)
		{
			if (x % i) continue;
			res = std::max(res, i);
			if (i > 1) res = std::max(res, x / i);
		}
		printf("%d\n", res);
	}
	return 0;
}