#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MaxN = 200005;
const int MaxM = 500005;
struct MST {
	int u, v, w, id;
} t[MaxM], rec[MaxM];
struct Edge {
	int nxt, v, w;
}edge[MaxM];
int head[MaxN], k = 0;
int n, m;
int size = 0, cnt = 0;
int fa[MaxN];
int f[MaxN][25], dep[MaxN], maxw[MaxN][25];
int inmst[MaxM];

void addedge(int u, int v, int w) {
	edge[++k].v = v;
	edge[k].w = w;
	edge[k].nxt = head[u];
	head[u] = k;
}

bool cmp(MST x, MST y)  {
	return x.w < y.w;
}

int find(int x) {
	return x==fa[x] ? x : (fa[x] = find(fa[x]));
}

void insert(int u, int v, int w) {
	addedge(u, v, w);
	addedge(v, u, w);
}

void Kruskal() {
	sort(t + 1, t + 1 + m, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		if(find(t[i].u) != find(t[i].v)) {
            cnt++;
			fa[find(t[i].u)] = find(t[i].v);
			insert(t[i].u, t[i].v, t[i].w);
            size += t[i].w;
            inmst[t[i].id] = 1;
            if(cnt == m) break;
		}
	}
}

void dfs(int u, int fa) {
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		f[v][0] = u;
		maxw[v][0] = edge[i].w;
		dfs(v, u);
	}
}

int lca(int x, int y) {
	int ans = 0;
	if(dep[x] <= dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i--) 
		if(dep[f[x][i]] >= dep[y]) 
			ans = max(maxw[x][i], ans), x = f[x][i];
	if(x == y) return ans;
	for(int i = 20; i >= 0; i--) {
		if(f[x][i] == f[y][i]) continue;
		ans = max(ans, max(maxw[x][i], maxw[y][i]));
		x = f[x][i], y = f[y][i];
	}
	ans = max(ans, max(maxw[x][0], maxw[y][0]));
	return ans;
}

signed main() {
	scanf("%I64d%I64d", &n, &m);
	for(int i = 1; i <= m; i++) {
        scanf("%I64d%I64d%I64d", &t[i].u, &t[i].v, &t[i].w);
        t[i].id = i;
        rec[i] = t[i];
    }
	Kruskal();
	memset(maxw, 0, sizeof(maxw));
    dfs(1, 0);
	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			maxw[j][i] = max(maxw[j][i - 1], maxw[f[j][i - 1]][i - 1]);
		}
	}
	for(int i = 1; i <= m; i++) {
        int u = rec[i].u, v = rec[i].v;
        printf("%I64d\n", size + rec[i].w - lca(u, v));
	}
    return 0;
}