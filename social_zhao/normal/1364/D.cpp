#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, m, k, dep[N], vis[N], fa[N], cnt[2], md, ins[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot = 1;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int lst) {
//	printf("dfs %d %d\n", u, lst);
	vis[u] = 1, fa[u] = lst, dep[u] = dep[lst] + 1, cnt[dep[u] & 1]++, ins[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		if(!vis[v]) dfs(v, u);
		else {
			if(ins[v] && dep[u] - dep[v] + 1 <= k) {
//				printf("%d: %d %d\n", dep[u] - dep[v] + 1, u, v);
//				exit(0);
				printf("2\n");
				int now = u;
				printf("%d\n", dep[u] - dep[v] + 1);
				while(now != v) printf("%d ", now), now = fa[now];
				printf("%d\n", now);
				exit(0);
			}
		}
	}
	if(dep[u] > dep[md]) md = u;
	ins[u] = 0;
}

int main() {
	n = get(), m = get(), k = get();
	for(int i = 1, u, v; i <= m; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	printf("1\n");
	if(n - 1 == m) {
		if(cnt[0] > (k + 1) / 2) {
			int cnt = 0;
			for(int i = 1; i <= n && cnt != (k + 1) / 2; i++) if((dep[i] & 1) == 0) ++cnt, printf("%d ", i);
			printf("\n");
			return 0;
		}
		else {
			int cnt = 0;
			for(int i = 1; i <= n && cnt != (k + 1) / 2; i++) if((dep[i] & 1) == 1) ++cnt, printf("%d ", i);
			printf("\n");
			return 0;
		}
	}
	else {
//		return 0;
		int now = md;
		for(int i = 1; i <= (k + 1) / 2; i++) printf("%d ", now), now = fa[fa[now]];
	}
	return 0;
}