#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1, L = 21;

int n, u, v, head[N], nxt[N << 1], to[N << 1], eid = 1;
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}

int dep[N], fa[N][L];
void dfs(int i, int pre){
    dep[i] = dep[pre] + 1;
    fa[i][0] = pre;
    for (int e = head[i]; e; e = nxt[e])
        if(to[e] != pre)
            dfs(to[e], i);
}

int lca(int a, int b){
    if(dep[a] < dep[b])
        swap(a, b);
    int diff = dep[a] - dep[b];
    for (int i = 0; (1 << i) <= diff; i++)
        if(diff & (1 << i))
            a = fa[a][i];
    if(a == b)
        return a;
    for (int i = L - 1; i >= 0; i--)
        if(fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

int p[N];
bool cmp(int a, int b){
    return dep[a] > dep[b];
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    dfs(1, 0);
    for (int j = 1; j < L; j++)
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    int t;
    scanf("%d", &t);
    while(t--){
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &p[i]);
        if(m <= 2){
            puts("YES");
            continue;
        }
        sort(p + 1, p + 1 + m, cmp);
        int u = p[1], v = 0, mindep;
        bool flag = true;
        for (int i = 2; i <= m; i++){
            if(v){
                if(dep[p[i]] < mindep){
                    flag = false;
                    break;
                }
                if(lca(u, p[i]) == p[i])
                    u = p[i];
                else if(lca(v, p[i]) == p[i])
                    v = p[i];
                else{
                    flag = false;
                    break;
                }
            }
            else if(lca(u, p[i]) == p[i])
                u = p[i];
            else{
                v = p[i];
                mindep = dep[lca(u, v)];
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}