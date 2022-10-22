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
	int l, r;
	q = read();
	while (q--)
	{
		l = read(); r = read();
		int res = l & 1 ? r - l + 1 >> 1 : - (r - l + 1 >> 1);
		if (!(r - l & 1))
		{
			if (r & 1) res -= r;
			else res += r;
		}
		printf("%d\n", res);
	}
	return 0;
}