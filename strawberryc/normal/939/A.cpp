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

const int N = 5005;

int n, f[N], T, mark[N], th[N];
bool vis[N], ans;

int main()
{
	int i;
	n = read();
	For (i, 1, n) f[i] = read();
	For (i, 1, n)
	{
		if (vis[i]) continue;
		int u = i, tot = 0;
		T++;
		while (1)
		{
			if (vis[u])
			{
				if (mark[u] == T && tot - th[u] == 2) ans = 1;
				break;
			}
			vis[u] = 1;
			mark[u] = T; th[u] = ++tot;
			u = f[u];
		}
	}
	puts(ans ? "YES" : "NO");
	return 0;
}