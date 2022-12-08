#include<bits/stdc++.h>
using namespace std;

inline int get() {
    int x = 0, sign = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sign = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * sign;
}

const int N = 1e5 + 5, E = N << 1;
struct Edge {
    int v, nxt;
} edge[E];
int head[N], k = 1;
int n, m;
int f[N][20], dep[N], size[N];

inline void addedge(int u, int v) {
	edge[++k].v = v;
	edge[k].nxt = head[u];
	head[u] = k;
}

inline void insedge(int u, int v) {
    addedge(u, v);
    addedge(v, u);
}

inline void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1, size[u] = 1, f[u][0] = fa;
    for(int i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for(int i = head[u]; i; i = edge[i].nxt) if(edge[i].v != fa) dfs(edge[i].v, u), size[u] += size[edge[i].v];
}

inline int LCA(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(register int i = 19; i >= 0; i--) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
    if(x == y) return x;
    for(register int i = 19; i >= 0; i--) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

inline int jump(int x, int len) {
    int res = x;
    for(int i = 19; i >= 0; i--) if(dep[x] - dep[f[res][i]] <= len) res = f[res][i];
    return res;
}

int main() {
    n = get();
    for(register int i = 1; i < n; i++) {
        int u = get(), v = get();
        insedge(u, v);
    }
    dfs(1, 0);
    m = get();
    for(register int i = 1; i <= m; i++) {
        int x = get(), y = get();
        if(x == y) { printf("%d\n", size[1]); continue; }
        int lca = LCA(x, y);
        int len = dep[x] + dep[y] - 2 * dep[lca] + 1;
        if(!(len & 1)) { printf("0\n"); continue; }
        len /= 2;
        if(dep[x] - dep[lca] == len) { printf("%d\n", size[1] - size[jump(x, len - 1)] - size[jump(y, len - 1)]); continue; }
        else {
            if(dep[x] < dep[y]) swap(x, y);
            printf("%d\n", size[jump(x, len)] - size[jump(x, len - 1)]);
        }
    }
    return 0;
}