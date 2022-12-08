#include<bits/stdc++.h>
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 55, M = N * N, inf = 0x3f3f3f3f;
int n, m, s, t, MaxFlow = 0, MinCost = 0;
struct Edge { int v, nxt, f, c; } edge[M << 1];
int head[N], tot = 1;
int flow[N], pre[N], dis[N], inq[N];
int binf[N], binc[N], top;

void addedge(int u, int v, int f, int c) { edge[++tot] = (Edge){ v, head[u], f, c }, head[u] = tot; }
void insedge(int u, int v, int f, int c) { addedge(u, v, f, c), addedge(v, u, 0, -c); }

int SPFA() {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis)), dis[s] = 0, flow[s] = inf, flow[t] = 0, inq[s] = 1, q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].v, f = edge[i].f, c = edge[i].c;
            if(f && dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c, pre[v] = i, flow[v] = min(flow[u], f);
                if(!inq[v]) inq[v] = 1, q.push(v);
            }
        }
    }
    return flow[t];
}

void update() {
    MaxFlow += flow[t];
    for(int i = t; i != s; i = edge[pre[i] ^ 1].v)
        MinCost += flow[t] * edge[pre[i]].c, edge[pre[i]].f -= flow[t], edge[pre[i] ^ 1].f += flow[t];
}

int main() {
    n = get(), m = get(), s = 1, t = n;
    for(int i = 1, u, v, w; i <= m; i++) u = get(), v = get(), w = get(), insedge(u, v, 1, w);
    while(SPFA())
        ++top, update(), binf[top] = MaxFlow, binc[top] = MinCost;
    int q = get();
    for(int i = 1; i <= q; i++) {
        int x = get();
        double ans = 1e9;
        for(int j = 1; j <= n; j++) ans = min(ans, 1.0 * (binc[j] + x) / binf[j]);
        printf("%.8lf\n", ans);
    }
    return 0;
}