//https://codeforces.com/contest/609/problem/E
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define int             long long int
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
const int inf2=1e18;
const int N=200001;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
vector<pii> mst[N+10];
bool edges[N+10];
vector<pair<pii,pii>> g;
int a[N+10][3];
int p[2*N+10];
int sz[2*N+10];
int ans=0;
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}
void build_mst(int m){
   rep(i,1,N)p[i]=i,sz[i]=1; 
   for(int i=0;i<m;i++){
      int u=g[i].y.x;
      int v=g[i].y.y;
      int w=g[i].x.x;
      if(root(u)==root(v))continue;
      else {
          merge(u,v);
          mst[u].pb({v,w});
          mst[v].pb({u,w});
          edges[g[i].x.y]=1;
          ans+=w;
      }
   } 
   memset(p,0,sizeof(p));
}
int dp[N+10][21];
int b_p[N+10][21];
int level[N+10];
void dfs(int n=1,int e=0,int l=0,int w=0){
     p[n]=e;
     level[n]=l;
     dp[n][0]=w;
     for(auto i:mst[n]){
         if(i.x!=e){
             dfs(i.x,n,l+1,i.y);
         }
     }
     return;
}
void b_lift(int n){
     for(int i=0;i<=20;i++){
         for(int j=1;j<=n;j++){
             if(i==0)b_p[j][i]=p[j];
             else{
                b_p[j][i]=b_p[b_p[j][i-1]][i-1];
                dp[j][i]=max(dp[j][i-1],dp[b_p[j][i-1]][i-1]);
             }
         }
     }
     return;
}
int LCA_MAX(int u, int v){
   if(level[v]<level[u])u=v+u-(v=u);
   int diff=level[u]-level[v];
   int ans=0;
   for (int i=20;i >= 0; i--) {
        if (level[v]-level[u] >=(1 << i)) {
            ans = max(ans, dp[v][i]);
            v = b_p[v][i];
        }
   }
   if(v==u){
       return ans;
   }
   int k=ceil(log2(level[u]));
   while(k>=0){
        if(b_p[u][k]!=b_p[v][k]){
            ans=max(ans,dp[u][k]);
            ans=max(ans,dp[v][k]);
            u=b_p[u][k];
            v=b_p[v][k];
        }
        k--;
   } 
   ans=max(ans,dp[u][0]);
   ans=max(ans,dp[v][0]);
   return ans;

}
int solve(){
  int n,m;cin>>n>>m;
  rep3(m){
      int u,v,w;
      cin>>u>>v>>w;
      g.pb({{w,i},{u,v}});
      a[i][0]=w;
      a[i][1]=u;
      a[i][2]=v;
  }
  sort(all(g));
  build_mst(m);
  dfs();
  b_lift(n);
  //for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
  rep3(m){
    int u=a[i][1];
    int v=a[i][2];
    if(edges[i]){
        cout<<ans<<endl;
    }
    else{
        int max=LCA_MAX(u,v);
        cout<<a[i][0]-max+ans<<endl;
    }
  }
 ret;
}
signed main(){
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