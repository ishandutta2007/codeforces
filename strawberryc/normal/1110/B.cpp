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

const int N = 1e5 + 5;

int n, m, k, b[N], ans, a[N];

inline bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	n = read(); m = read(); k = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	ans = b[n] - b[1] + 1;
	for (int i = 1; i < n; i++) a[i] = b[i + 1] - b[i] - 1;
	std::sort(a + 1, a + n, comp);
	for (int i = 1; i <= k - 1; i++) ans -= a[i];
	std::cout << ans << std::endl;
	return 0;
}