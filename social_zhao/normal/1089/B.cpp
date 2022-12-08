#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, S = 305;
int n, m, node;
char s[S];
struct Edge { int v, nxt; } edge[N];
int head[S], tot;
int col[S], pre[S], bel[S], fa[S];
int vis[S], tim;
queue<int> q;

void clear() {
	memset(edge, 0, sizeof(edge));
	memset(head, 0, sizeof(head));
	memset(col, 0, sizeof(col));
	memset(pre, 0, sizeof(pre));
	memset(fa, 0, sizeof(fa));
	memset(bel, 0, sizeof(bel));
	memset(vis, 0, sizeof(vis));
	tot = 0, tim = 0;
}

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }
void insedge(int u, int v) { add(u, v), add(v, u); }
int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

int lca(int x, int y) {
	tim++;
	x = find(x), y = find(y);
	while(vis[x] != tim) {
		vis[x] = tim, x = find(pre[bel[x]]);
		if(y) swap(x, y);
	}
	return x;
}

void shrink(int x, int y, int w) {
	while(find(x) != w) {
		pre[x] = y, y = bel[x];
		if(col[y] == 2) col[y] = 1, q.push(y);
		if(find(x) == x) fa[x] = w;
		if(find(y) == y) fa[y] = w;
		x = pre[y];
	}
}

bool bfs(int s) {
	for(int i = 1; i <= node; i++) col[i] = 0, fa[i] = i;
	while(!q.empty()) q.pop();
	q.push(s), col[s] = 1;
	while(!q.empty()) {
		int u = q.front(), w; q.pop();
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			if(col[v] == 2 || find(u) == find(v)) continue;
			if(!col[v]) {
				col[v] = 2, pre[v] = u;
				if(!bel[v]) {
					for(int x = v, lst; x; x = lst) 
						lst = bel[pre[x]], bel[x] = pre[x], bel[pre[x]] = x;
					return 1;
				}
				else col[bel[v]] = 1, q.push(bel[v]);
			}
			else w = lca(u, v), shrink(u, v, w), shrink(v, u, w);
		}
	}
	return 0;
}

void solve() {
	n = get(), m = get(), node = n + n + m;
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		insedge(i, i + n);
		for(int j = 1; j <= m; j++) if(s[j] == '1') insedge(j + 2 * n, i), insedge(j + 2 * n, i + n);
	}
	int ans = 0;
	for(int i = 1; i <= node; i++) if(!bel[i]) ans += bfs(i);
	printf("%d\n", ans - n);
}

int main() {
	int T = get();
	while(T--) clear(), solve();
	return 0;
}

/*
1
3 4
0110
1100
0011
*/