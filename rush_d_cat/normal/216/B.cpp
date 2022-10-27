#include <iostream>
#include <vector>
using namespace std;
const int N=102;
int n,m;
vector<int> g[N];
int vis[N];
bool hasring = 0; int sz = 0;
void dfs(int u,int p){
    if(vis[u]==1) {
        hasring = 1;
        return;
    }
    vis[u]=1;
    sz ++;
    for(auto v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int tot = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0) {
            sz=0, hasring=0;
            dfs(i, 0);
            if(hasring == 0)
                tot += sz;
            else
                if(sz % 2 == 0)
                    tot += sz;
                else
                    tot += sz-1;
        }
    }
    printf("%d\n", n-tot+tot%2);
}