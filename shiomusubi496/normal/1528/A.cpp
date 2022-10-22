#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,l[100000],r[100000];
pair<ll,ll>dfs(int v,int p,const vector<vector<int>>&G){
  ll suma=0,sumb=0;
  for(int t:G[v])if(t!=p){
    auto[a,b]=dfs(t,v,G);
    suma+=max(a+abs(l[v]-l[t]),b+abs(l[v]-r[t]));
    sumb+=max(a+abs(r[v]-l[t]),b+abs(r[v]-r[t]));
  }
  return{suma,sumb};
}
int main(){
  int t; scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",l+i,r+i);
    vector<vector<int>> G(n);
    for(int i=0;i<n-1;i++){
      int a,b; scanf("%d%d",&a,&b);
      G[--a].push_back(--b);
      G[b].push_back(a);
    }
    auto[a,b]=dfs(0,-1,G);
    printf("%lld\n",max(a,b));
  }
}