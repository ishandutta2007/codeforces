#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
const int INF = 900000;
int dfs(int j, vector<int>& time, vector<bool>& seen, vector<vector<int>>& adj){
  if(seen[j]){
    return time[j];
  }
  seen[j] = true;
  int t = 0;
  for(int k:adj[j]){
    int t2 = dfs(k,time,seen,adj);
    if(k>j){
      ++t2;
    }
    t = max(t,t2);
  }
  return time[j] = t;
}
void one(){
  int N;
  cin>>N;
  vector<vector<int>> adj(N);
  vector<int> time(N,INF);
  vector<bool> seen(N,false);
  for(int i=0;i<N;++i){
    int k;
    cin>>k;
    if(k==0){
      time[i] = 1;
      seen[i] = true;
    }
    while(k-->0){
      int j;
      cin>>j;
      --j;
      adj[i].push_back(j);
    }
  }
  for(int i=0;i<N;++i){
    if(!seen[i]){
      int res = dfs(i,time,seen,adj);
      if(res >= INF){
        cout<<"-1\n";
        return;
      }
    }
  }
  int ma = 1;
  for(int j:time)ma = max(j,ma);
  cout<<ma<<'\n';
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