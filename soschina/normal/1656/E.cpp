#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 1;

int t, n, u, v, d[N], head[N], nxt[N << 1], to[N << 1], val[N], eid;
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}

void dfs(int i, int f, int v){
    val[i] = v * d[i];
    for(int e = head[i]; e; e = nxt[e]) if(to[e] != f)
        dfs(to[e], i, -v);
}

int main(){
    scanf("%d", &t);
    while(t--){
        eid = 1;
        memset(head + 1, 0, sizeof(int) * n);
        memset(d + 1, 0, sizeof(int) * n);
        scanf("%d", &n);
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            d[u]++;
            d[v]++;
            addedge(u, v);
            addedge(v, u);
        }
        dfs(1, 0, 1);
        for(int i = 1; i <= n; i++)
            printf("%d ", val[i]);
        putchar('\n');
    }
    return 0;
}