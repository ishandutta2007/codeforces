#include<bits/stdc++.h>
using namespace std;

template<class Cap> struct MaxFlowGraph{
    struct edge{
        int from, to;
        Cap cap, flow;
    };
    MaxFlowGraph(int n): G(n), _n(n), cap_max(0){}
    int add_edge(int a, int b, Cap c){
        assert(0<=a && a<_n);
        assert(0<=b && b<_n);
        assert(0<=c);
        G[a].push_back({b, G[b].size(), edg.size(), c});
        G[b].push_back({a, G[a].size()-1, ~(int)edg.size(), 0});
        edg.push_back({a, b, c, 0});
        if(cap_max < c) cap_max = c;
        return edg.size()-1;
    }
    Cap flow(int s, int t){
        Cap res = 0;
        while(true){
            used.assign(_n, false);
            Cap fw = dfs(s, t, cap_max);
            if(fw==0)break;
            res += fw;
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
    Cap cap_max;
    std::vector<std::vector<edge_>> G;
    std::vector<edge> edg;
    std::vector<bool> used;
    Cap dfs(int v, int t, Cap f){
        if(v==t) return f;
        used[v] = true;
        for(edge_ &e:G[v]){
            if(used[e.to] || e.cap==0) continue;
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

int main(){
  constexpr int INF=1e9;
  int N,M; cin>>N>>M;
  int suma=0, sumb=0;
  vector<int> A(N),B(N);
  for(int i=0;i<N;i++)cin>>A[i],suma+=A[i];
  for(int i=0;i<N;i++)cin>>B[i],sumb+=B[i];
  if(suma!=sumb)return puts("NO"),0;
  int s=2*N,t=s+1;
  MaxFlowGraph<int> G(2*N+2);
  for(int i=0;i<N;i++)G.add_edge(s,i,A[i]);
  for(int i=0;i<N;i++)G.add_edge(N+i,t,B[i]);
  for(int i=0;i<N;i++)G.add_edge(i,N+i,INF);
  for(int i=0;i<M;i++){
    int a,b; cin>>a>>b;
    --a; --b;
    G.add_edge(a,N+b,INF);
    G.add_edge(b,N+a,INF);
  }
  if(G.flow(s,t)!=suma)return puts("NO"),0;
  vector<vector<int>> ans(N,vector<int>(N));
  for(auto e:G.edges()){
    if(e.from<0 || N<=e.from || e.to<N || 2*N<=e.to)continue;
    ans[e.from][e.to-N]=e.flow;
  }
  puts("YES");
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)cout<<ans[i][j]<<" \n"[j==N-1];
  }
}