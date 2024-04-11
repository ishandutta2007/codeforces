#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 22;

int n, m, h, l;
int q[N + 10], vis[N], flag[N];

void work(int x)
{
	if(vis[x])return;
	vis[x] = 1;
	if(flag[x])q[++l] = x;
	for(int i = 0; i < n; i++)
		if((x >> i) & 1)work(x ^ (1 << i));
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int v;
		scanf("%d", &v);
		flag[v] = 1;
	}
	int ans = 0;
	for(int i = 0; i < (1 << n); i++)
		if(flag[i] && !vis[i])
		{
			ans++;
			h = 0, l = 0;
			q[++l] = i;
			vis[i] = 1;
			while(h < l)
			{
				work((1 << n) - 1 - q[++h]);
			}
		}
	printf("%d\n", ans);
}