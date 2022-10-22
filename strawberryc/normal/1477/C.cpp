#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 5005;

int n, x[N], y[N];
bool vis[N];

ll dist(int i, int j)
{
	return 1ll * (x[i] - x[j]) * (x[i] - x[j]) + 1ll * (y[i] - y[j]) * (y[i] - y[j]);
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
	vis[1] = 1; printf("1 ");
	for (int i = 2, pre = 1; i <= n; i++)
	{
		ll cur = -1; int u;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dist(pre, j) > cur)
				cur = dist(pre, j), u = j;
		vis[pre = u] = 1; printf("%d ", pre);
	}
	return puts(""), 0;
}