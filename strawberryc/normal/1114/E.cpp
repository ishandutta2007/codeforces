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

const int N = 1e6 + 5;

int n, m, val[N], ans;

int main()
{
	n = read();
	int l = 0, r = 1e9;
	while (l <= r)
	{
		int mid = l + r >> 1;
		printf("> %d\n", mid);
		fflush(stdout);
		if (read()) l = mid + 1;
		else r = mid - 1;
	}
	for (int i = 1; i <= 30; i++)
	{
		printf("? %d\n", 998244353ll * rand() % n + 1);
		fflush(stdout);
		val[++m] = read();
	}
	std::sort(val + 1, val + m + 1);
	ans = val[2] - val[1];
	for (int i = 3; i <= m; i++)
		ans = std::__gcd(ans, val[i] - val[i - 1]);
	std::cout << "! " << l - ans * (n - 1) << " " << ans << std::endl;
	return fflush(stdout), 0;
}