#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int n, m, v[maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", v + i);
	int ans = 0;
	for (int i = 1, a, b; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		ans += min(v[a], v[b]);
	}
	printf("%d\n", ans);
	return 0;
}