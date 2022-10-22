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

const int N = 105, M = 1e5 + 5;

int b, k, a[M], pw[M], ans;

int main()
{
	b = read(); k = read();
	for (int i = 1; i <= k; i++) a[i] = read() % 2;
	pw[0] = 1;
	for (int i = 1; i <= k; i++) pw[i] = b & 1;
	for (int i = 1; i <= k; i++)
		ans ^= a[i] & pw[k - i];
	puts(ans ? "odd" : "even");
	return 0;
}