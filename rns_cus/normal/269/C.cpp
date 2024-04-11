#include <bits/stdc++.h>

using namespace std;

#define N 200200

int n, m, head[N], to[N << 1], nxt[N << 1];
int vis[N], tot[N], cur[N];
int ans[N];
int a[N], b[N], c[N];

void add(int x, int y, int i) {
	nxt[i * 2] = head[x]; head[x] = i * 2; to[i * 2] = y;
	nxt[i * 2 + 1] = head[y]; head[y] = i * 2 + 1; to[i * 2 + 1] = x;
}

void dfs(int r) {
	vis[r] = 1;
	for(int i = head[r]; i; i = nxt[i]) {
		if(vis[to[i]]) continue;
		cur[to[i]] += c[i / 2];
        ans[i / 2]  = i & 1;
        if(to[i] == n) continue;
        if(!vis[to[i]] && cur[to[i]] == tot[to[i]] / 2) dfs(to[i]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%d", a + i, b + i, c + i);
		add(a[i], b[i], i);
		tot[a[i]] += c[i];
		tot[b[i]] += c[i];
	}
	dfs(1);
	for(int i = 1 ;i <= m; i ++) printf("%d\n", ans[i]);
	return 0;
}