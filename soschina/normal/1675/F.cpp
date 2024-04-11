#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 1;

int T, n, k, s, t, u, v, a, head[N], nxt[N << 1], to[N << 1], eid;
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}
bool col[N];

int dep[N], fa[N];
int dfs(int i){
    dep[i] = dep[fa[i]] + 1;
    int ret = 0;
    for (int e = head[i]; e; e = nxt[e])
        if(to[e] != fa[i]){
            fa[to[e]] = i;
            ret += dfs(to[e]);
            if(col[to[e]]){
                col[i] = true;
                ret += 2;
            }
        }
    return ret;
}

int main(){
    scanf("%d", &T);
    while(T--){
        eid = 1;
        memset(head + 1, 0, sizeof(int) * n);
        memset(col + 1, 0, sizeof(bool) * n);
        scanf("%d%d%d%d", &n, &k, &s, &t);
        for (int i = 1; i <= k; i++){
            scanf("%d", &a);
            col[a] = true;
        }
        for (int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
            dep[0] = -1;
        fa[s] = 0;
        int ans = dfs(s);
        if(col[t])
            ans -= dep[t];
        else{
            int s = t;
            while(!col[s]){
                s = fa[s];
                ans++;
            }
            ans -= dep[s];
        }
        printf("%d\n", ans);
    }
    return 0;
}