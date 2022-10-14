//https://codeforces.com/contest/1173/problem/D
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=200000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll dp[N+1];
vector<int>g[N+1];
#define cat
ll dp2[N+1];
ll fact[N+1],infact[N+1];
ll xymodp(ll x,ll y,ll p){
    ll a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}
int n;
void init(){
    fact[0]=1;
    rep(i,1,200001)fact[i]=(i*fact[i-1])%narak;
    rep(i,1,200001)infact[i]=xymodp(fact[i],narak-2,narak);
    infact[0]=1;infact[1]=1;
}
void dfs1(int u=1,int p=0){
    dp[u]++;
    for(auto i:g[u]){
        if(i!=p){
          dfs1(i,u);
          dp[u]=dp[u]*dp[i]%narak;
        }
    }
    ll k=(u==1)?fact[sz(g[u])]:fact[sz(g[u])-1];
    dp[u]=dp[u]*k%narak;
    k=(u==1)?n:sz(g[u]);
    dp[u]=dp[u]*k%narak;
}

int solve(){
  cin>>n;          
 rep3(n-1){
     int a,b;cin>>a>>b;
     g[a].pb(b);
     g[b].pb(a);
 }          
 ll ans=0;
 dfs1();
 cout<<dp[1]<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}