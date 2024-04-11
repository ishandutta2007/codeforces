#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int E = N;

int n, m;
int h[N], nx[E], to[E], et;
int id[N], od[N];

int id0[N], tid[N], top;
int topo[N], cnt;
int f[N];

int ans;

void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
	id[v]++;
	od[u]++;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ae(u, v);
	}
	for (int i = 1; i <= n; i++)
	{
		tid[i] = id[i];
		if (id[i] == 0)
			id0[++top] = i;
	}
	while (top)
	{
		int u = id0[top--];
		topo[++cnt] = u;
		for (int i = h[u]; i; i = nx[i])
		{
			tid[to[i]]--;
			if (tid[to[i]] == 0)
				id0[++top] = to[i];
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		int cur = topo[i];
		f[cur] = max(f[cur], 1);
		if (od[cur] == 1)
			continue;
		for (int j = h[cur]; j; j = nx[j])
			if (id[to[j]] > 1)
				f[to[j]] = max(f[to[j]], f[cur] + 1);
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}