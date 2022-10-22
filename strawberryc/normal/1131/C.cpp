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

const int N = 105;

int n, a[N];

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	std::sort(a + 1, a + n + 1);
	if (n & 1)
	{
		for (int i = 1; i <= n; i += 2) printf("%d ", a[i]);
		for (int i = n - 1; i >= 1; i -= 2) printf("%d ", a[i]);
	}
	else
	{
		for (int i = 1; i <= n; i += 2) printf("%d ", a[i]);
		for (int i = n; i >= 1; i -= 2) printf("%d ", a[i]);
	}
	std::cout << std::endl;
	return 0;
}