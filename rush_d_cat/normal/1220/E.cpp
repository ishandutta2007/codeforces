#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;
const int N = 1000000 + 10;

//map< pair<int,int>, int > cut;
vector< pair<int,int> > g[N];
int n, m; LL w[N];
bool cut[N];

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
            auto e = g[u][i];
            int v = e.first;
            pair<int, int> edge = make_pair(u, v);
            if (! pre[v])
            {   
                S.push(edge);
                child ++;
                int lowv = dfs(v, u);
                lowu = min(lowu, lowv);
                if (lowv > pre[u]) { 
                    cut[e.second] = 1;
                } 
            } else 
            if (pre[v] < pre[u] && v != p) {
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
    }
} Saber;

int u[N], v[N];
int par[N]; LL sum[N], sz[N];
int find(int x) {
    return par[x] == x ? x: par[x] = find(par[x]);
}

vector<int> tree[N];

LL cac(int u, int p) {
    LL ans = sum[find(u)], tmp = 0;
    for(auto v: tree[u]) {
        //int v = e.second;
        if (v==p) continue;
        tmp = max(cac(v, u), tmp);
    }
    return ans + tmp;
}
int flag[N];
void down(int u,int p){
    if (sz[find(u)] > 1) flag[u] = 1;
    for(auto v: tree[u]) {
        //int v = e.second;
        if (v == p) continue;
        down(v, u);
        if (flag[v]) flag[u] = 1;
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &w[i]);
    }
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&u[i],&v[i]);
        g[u[i]].push_back(make_pair(v[i],i)); 
        g[v[i]].push_back(make_pair(u[i],i));
    }

    int s; scanf("%d", &s);
    Saber.Excalibur(n);
    for(int i=1;i<=n;i++) {
        par[i] = i; sz[i] = 1; sum[i] = w[i]; 
    }
    for(int i=1;i<=m;i++) {
        if(find(u[i]) != find(v[i]) && cut[i] == 0) {
            sum[find(v[i])] += sum[find(u[i])];
            sz[find(v[i])] += sz[find(u[i])];
            par[find(u[i])] = find(v[i]);
        }
    }
    /*
    printf("stage 1\n");
    for(int i=1;i<=n;i++) {
        printf("find %d = %d\n", i,find(i));
    }
    printf("------------------\n");
    */
    for(int i=1;i<=m;i++) {
        if(find(u[i]) != find(v[i])) {
            tree[find(u[i])].push_back(find(v[i]));
            tree[find(v[i])].push_back(find(u[i]));
        }
    }
    down(find(s), find(s));

    for(int i=1;i<=m;i++) {
        if(cut[i] && find(u[i]) != find(v[i])) {
            if (flag[find(u[i])] == 0 || flag[find(v[i])] == 0) continue;
            sum[find(v[i])] += sum[find(u[i])];
            sz[find(v[i])] += sz[find(u[i])];
            par[find(u[i])] = find(v[i]);  
        }
    }
    for(int i=1;i<=n;i++) tree[i].clear();
    /*
    printf("stage 2\n");
    for(int i=1;i<=n;i++) {
        printf("find %d = %d\n", i,find(i));
    }
    printf("------------------\n");
    */
    for(int i=1;i<=m;i++) {
        if(find(u[i]) != find(v[i])) {
            tree[find(u[i])].push_back(find(v[i]));
            tree[find(v[i])].push_back(find(u[i]));
        }
    }
    
    cout << cac(find(s), find(s)) << endl;
}