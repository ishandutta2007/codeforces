#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>, int> > E;
struct Bridges{
    static const int N = 1005;
    static const int M = 40005;
    int tim=0;
    int vis[N];
    int vis2[N];
    int tin[N], tout[N], isBridge[M], minAncestor[N];
    vector<pair<int, int> > g[N]; //vertex, index of edge
    void init(int n, int m){
        tim=0;
        for (int i=0;i<=n;i++) vis[i]=0, g[i].clear(), vis2[i]=0;
        for (int i=0;i<=m;i++) isBridge[i]=0;
        edges.clear();
        ret=1e9+2, best=-1;
        reach =0;
    }
    void addEdge(int u,int v,int id){
        g[u].emplace_back(v,id);
    }
    int st,en;
    int ret=1e9+2;
    int best=-1;
    bool reach=0;
    vector<pair<int,int> > edges;
    void dfs2(int v){
        vis2[v]=1;
        if (v==en){
            reach = 1;
            for (auto x:edges){
                if (x.first < ret){
                    ret = x.first;
                    best = x.second;
                }
            }
        }
        for (auto [u,id]:g[v]){
            if (vis2[u])continue;
            if (isBridge[id]) edges.emplace_back(E[id].second, id);
            dfs2(u);
            if (isBridge[id]) edges.pop_back();
        }
    }
    pair<int,int> run(int s,int t){
        st = s, en = t;
        dfs(s,-1);
        dfs2(s);
        if (!reach) return {0,-1};
        else return {(ret>1e9)?-1:ret , best};
    }
    void dfs(int k, int par)
    {
        vis[k]=1;
        tin[k]=++tim;
        minAncestor[k]=tin[k];
        for(auto it:g[k])
        {
            if(it.second==par)
                continue;
            if(vis[it.first])
            {
                minAncestor[k]=min(minAncestor[k], tin[it.first]);
                continue;
            }
            dfs(it.first, it.second);
            minAncestor[k]=min(minAncestor[k], minAncestor[it.first]);
            if(minAncestor[it.first]>tin[k])
                isBridge[it.second]=1;
        }
        tout[k]=tim;
    }
};
vector<int> possibleEdges;
vector<pair<int,int> > adj[1000000];
bool vis[1000000];
bool ok = 0;
int st,en;
void dfs(int v=st){
    vis[v]=1;
    if (v==en) ok = 1;
    for (auto [u,id]:adj[v]){
        if (vis[u])continue;
        if (!ok)possibleEdges.push_back(id);
        dfs(u);
        if (!ok)possibleEdges.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m>>st>>en;
    E.push_back({{0,0},0});
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        E.push_back({{u,v},w});
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
    }
    dfs();
    if (!ok){
        cout<<0<<endl<<0<<endl;
        return 0;
    }
    int ret=2e9+1;
    int A=-1,B=-1;
    for (auto edge:possibleEdges){
        Bridges bridges;
        bridges.init(n,m);
        int cost = E[edge].second;
        for (int v=1;v<=n;v++){
            for (auto [u,id]:adj[v]){
                if (id==edge)continue;
                bridges.addEdge(u,v,id);
            }
        }
        auto cur = bridges.run(st,en);
        if (cur.first!=-1 && cur.first+cost<ret){
            ret = cost+cur.first;
            A = edge, B = cur.second;
        }
    }
    if (A==-1 && B==-1) {
        cout<<-1<<endl;
    } else {
        cout<<ret<<endl;
        if (A==-1)swap(A,B);
        if (B==-1)cout<<1<<endl<<A<<endl;
        else cout<<2<<endl<<A<<' '<<B<<endl;
    }
}