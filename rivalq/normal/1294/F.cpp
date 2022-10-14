#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int level[2*N+10];
int par[2*N+10];
int vis[2*N+10];
vector<int> g[2*N+10];
void dfs(int u=1,int p=0){
    par[u]=p;
    for(auto i:g[u]){
        if(i!=p){
            level[i]=level[u]+1;
            dfs(i,u);
        }
    }
}
int solve(){
  int n;cin>>n;          
  rep3(n-1){
      int a,b;cin>>a>>b;
      g[a].pb(b);g[b].pb(a);
  }
  dfs();
  int v1,v2;
  int ma=0;
  for(int i=1;i<=n;i++){
      if(ma<level[i]){
          ma=level[i];
          v1=i;
      }
  }
  memset(level,0,sizeof(level));
  dfs(v1,0);          
  ma=0;
  for(int i=1;i<=n;i++){
      if(ma<level[i]){
          ma=level[i];
          v2=i;
      }
  }
 
  int ans=ma;
  if(ans==n-1){
      cout<<n-1<<endl;
      cout<<v1<<" "<<v2<<" "<<par[v2]<<endl;
      ret;
  }
  queue<int> q;
  int x=v2;
  while(x!=v1){
    q.push(x);
    vis[x]=1;
    level[x]=0;
    x=par[x];
  }
  q.push(v1);
  vis[v1]=1;
  memset(level,0,sizeof(level));
  while(!q.empty()){
    int v=q.front();
    q.pop();
    vis[v]=1;
    for(auto i:g[v]){
        if(!vis[i]){
            q.push(i);
            level[i]=level[v]+1;
        }
    }
  }
  ma=0;
  int v3;
  for(int i=1;i<=n;i++){
     if(ma<=level[i]){
         ma=level[i];
         v3=i;
     }
  }
  cout<<ans+ma<<endl;
  cout<<v1<<" "<<v2<<" "<<v3<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}