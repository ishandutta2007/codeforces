#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

// cpalgs scc
const int maxnm=400000;
vector<vector<int>> adj(maxnm), adj_rev(maxnm);
vector<bool> used(maxnm);
vector<bool> used2(maxnm);
vector<int> order, component;

void add_edge(int a,int b){
  adj[a].push_back(b);
  adj_rev[b].push_back(a);
}
void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used2[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (used[u] && !used2[u])
            dfs2(u);
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N,M;
  cin>>N>>M;
  vector<string> vec(N);
  vector<int> mins(M,N);
  for(int i=0;i<N;++i){
    cin>>vec[i];
    for(int j=0;j<M;++j){
      
      if(i<N-1){
	add_edge(i*M+j,(i+1)*M+j);
      }
      if(vec[i][j]=='#'){
	if(i>0){
	  //add_edge(i*M+j,(i-1)*M+j);
	  if(vec[i-1][j]=='#'){
	    // connect up to this
	    add_edge(i*M+j,(i-1)*M+j);
	  }
	}
	if(j>0){
	  add_edge(i*M+j-1,i*M+j);
	}
	if(j<M-1){
	  add_edge(i*M+j+1,i*M+j);
	}
      }
    }
  }
  mins.push_back(N);
  int n = N*M;
  used.assign(n, false);
  
  for (int i = 0; i < n; i++){
    int y = i/M;
    int x= i%M;
    if(vec[y][x]!='#')continue;
    if (!used[i])
      dfs1(i);
  }
  used2.assign(n, false);
  reverse(order.begin(), order.end());
  vector<int> roots(n, 0);
  vector<int> root_nodes;
  vector<vector<int>> adj_scc(n);
  
  for (auto v : order)
    if (!used2[v]) {
      dfs2(v);

      int root = component.front();
      for (auto u : component) roots[u] = root;
      root_nodes.push_back(root);
      
      component.clear();
    }
  
  
  for (int v = 0; v < n; v++){
    if(!used[v])continue;
    for (auto u : adj[v]) {
      int root_v = roots[v],
	root_u = roots[u];
      
      if (root_u != root_v)
	adj_scc[root_u].push_back(root_v);
    }
  }
  int res =0;
  for(int i : root_nodes){
    if(adj_scc[i].size()==0)++res;
  }
  
  cout<<res<<endl;
}