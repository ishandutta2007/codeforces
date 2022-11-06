#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n);
  vector<ll> v(n);
  for(int i=0;i<n;++i){
    cin>>v[i];
  }
  for(int i=0;i<n;++i){
    int k;
    cin>>k;
    v[i]-=k;
  }
  while(m-->0){
    int a,b;
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> sta;
  vector<int> color(n,-1);
  sta.push_back(0);
  color[0]=0;
  ll sums [2];
  sums[0]=sums[1]=0;
  bool bipartite=true;
  while(!sta.empty()){
    int x = sta.back();
    sums[color[x]]+=v[x];
    sta.pop_back();
    for(int j: g[x]){
      if(color[j]>=0){
        bipartite &= color[j]!=color[x];
      }
      else{
        color[j]=1-color[x];
        
        sta.push_back(j);
      }
    }
  }
  cout<< (( bipartite?sums[0]==sums[1]: (((sums[0]+sums[1])&1) ==0) )?
          "YES\n":"NO\n");
  //cout<<"REEE";
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