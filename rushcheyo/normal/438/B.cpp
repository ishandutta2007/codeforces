#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int n, m, a[maxn], id[maxn], tot, nxt[2 * maxn], fst[maxn], to[2 * maxn], fa[maxn];

int find(int x) { return fa[x] < 0 ? x : fa[x] = find(fa[x]); }

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), id[i] = i, fa[i] = -1;
	sort(id + 1, id + 1 + n, [](int p, int q) { return a[p] > a[q] || (a[p] == a[q] && p > q); });
	for (int i = 1, a, b; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		nxt[++tot] = fst[a]; fst[a] = tot; to[tot] = b;
		nxt[++tot] = fst[b]; fst[b] = tot; to[tot] = a;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = fst[id[i]]; j; j = nxt[j])
			if (a[to[j]] > a[id[i]] || (a[to[j]] == a[id[i]] && to[j] > id[i]))
			{
				int v = find(to[j]);
				if (v == id[i]) continue;
				ans += 1ll * fa[id[i]] * fa[v] * a[id[i]];
				fa[id[i]] += fa[v], fa[v] = id[i];
			}
	printf("%.6f\n", 2.0 * ans / n / (n - 1));
	return 0;
}