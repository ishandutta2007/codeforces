#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
bool dfs(int n, vector<bool>& marked, int& nl,int & nb, vector<vector<int>>& adj){
  marked[n] = true;
  bool hasleaf = false;
  for(int k : adj[n]){
    if(marked[k])continue;
    hasleaf |= dfs(k,marked,nl,nb,adj);
  }
  if(!hasleaf) ++nl;
  else ++nb;
  return !hasleaf;
}
void one(){
  int N;
  cin>>N;
  vector<vector<int>> adj(N);
  for(int i=0;i<N-1;++i){
    int u,v;
    cin>>u>>v;
    --u;--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // run dfs to determine number of bud groups after all buds are removed
  vector<bool> marked(N,false);
  marked[0] = true;
  int nb = 0;
  int nl = 0;
  //for(int k : adj[0]){
  if(dfs(0,marked,nl,nb,adj)){
    
  }
  else {
    --nb;
  }
    //}
  //cerr<<nl<<"nl"<<nb<<endl;
  cout<<max(1, nl-nb )<<'\n';
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}