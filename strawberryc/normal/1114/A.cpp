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
		res = (res << 3) + (res << 1) + (c - '0');
	return bo ? ~res + 1 : res;
}

int x, y, z, a, b, cc;

int main()
{
	std::cin >> x >> y >> z >> a >> b >> cc;
	if (x > a) return puts("NO"), 0; a -= x;
	if (y > a + b) return puts("NO"), 0; a -= y;
	if (z > a + b + cc) return puts("NO"), 0;
	puts("YES");
	return 0;
}