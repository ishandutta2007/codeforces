//https://codeforces.com/contest/1092/problem/F
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
const int N=200000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int arr[N+5];
vector<int>g[N+5];
ll dp1[N+5];
ll dp2[N+5];
int dist[N+5];  
ll dp3[N+5];
ll ma=0;
int n;
ll s=0;
void dfs1(int u=1,int p=0,int l=0){
     dist[u]=l;
     for(auto i:g[u]){
         if(i!=p){
           dfs1(i,u,l+1);
           dp3[u]+=(dp3[i]+arr[i]);
           dp1[u]+=dp1[i];
         }
     }
     dp1[u]+=dp3[u];
}
void dfs2(int u=1,int p=0,ll cnt=0){
     dp2[u]=dp1[u]+cnt;
     ma=max(ma,dp2[u]);
     for(auto i:g[u]){
         if(i!=p){
             ll k=dp2[u]-dp1[i]-(dp3[i]+arr[i])+(s-dp3[i]-arr[i]);
             dfs2(i,u,k);
         }
     }
}   
int solve(){
 cin>>n;
 rep3(n)cin>>arr[i+1]; 
 rep3(n)s+=arr[i+1];  
 rep3(n-1){
     int a,b;cin>>a>>b;
     g[a].pb(b);
     g[b].pb(a);
 } 
 dfs1();
 dfs2();
 //for(int i=1;i<=n;i++)cout<<dp1[i]<<" ";cout<<endl;
 cout<<ma<<endl;  
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