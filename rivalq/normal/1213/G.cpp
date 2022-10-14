//https://codeforces.com/contest/1213/problem/G
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
int p[2*N+10];
ll sz[2*N+10];
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
ll a=0;
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    a+=(sz[p1]*sz[p2]);
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}
ll ans[2*N+10];
int solve(){
  int n,m;cin>>n>>m; 
  vector<pair<int,pii>> g;         
  rep3(n-1){
     int a,b,w;cin>>a>>b>>w;
     g.pb({w,{a,b}});
  }          
  sort(all(g));
  for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
  for(auto i:g){
      merge(i.y.x,i.y.y);
      ans[i.x]=a;
     
  }
  for(int i=1;i<=200005;i++){
      if(ans[i]==0)ans[i]=ans[i-1];
  }
  rep3(m){
      int t;cin>>t;
      cout<<ans[t]<<" ";
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