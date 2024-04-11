#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 500000+10;
int n,m;
vector<int> g[N];

struct SCC {
    int pre[N], low[N], sccno[N], dfs_clock, scc_cnt;
    stack<int> S;
    void dfs(int u) {
        pre[u] = low[u] = ++dfs_clock;
        S.push(u);
        for (int i = 0; i < g[u].size(); i ++) {
            int v = g[u][i];
            if (! pre[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (!sccno[v]) {
                low[u] = min(low[u], pre[v]);
            }
        }
        if (low[u] == pre[u]) {
            scc_cnt ++;
            for (;;) {
                int x = S.top(); S.pop();
                sccno[x] = scc_cnt;                                                                        
                if (x == u) break;
            }
        }
    }
    void Excalibur(int n) {
        for (int i = 1; i <= n; i ++) {
            pre[i] = low[i] = sccno[i] = 0;
        }
        while(S.size()) S.pop();
        dfs_clock = scc_cnt = 0;
        for (int i = 1 ;i <= n; i ++)
            if (pre[i] == 0) dfs(i);

    }
} Saber;

void add_edge(int x,int val_x,int y,int val_y) {
    //printf("%d %d -> %d %d\n", x,val_x,y,val_y);
   // printf("%d -> %d\n", x<<1|val_x, y<<1|val_y);
    g[x<<1|val_x].push_back(y<<1|val_y);
}

vector<int> vec[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        for(int j=1;j<=x;j++){
            int y; scanf("%d",&y);
            vec[i].push_back(y);
        }
    }
    for(int i=1;i<n;i++){
        bool flag=0;
        //printf("i = %d\n", i);
        for(int j=0;j<min(vec[i].size(),vec[i+1].size());j++){
            //printf("(%d, %d)\n", vec[i][j], vec[i+1][j]);
            if(vec[i][j]!=vec[i+1][j]){
                int x=vec[i][j], y=vec[i+1][j]; 
                //printf("# %d %d\n", x, y);
                if(x<y) {
                    add_edge(x,1,y,1);
                    add_edge(y,0,x,0);
                } else {
                    add_edge(x,1,x,0);
                    add_edge(y,0,y,1);
                }
                flag=1;
                break;
            }
        }
        if(flag==0 && vec[i].size()>vec[i+1].size()) {
            return !printf("No\n");
        }
    }
    Saber.Excalibur(m<<1|1);
    vector<int> ans;
    for (int i = 1; i <= m; i ++) {
        //printf("i = %d, [%d, %d]\n", i, Saber.sccno[i<<1], Saber.sccno[i<<1|1]);
        if (Saber.sccno[i<<1] == Saber.sccno[i<<1|1]) {
            return !printf("No\n"); 
        }
        if (Saber.sccno[i<<1] < Saber.sccno[i<<1|1]) {
            ans.push_back(i);
        }
    }
    printf("Yes\n");
    printf("%d\n", ans.size());
    for (auto x: ans) printf("%d ", x);
}