//In the name of God
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int Maxn = 3e5 + 9;
bool cut_edge[Maxn];
vector<pair<int,int> > al[Maxn];
pair<int,int> edge[Maxn];
int dep[Maxn],vis[Maxn];
int dfs(int v,int p = -1){
    if(vis[v])
        return dep[v];
    vis[v] = 1;
    int ret = dep[v];
    for(int i = 0; i < al[v].size();i++){
        int u = al[v][i].first,id = al[v][i].second;
        if(u == p)
            continue;
        bool f = vis[u];
        if(!f)
            dep[u] = dep[v] + 1;
        int got = dfs(u,v);
        if(!f && got == dep[u]){
            cut_edge[id] = 1;
        }
        ret = min(ret,got);
    }
    return ret;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        al[--u].push_back(make_pair(--v,i));
        al[v].push_back(make_pair(u,i));
        edge[i] = make_pair(u,v);
    }
    dfs(0);
    for(int i = 0; i < m;i++){
        if(cut_edge[i]){
            printf("0\n");
            return 0;
        }
    }
    for(int i = 0; i < m;i++){
        int u = edge[i].first,v = edge[i].second;
        if(dep[u] > dep[v]) 
            swap(u,v);
        if(dep[v] - dep[u] == 1)
            printf("%d %d\n",u+1,v+1);
        else
            printf("%d %d\n",v+1,u+1);
    }
    return 0;
}