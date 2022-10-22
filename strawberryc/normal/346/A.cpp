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

const int N = 105;

int n;

int main()
{
	int i, x, _max = 0, _gcd = 0;
	n = read();
	For (i, 1, n)
	{
		x = read();
		if (x > _max) _max = x;
		_gcd = std::__gcd(_gcd, x);
	}
	puts(_max / _gcd - n & 1 ? "Alice" : "Bob");
	return 0;
}