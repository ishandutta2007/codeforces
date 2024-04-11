#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1005;

int n, m, ir[N], ic[N], a[N], ia[N], b[N], ib[N],
ans1x[N], ans1y[N], ans2x[N], ans2y[N];

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) ir[read()] = a[i] = ia[i] = i;
	for (int i = 1; i <= n; i++) ic[read()] = b[i] = ib[i] = i;
	for (int i = 1; i <= n; i++)
	{
		if (ir[i] == a[i] && ic[i] == b[i]) continue;
		int x = ia[ir[i]], y = ib[ic[i]];
		ans1x[++m] = x; ans1y[m] = ans2x[m] = i;
		ans2y[m] = y;
		a[x] = a[i]; b[y] = b[i];
		ia[a[i]] = x; ib[b[i]] = y;
	}
	std::cout << m << std::endl;
	for (int i = 1; i <= m; i++)
		printf("%d %d %d %d\n", ans1x[i], ans1y[i], ans2x[i], ans2y[i]);
	return 0;
}