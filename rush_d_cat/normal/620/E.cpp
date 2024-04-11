#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 800000+10;
int n, m, u, v, op, T, tot, head[N<<1], dfsn[N], l[N], r[N], c[N<<1], cc[N];
LL sum[N*2];
struct Edge {
    int v, nex;
    Edge() {}
    Edge(int v_, int nex_) {
        v = v_, nex = nex_;
    }
} edge[N<<1];
void init() {
    T = 0, tot = 0;
    memset(head, -1, sizeof(head));
}
void add_edge(int u, int v) {
    edge[tot] = Edge(v, head[u]);
    head[u] = tot ++;
}
int count(LL x) {
    int ans = 0;
    while (x) {
        if (x&1) ans++;
        x >>= 1;
    }
    return ans;
}
void dfs(int u, int p) {
    l[u] = ++ T;
    dfsn[T] = u;
    for (int i = head[u]; i != -1; i = edge[i].nex) {
        int v = edge[i].v;
        if (v == p) continue;
        dfs(v, u);
    }
    r[u] = T;
}
void push_up(int rt) {
    sum[rt] = (sum[rt<<1] | sum[(rt<<1)|1]);
}
void push_down(int rt) {
    if (c[rt]) {
        c[rt<<1] = c[(rt<<1)|1] = c[rt];
        sum[rt<<1] = sum[(rt<<1)|1] = (1LL<<c[rt]);
        c[rt] = 0;
    }
}
void build(int l, int r, int rt) {
    c[rt] = 0;
    if (l == r) {
        sum[rt] = (1LL << cc[dfsn[l]]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt<<1);
    build(mid+1, r, (rt<<1)|1);
    push_up(rt);
}
void update(int l, int r, int rt, int L, int R, int d) {
    if (L <= l && r <= R) {
        sum[rt] = (1LL<<d);
        c[rt] = d;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt);
    if (L <= mid) update(l, mid, rt<<1, L, R, d);
    if (R > mid) update(mid+1, r, (rt<<1)|1, L, R, d);
    push_up(rt);
}
LL query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) return sum[rt];
    LL ans = 0;
    push_down(rt);
    int mid = (l+r)>>1;
    if (L <= mid) 
        ans |= query(l, mid, rt<<1, L, R);
    if (R > mid) 
        ans |= query(mid+1, r, (rt<<1)|1, L, R);
    return ans; 
}

int main() {
    init();
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &cc[i]);
    for (int i = 1; i < n; i ++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, -1);
    build(1, n, 1);

    for (int i = 1; i <= m; i ++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d", &u, &v);
            update(1, n, 1, l[u], r[u], v);
        }
        if (op == 2) {
            scanf("%d", &u);
            printf("%d\n", count(query(1, n, 1, l[u], r[u])));
        }
    }
}