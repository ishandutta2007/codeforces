#include <cstdio>

const int maxn = 1000005;
int n, m, tot, cur, nxt[2 * maxn], to[2 * maxn], fst[maxn];
bool del[maxn], ans[maxn];

void solve()
{
	while (cur <= n && del[cur]) cur++;
	if (cur > n) return;
	int u = cur;
	del[u] = true;
	for (int i = fst[u]; i; i = nxt[i])
		if (i & 1) del[to[i]] = true;
	solve();
	for (int i = fst[u]; i; i = nxt[i])
		if (~i & 1) ans[u] |= ans[to[i]];
	ans[u] ^= 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, a, b; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		nxt[++tot] = fst[a]; fst[a] = tot; to[tot] = b;
		nxt[++tot] = fst[b]; fst[b] = tot; to[tot] = a;
	}
	cur = 1;
	solve();
	int tot = 0;
	for (int i = 1; i <= n; i++) tot += ans[i];
	printf("%d\n", tot);
	for (int i = 1; i <= n; i++) if (ans[i]) printf("%d ", i);
	puts("");
	return 0;
}