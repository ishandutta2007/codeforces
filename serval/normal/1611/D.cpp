#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int b[N], p[N];
int w[N], f[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
	{
		w[i] = 0;
		f[i] = (b[i] == i ? 0 : -1);
	}
	if (b[p[1]] != p[1])
	{
		printf("-1\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[b[p[i]]] == -1)
		{
			printf("-1\n");
			return;
		}
		if (i != 1)
			w[p[i]] = f[p[i - 1]] + 1 - f[b[p[i]]];
		f[p[i]] = f[b[p[i]]] + w[p[i]];
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", w[i], " \n"[i == n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}