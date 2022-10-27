#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int N = 500000 + 10;
int n,m,q;
vector<int> g[N], bcc[N];
int par[N]; vector<int> tree[N];
int tot;
int u[N],v[N];
int dep[N],father[N][20];
int find(int x) {
    return par[x]==x?x:par[x]=find(par[x]);
}
struct BCC {
    int pre[N], low[N], iscut[N], bccno[N];
    int dfs_clock, bcc_cnt;
    stack< pair<int,int> > S;
    int dfs(int u, int p) 
    {
        int lowu = pre[u] = ++ dfs_clock;
        int child = 0;
        for (int i = 0; i < g[u].size(); i ++) 
        {
            int v = g[u][i];
            pair<int, int> edge = make_pair(u, v);
            if (! pre[v])
            {   
                S.push(edge);
                child ++;
                int lowv = dfs(v, u);
                lowu = min(lowu, lowv);
                if (lowv >= pre[u]) { 
                    bcc[++ bcc_cnt].clear();
                    iscut[u] = 1;
                    for (;;) {
                        pair<int, int> x = S.top(); S.pop();
                        if (bccno[x.first] != bcc_cnt) {
                            bccno[x.first] = bcc_cnt;
                            bcc[bcc_cnt].push_back(x.first);
                        }
                        if (bccno[x.second] != bcc_cnt) {
                            bccno[x.second] = bcc_cnt;
                            bcc[bcc_cnt].push_back(x.second);
                        }
                        if (x.first == u && x.second == v)
                            break;
                    }
                } 
            } else 
            if (pre[v] < pre[u] && v != p) {
                S.push(edge);
                lowu = min(lowu, pre[v]);
            }
        }
        if (p == -1 && child <= 1) iscut[u] = 0;
        return lowu;
    }
    void Excalibur(int n) 
    {
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        memset(iscut, 0, sizeof(iscut));
        memset(bccno, 0, sizeof(bccno));
        dfs_clock = bcc_cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (pre[i] == 0)
                dfs(i, -1);
        }   

        for(int i=1;i<=bcc_cnt;i++) {
            ++ tot;
            for(auto x: bcc[i]) {
                tree[tot].push_back(x);
                tree[x].push_back(tot);
            }
        }
    }
} Saber;

void dfs(int u,int p) {
    dep[u] = dep[p] + 1; father[u][0] = p;
    for(auto v: tree[u]) {
        if (p==v) continue;
        dfs(v, u);
    }
}
void init() {
    for(int j=1;j<20;j++)
    for(int i=1;i<=n;i++) {
        father[i][j] = father[father[i][j-1]][j-1];
    }
}
int lca(int u,int v) {
    if (dep[u]<dep[v]) swap(u,v);
    int d = dep[u]-dep[v];
    for(int i=19;i>=0;i--) {
        if((d>>i)&1) u = father[u][i];
    }
    if (u==v) return u;
    for(int i=19;i>=0;i--) {
        if(father[u][i]!=father[v][i]) {
            u = father[u][i], v = father[v][i];
        }
    }
    return father[u][0];
}
int main() {
    scanf("%d%d%d",&n,&m,&q); tot = n;
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&u[i],&v[i]);
        g[u[i]].push_back(v[i]); g[v[i]].push_back(u[i]);
    }
    Saber.Excalibur(n);  n = tot;
    dfs(find(1), find(1));
    init();
    while(q--) {
        int x,y; scanf("%d%d",&x,&y); 
        int LCA = lca(x, y);
        int len = dep[x] + dep[y] - 2*dep[LCA];
        printf("%d\n", len/2);
    }   
}