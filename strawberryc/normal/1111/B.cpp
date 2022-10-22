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

const int N = 1e5 + 5;

int n, k, m, a[N];
double ans;
ll sum[N];

int main()
{
	n = read(); k = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	std::sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) sum[i] = sum[i + 1] + a[i];
	for (int i = 1; i <= n; i++)
	{
		int cnt = m - (i - 1);
		if (cnt < 0) continue;
		int x = n - i + 1, delta = std::min(1ll * cnt, 1ll * x * k);
		ans = std::max(ans, 1.0 * (sum[i] + delta) / x);
	}
	printf("%.12lf\n", ans);
	return 0;
}