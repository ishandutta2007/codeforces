//https://codeforces.com/contest/1296/problem/F
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
vector<int> g[5005];
int mp[5005][5005];
int f[5005];
int p[5005][5005];
void dfs(int r,int u,int par){
    p[r][u]=par;
    for(auto i:g[u]){
        if(i!=par){
            dfs(r,i,u);
        }
    }
}
int solve(){
  int n;cin>>n;          
  rep3(n-1){
      int a,b;cin>>a>>b;
      g[a].pb(b);
      g[b].pb(a);
      mp[a][b]=i;
      mp[b][a]=i;
  }   
  for(int i=0;i<n;i++)f[i]=-1;       
  for(int i=1;i<=n;i++){
      dfs(i,i,0);
  }
  int m;cin>>m;
  int q[m][3];
  rep3(m){
      int a,b,w;cin>>a>>b>>w;
      q[i][0]=a,q[i][1]=b,q[i][2]=w;
      int x=a;
      while(x!=b){
          int v=p[b][x];
          int edge=mp[v][x];
          f[edge]=max(w,f[edge]);
          x=v;
      }
  } 
  rep3(n-1){
      if(f[i]==-1)f[i]=1e6;
  }
  rep3(m){
      int a,b,w;
      a=q[i][0],b=q[i][1],w=q[i][2];
      int x=a;
      int mi=hell;
      while(x!=b){
          int v=p[b][x];
          int edge=mp[v][x];
          mi=min(mi,f[edge]);
          x=v;
      }
      if(mi!=w){
          cout<<-1<<endl;ret;
      }
  } 
  rep3(n-1)cout<<f[i]<<" ";cout<<endl;
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