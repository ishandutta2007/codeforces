//https://codeforces.com/contest/1328/problem/E
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
const int N=200010;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
vector<int> g[N+1];
int p[N+1];
int b_p[N+1][21];
int level[N+1];
int dp[N+1][21];
void dfs(int n=1,int e=0,int l=0){
     p[n]=e;
     level[n]=l;
     for(auto i:g[n]){
         if(i!=e){
             dfs(i,n,l+1);
         }
     }
     return;
}
void b_lift(int n){
     for(int i=0;i<=20;i++){
         for(int j=1;j<=n;j++){
             if(i==0)b_p[j][i]=p[j];
             else b_p[j][i]=b_p[b_p[j][i-1]][i-1];
         }
     }
     return;
}
int LCA(int u, int v){
   if(level[v]<level[u])u=v+u-(v=u);
   for (int i=20;i >= 0; i--) {
        if (level[v]-level[u] >=(1 << i)) {
            v = b_p[v][i];
        }
   }
   if(v==u){
       return u;
   }
   int k=ceil(log2(level[u]));
   while(k>=0){
        if(b_p[u][k]!=b_p[v][k]){
            u=b_p[u][k];
            v=b_p[v][k];
        }
        k--;
   } 
   return p[u];

}
int solve(){
  int n,m;cin>>n>>m;           
  rep3(n-1){
      int a,b;cin>>a>>b;
      g[a].pb(b);
      g[b].pb(a);
  }          
  dfs();
  b_lift(n);
  rep3(m){
      int k;cin>>k;
      vector<pii> v;
      for(int j=0;j<k;j++){
          int t;cin>>t;
          v.pb({level[p[t]],p[t]});
      }
      sort(all(v));
      int f=0;
      for(int j=0;j<k-1;j++){
          //cout<<v[j].y<<" "<<v[j+1].y<<endl;
          if(LCA(v[j].y,v[j+1].y)!=v[j].y){
              f=1;break;
          }
      }
      if(f==1)cout<<"NO"<<endl;
      else cout<<"YES"<<endl;
  }
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