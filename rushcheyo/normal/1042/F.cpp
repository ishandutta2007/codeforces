#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
int n, k, tot, deg[maxn], nxt[2 * maxn], fst[maxn], to[2 * maxn], ans;

int dfs(int u, int fa)
{
	vector<int> v;
	for (int i = fst[u]; i; i = nxt[i])
		if (to[i] != fa)
			v.push_back(1 + dfs(to[i], u));
	if (v.empty()) return 0;
	sort(v.begin(), v.end());
	while (v.size() > 1)
	{
		if (v[v.size() - 1] + v[v.size() - 2] <= k) break;
		v.pop_back(), ans++;
	}
	return v[v.size() - 1];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1, u, v; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v;
		nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u;
		deg[u]++, deg[v]++;
	}
	int rt;
	for (int i = 1; i <= n; i++)
		if (deg[i] > 1) rt = i;
	dfs(rt, 0);
	printf("%d\n", ans + 1);
	return 0;
}