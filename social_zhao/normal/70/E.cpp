#include<bits/stdc++.h>
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 185;
int n, k, dis[N][N], f[N][N], d[N], mn[N], ans[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void GetDis(int u, int lst, int rt) {
    for(int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == lst) continue;
        dis[rt][v] = dis[rt][u] + 1, GetDis(v, u, rt);
    }
}

void dfs(int u, int lst) {
    for(int i = 1; i <= n; i++) f[i][u] = d[dis[u][i]] + k;
    for(int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == lst) continue;
        dfs(v, u);
        for(int j = 1; j <= n; j++) f[j][u] += min(f[j][v] - k, f[mn[v]][v]);
    }
    mn[u] = 1;
    for(int i = 1; i <= n; i++) mn[u] = f[i][u] < f[mn[u]][u]? i : mn[u];
}

void GetAns(int u, int lst, int ansf) {
    ans[u] = ansf;
    for(int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == lst) continue;
        if(f[ansf][v] - k < f[mn[v]][v]) GetAns(v, u, ansf);
        else GetAns(v, u, mn[v]);
    }
}

int main() {
    n = get(), k = get();
    for(int i = 1; i < n; i++) d[i] = get();
    for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
    for(int i = 1; i <= n; i++) GetDis(i, 0, i);
    dfs(1, 0);
    GetAns(1, 0, mn[1]);
    cout << f[mn[1]][1] << endl;
    for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
    return 0;
}