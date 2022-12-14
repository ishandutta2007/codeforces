/*
______     _   _                               _
| ___ \   | | (_)                             | |
| |_/ /___| |_ _ _ __ ___ _ __ ___   ___ _ __ | |_
|    // _ \ __| | '__/ _ \ '_ ` _ \ / _ \ '_ \| __|
| |\ \  __/ |_| | | |  __/ | | | | |  __/ | | | |_
\_| \_\___|\__|_|_|  \___|_| |_| |_|\___|_| |_|\__|


 _____      _   _       _      ___  _ _                       _
|_   _|    | \ | |     | |    / _ \| | |                     | |
  | | ___  |  \| | ___ | |_  / /_\ \ | | _____      _____  __| |
  | |/ __| | . ` |/ _ \| __| |  _  | | |/ _ \ \ /\ / / _ \/ _` |
 _| |\__ \ | |\  | (_) | |_  | | | | | | (_) \ V  V /  __/ (_| |
 \___/___/ \_| \_/\___/ \__| \_| |_/_|_|\___/ \_/\_/ \___|\__,_|


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sz[1000000];
vector<int> adj[1000000];
bool vis[1000000];
vector<ll> f;
void pre(int v){
  vis[v]=1;
  sz[v]=1;
  for (auto u:adj[v]){
    if (vis[u])continue;
    pre(u);
    sz[v]+=sz[u];
  }
}
void dfs(int v){
  vis[v]=1;
  for (auto u:adj[v]){
    if (vis[u])continue;
    dfs(u);
    f.push_back(sz[u]*1LL*(sz[1]-sz[u]));
  }
}
ll mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      f.clear();
      for (int i=1;i<=n;i++) adj[i].clear(), vis[i]=0;
      for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      pre(1);
      for (int i=1;i<=n;i++)vis[i]=0;
      dfs(1);
      int m;
      cin>>m;
      vector<ll> vec;
      for (int i=1;i<=m;i++){
        ll x;
        cin>>x;
        vec.push_back(x);
      }
      while(vec.size()<n-1) vec.push_back(1);
      sort(vec.begin(), vec.end());
      int j = vec.size()-1;
      sort(f.begin(),f.end());
      while(vec.size() > f.size()){
        ll last = vec.back();
        vec.pop_back();
        vec[vec.size()-1] = (vec[vec.size()-1]*last)%mod;
      }
      ll ret=0;
      assert(vec.size()==f.size());
      for (int i=0;i<vec.size();i++){
          ret = (ret + (vec[i]*f[i])%mod)%mod;
      }
      cout<<ret<<endl;
    }
}