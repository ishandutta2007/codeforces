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

typedef long long ll;

const int N = 1e5 + 10;

int n;
ll a[N], b[N];

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	for (int i = n; i >= 1; i--) a[i] -= a[i - 1], b[i] -= b[i - 1];
	std::sort(a + 2, a + n + 1);
	std::sort(b + 2, b + n + 1);
	for (int i = 1; i <= n; i++) if (a[i] != b[i])
		return puts("No"), 0;
	puts("Yes");
	return 0;
}