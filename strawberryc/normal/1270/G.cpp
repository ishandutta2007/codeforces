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

const int N = 1e6 + 5;

int n, a[N], cnt;
bool vis[N];

void work()
{
	int u;
	read(n); cnt = 0;
	for (int i = 1; i <= n; i++) read(a[i]), a[i] = i - a[i];
	for (int i = 1; i <= n; i++) vis[i] = 0;
	for (u = 1; !vis[u]; u = a[u]) vis[u] = 1;
	for (int i = 1; i <= n; i++) vis[i] = 0;
	for (; !vis[u]; u = a[u]) vis[u] = 1, cnt++;
	for (int i = 1; i <= n; i++) vis[i] = 0;
	printf("%d\n", cnt);
	for (; !vis[u]; u = a[u]) vis[u] = 1, printf("%d ", u);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}