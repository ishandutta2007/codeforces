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

const int N = 55;

int n, x[N];
bool vis[N];

void work()
{
	read(n);
	for (int i = 1; i <= n; i++) read(x[i]);
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++) vis[x[i] - x[j]] = 1;
	int ans = 0;
	for (int i = 1; i <= 50; i++) ans += vis[i];
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}