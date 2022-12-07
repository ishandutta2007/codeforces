#include <stdio.h>
const int maxn = 1000001;
int graph[maxn << 1];
int prev[maxn << 1];
int last[maxn], lgraph;
int a[maxn], n;
void insert(int u, int v){
    lgraph ++;
    graph[lgraph] = v;
    prev[lgraph] = last[u];
    last[u] = lgraph;
}

int F[maxn];
int index[maxn];
int left[maxn];
int right[maxn];
long long ss[maxn];
int k;
void build_graph(int u, int f){
    F[u] = f;
    k ++;
    index[k] = u;
    left[u] = k;
    int v;
    for(int i = last[u]; i; i = prev[i]){
        v = graph[i];
        if(v == f) continue;
        build_graph(v ,u);
    }
    right[u] = k;
}


int t[maxn << 2], c[maxn << 2];
void build(int v, int l, int r){
    if(l == r){
        t[v] = index[l];
        c[v] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(v<<1, l, m);
    build(v<<1|1, m + 1, r);
    t[v] = a[t[v<<1]] < a[t[v<<1|1]] ? t[v<<1|1] : t[v<<1];
    c[v] = c[v << 1] + c[v << 1 | 1];
}
int get_max_id(int v, int l, int r, int L, int R){
    if(L > r || R < l || c[v] == 0) return 0;
    if(L <= l && r <= R) return t[v];
    int m = (l + r) >> 1;
    int rl = get_max_id(v << 1, l, m, L, R),
        rr = get_max_id(v << 1 | 1, m + 1, r, L, R);
    return a[rr] > a[rl] ? rr : rl;
}
void clear_graph(int v, int l, int r, int L, int R){
    if(L > r || R < l || c[v] == 0) return;
    if(L <= l && r <= R){
        t[v] = 0;
        c[v] = 0;
        ///printf("%d %d cleared\n", l, r);
        return;
    }
    int m = (l + r) >> 1;
    clear_graph(v << 1, l, m, L, R);
    clear_graph(v << 1 | 1, m + 1, r, L, R);
    t[v] = a[t[v<<1]] < a[t[v<<1|1]] ? t[v<<1|1] : t[v<<1];
    c[v] = c[v << 1] + c[v << 1 | 1];
}
int get_col(int v, int l, int r, int L, int R){
    if(L > r || R < l || c[v] == 0) return 0;
    if(L <= l && r <= R) return c[v];
    int m = (l + r) >> 1;
    return get_col(v << 1, l, m, L, R) + get_col(v << 1 | 1, m + 1, r, L, R);
}
__int64 res;
void solve(int l, int r){
    ///printf("%d %d\n", l, r);
    if(l > r) return;
    int mx, col, u, v, C;
    while(true){
        mx = get_max_id(1, 1, n, l, r);
        ///printf("%d\n", a[mx]);
        ///getchar();
        if(mx == 0) break;
        col = get_col(1, 1, n, l, r);
        u = mx;
        for(int i = last[u]; i; i = prev[i]){
            v = graph[i];
            if(F[u] == v) continue;
            C = get_col(1, 1, n, left[v], right[v]);
            col -= C;
            res += ((1LL * col) * C) * a[u];
        }
        res += (col - 1LL) * a[u];
        for(int i = last[u]; i; i = prev[i]){
            v = graph[i];
            if(F[u] == v) continue;
            solve(left[v], right[v]);
        }
        clear_graph(1, 1, n, left[u], right[u]);
        ///printf("%d %d cleared\n", left[u], right[u]);
    }
}
void solve(){
    build(1, 1, n);
    solve(1, n);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", a+i);
    for(int i = 1, u, v; i < n; i ++){
        scanf("%d%d", &u, &v);
        insert(u, v);
        insert(v, u);
    }
    build_graph(1, 0);
    ///for(int i = 1; i <= n; i ++) printf("%d %d %d\n", i, left[i], right[i]);
    solve();
    for(int i = 1; i <= n; i ++) a[i] = -a[i];
    a[0] = -1e7;
    solve();
    printf("%I64d", res);
    return 0;
}