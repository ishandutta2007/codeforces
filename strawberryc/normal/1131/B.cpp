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

const int N = 1e4 + 5;

int n, a[N], b[N], ans;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read();
	for (int i = 0; i < n; i++)
	{
		int l = std::max(a[i], b[i]), r = std::min(a[i + 1], b[i + 1]);
		if (l <= r) ans += r - l + 1;
	}
	for (int i = 1; i < n; i++) if (a[i] == b[i]) ans--;
	std::cout << ans << std::endl;
	return 0;
}