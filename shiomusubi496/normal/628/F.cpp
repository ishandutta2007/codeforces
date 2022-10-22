#include<bits/stdc++.h>
using namespace std;

template<class Cap> struct Dinic{
    struct edge{
        int from, to;
        Cap cap, flow;
    };
    Dinic() = default;
    Dinic(int n): _n(n), fsum(0), cap_max(0), G(n){}
    int add_edge(int a, int b, Cap c){
        assert(0<=a && a<_n);
        assert(0<=b && b<_n);
        assert(0<=c);
        G[a].push_back({b, (int)G[b].size(), (int)edg.size(), c});
        G[b].push_back({a, (int)G[a].size()-1, ~(int)edg.size(), 0});
        edg.push_back({a, b, c, 0});
        if(cap_max < c) cap_max = c;
        return edg.size()-1;
    }
    Cap flow(int s, int t){
        Cap &res = fsum;
        while(true){
            bfs(s);
            if(level[t]==-1) break;
            iter.assign(_n, 0);
            while(true){
                Cap fw = dfs(s, t, cap_max);
                if(fw==0) break;
                res += fw;
            }
        }
        return res;
    }
    std::vector<edge> edges(){return edg;}
    edge get_edge(int k){return edg[k];}
    private:
    struct edge_{
        int to, rev, id;
        Cap cap;
    };
    int _n;
    Cap fsum, cap_max;
    std::vector<std::vector<edge_>> G;
    std::vector<edge> edg;
    std::vector<int> level;
    std::vector<int> iter;
    void bfs(int s){
        level.assign(_n, -1); level[s] = 0;
        std::queue<int> Q; Q.push(s);
        while(!Q.empty()){
            int v = Q.front(); Q.pop();
            for(edge_ e: G[v]){
                if(e.cap>0 && level[e.to]==-1){
                    level[e.to] = level[v]+1;
                    Q.push(e.to);
                }
            }
        }
    }
    Cap dfs(int v, int t, Cap f){
        if(v==t) return f;
        for(int &i=iter[v]; i<(int)G[v].size(); i++){
            edge_ &e = G[v][i];
            if(e.cap==0 || level[e.to]<=level[v]) continue;
            Cap fw = dfs(e.to, t, std::min<Cap>(f, e.cap));
            if(fw==0) continue;
            e.cap -= fw;
            G[e.to][e.rev].cap += fw;
            if(e.id<0) edg[~e.id].flow -= fw;
            else edg[e.id].flow += fw;
            return fw;
        }
        return 0;
    }
};

using ll=long long;
constexpr ll INF=1e18;
int main(){
  int n,b,q; cin>>n>>b>>q;
  vector<pair<int,int>> u(q+2);
  u[q+1]={b,n};
  for(int i=1;i<=q;i++)cin>>u[i].first>>u[i].second;
  sort(u.begin(),u.end());
  for(int i=0;i<=q;i++){
    if(u[i].second>u[i+1].second)return puts("unfair"),0;
  }
  Dinic<ll> g(q+8);
  int s=q+6,t=q+7;
  for(int i=0;i<=q;i++){
    g.add_edge(s,i,u[i+1].second-u[i].second);
    for(int j=1;j<=5;j++)g.add_edge(i,q+j,(u[i+1].first+j)/5-(u[i].first+j)/5);
  }
  for(int i=1;i<=5;i++)g.add_edge(q+i,t,n/5);
  puts(g.flow(s,t)==n?"fair":"unfair");
}