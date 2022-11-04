#include <cstdio>
#include <iostream>
#include <cstring>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 1e5 + 1, T = 21;

int t, n, m, q, u, v, fa[N];
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int head[N], nxt[N << 1], to[N << 1], val[N << 1], eid = 1;
void addedge(int u, int v, int w){
    val[eid] = w;
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}

int dep[N], stfa[N][T], stmax[N][T];
void dfs(int i, int pre){
    dep[i] = dep[pre] + 1;
    for (int e = head[i]; e; e = nxt[e])
        if(to[e] != pre){
            stfa[to[e]][0] = i;
            stmax[to[e]][0] = val[e];
            dfs(to[e], i);
        }
}

int stquery(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    int diff = dep[u] - dep[v], ans = 0;
    for (int i = 0; (1 << i) <= diff; i++)
        if(diff & (1 << i)){
            ans = max(ans, stmax[u][i]);
            u = stfa[u][i];
        }
    if(u == v)
        return ans;
    for (int i = T - 1; i >= 0; i--)
        if(stfa[u][i] != stfa[v][i]){
            ans = max(ans, max(stmax[u][i], stmax[v][i]));
            u = stfa[u][i], v = stfa[v][i];
        }
    return max(ans, max(stmax[u][0], stmax[v][0]));
}

int tree[N << 2];
void build(int i, int l, int r){
    if(l == r){
        tree[i] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(le, l, mid);
    build(ri, mid + 1, r);
    tree[i] = max(max(tree[le], tree[ri]), stquery(l, r));
}

int L, R;
int query(int i, int l, int r){
    if(l >= L && r <= R)
        return tree[i];
    int mid = (l + r) >> 1;
    if(mid >= L && mid < R)
        return max(max(query(le, l, mid), query(ri, mid + 1, r)), stquery(mid, mid + 1));
    if(mid >= L)
        return query(le, l, mid);
    return query(ri, mid + 1, r);
}

int main(){
    scanf("%d", &t);
    while(t--){
        memset(head + 1, 0, sizeof(int) * n);
        memset(stfa[1], 0, sizeof(int) * n * T);
        memset(stmax[1], 0, sizeof(int) * n * T);
        eid = 1;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= m; i++){
            scanf("%d%d", &u, &v);
            if(find(u) != find(v)){
                fa[find(u)] = find(v);
                addedge(u, v, i);
                addedge(v, u, i);
            }
        }
        dfs(1, 0);
        for (int j = 1; j < T; j++)
            for (int i = 1; i <= n; i++){
                stfa[i][j] = stfa[stfa[i][j - 1]][j - 1];
                stmax[i][j] = max(stmax[i][j - 1], stmax[stfa[i][j - 1]][j - 1]);
            }
        build(1, 1, n);
        while(q--){
            scanf("%d%d", &L, &R);
            printf("%d ", query(1, 1, n));
        }
        putchar('\n');
    }
    return 0;
}