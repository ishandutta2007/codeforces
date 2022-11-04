#include <cstdio>
#include <cstring>
using namespace std;
const int N = 4e5 + 2;

int t, n, a[N], head[N], nxt[N], to[N], eid;
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}
bool vis[N];
void dfs(int i){
    vis[i] = true;
    for (int e = head[i]; e; e = nxt[e])
        if(!vis[to[e]])
            dfs(to[e]);
}

int main(){
    scanf("%d", &t);
    while(t--){
        eid = 1;
        scanf("%d", &n);
        memset(head + 1, 0, sizeof(int) * (n + 1));
        memset(vis + 1, 0, sizeof(bool) * (n + 1));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++){
            if(i - a[i] >= 1)
                addedge(i - a[i], i + 1);
            if(i + a[i] <= n)
                addedge(i, i + a[i] + 1);
        }
        dfs(1);
        puts(vis[n + 1] ? "YES" : "NO");
    }
    return 0;
}