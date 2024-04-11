#include <bits/stdc++.h>

using namespace std;

#define M 1005
#define N 100005
#define lft id << 1
#define rgt id << 1 | 1

bitset <M> p, rlt, b[N << 2];
int m;
int a[N], aa[N];
int head[N], to[N << 1], nxt[N << 1];
int add[N << 2];

bool isprime(int x) {
    for (int i = 2; i < x; i ++) if (x % i == 0) return 0;
    return 1;
}

int dt[N], ft[N], dtime = 0;

void DFS(int u, int pr = 0) {
    dt[u] = ++ dtime;
    aa[dtime] = a[u];
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == pr) continue;
        DFS(v, u);
    }
    ft[u] = dtime;
}

void build(int l, int r, int id) {
    if (l == r) {
        b[id][aa[l]] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, lft);
    build(mid + 1, r, rgt);
    b[id] = b[lft] | b[rgt];
}

void modify(bitset <M> &bp, int x) {
    bp = (bp << x) | (bp >> (m - x));
}

void push_down(int id) {
    if (add[id]) {
        add[lft] = (add[lft] + add[id]) % m;
        add[rgt] = (add[rgt] + add[id]) % m;
        modify(b[lft], add[id]);
        modify(b[rgt], add[id]);
        add[id] = 0;
    }
}

void modify(int L, int R, int x, int l, int r, int id) {
    if (L <= l && r <= R) {
        add[id] = (add[id] + x) % m;
        modify(b[id], x);
        return;
    }
    push_down(id);
    int mid = l + r >> 1;
    if (L <= mid) modify(L, R, x, l, mid, lft);
    if (mid < R) modify(L, R, x, mid + 1, r, rgt);
    b[id] = b[lft] | b[rgt];
}

void query(int L, int R, int l, int r, int id) {
    if (L <= l && r <= R) {
        rlt |= b[id];
        return;
    }
    push_down(id);
    int mid = l + r >> 1;
    if (L <= mid) query(L, R, l, mid, lft);
    if (mid < R) query(L, R, mid + 1, r, rgt);
}

void AddEdge(int a, int b, int i) {
    to[i] = b;
    nxt[i] = head[a];
    head[a] = i;
}

main() {
    int n, q;
    scanf("%d %d", &n, &m);
    for (int i = 2; i < m; i ++) {
        if (isprime(i)) p[i] = 1;
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%d", a + i);
        a[i] %= m;
    }
    for (int i = 1; i < n; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        AddEdge(a, b, i);
        AddEdge(b, a, i + n - 1);
    }
    DFS(1);
    build(1, n, 1);
    for (scanf("%d", &q); q --; ) {
        int bf, u, x;
        scanf("%d %d", &bf, &u);
        if (bf == 1) {
            scanf("%d", &x);
            modify(dt[u], ft[u], x % m, 1, n, 1);
        } else {
            rlt.reset();
            query(dt[u], ft[u], 1, n, 1);
            printf("%d\n", (rlt & p).count());
        }
    }
}