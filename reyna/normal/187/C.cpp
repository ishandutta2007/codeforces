//In the name of God
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxn = 2e5 + 9;
bool is_it[Maxn];
vector<int> al[Maxn];
int Que[Maxn],bg,ed,par[Maxn];
int vis[Maxn],dis[Maxn];
vector<pair<int,pair<int,int> > > edges;
pair<int,int> edge[Maxn];
int find(int v){
    if(par[v] != v)
        return par[v] = find(par[v]);
    return v;
}
bool unite(int u,int v){
    u = find(u),v = find(v);
    if(u == v)
        return 0;
    par[u] = v;
    return 1;
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n;i++)
        par[i] = i;
    for(int i = 0; i < k;i++){
        int now;
        scanf("%d",&now);
        is_it[--now] = 1;
    }
    for(int i = 0; i < m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        al[--u].push_back(--v);
        al[v].push_back(u);
        edge[i] = make_pair(u,v);
    }
    int stp,edp;
    scanf("%d%d",&stp,&edp);
    is_it[--stp] = 1;
    is_it[--edp] = 1;
    for(int i = 0; i < n;i++)
        if(is_it[i]){
            Que[ed++] = i;
            vis[i] = 1;
        }
    while(bg != ed){
        int v = Que[bg++];
        for(int i = 0; i < al[v].size();i++){
            int u = al[v][i];
            if(!vis[u]){
                vis[u] = 1;
                dis[u] = dis[v] + 1;
                unite(u,v);
                Que[ed++] = u;
            }
        }
    }
    for(int i = 0; i < m;i++){
        int v = edge[i].first,u = edge[i].second;
        if(find(u) != find(v)){
            edges.push_back(make_pair(dis[v] + dis[u] + 1,make_pair(find(u),find(v))));
        }
    }
    sort(edges.begin(),edges.end());
    for(int i = 0; i < edges.size();i++){
        int u = edges[i].second.first,v = edges[i].second.second;
        unite(u,v);
        if(find(stp) == find(edp)){
            printf("%d\n",edges[i].first);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}