#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,m,ans[N];
vector<int> g[N];
set< pair<int,int> > edge;
map< pair<int,int>, int > id;

int vis[N],C;

void dfs(int u) {
    //printf("dfs %d\n", u);
    vis[u]=1;
    for(auto v: g[u]) {
        if(vis[v]==2) {
            ans[id[make_pair(u,v)]] = C; edge.erase(make_pair(u,v)); continue;
        } 
        if(vis[v]==1) continue;
        //printf("%d->%d\n", u,v);
        ans[id[make_pair(u,v)]] = C; edge.erase(make_pair(u,v));
        dfs(v);
    }
    vis[u]=2;
}
void solve() {
    //printf("solve !\n");
    C ++;
    for(int i=1;i<=n;i++) {
        vis[i]=0; g[i].clear();
    }
    for(auto e: edge) {
        //printf("link %d %d\n", e.first,e.second);
        g[e.first].push_back(e.second);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v); 
        edge.insert(make_pair(u,v));
        id[make_pair(u,v)] = i;
    }
    while(edge.size()) solve();
    printf("%d\n", C);
    for(int i=1;i<=m;i++) printf("%d ", ans[i]);
}