//https://codeforces.com/contest/1156/problem/D
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
vector<pii>g[N+1];
ll dp1[N+1][2];
ll dp2[N+1][2];
void dfs1(int u=1,int p=0){
    for(auto i:g[u]){
        if(i.x!=p){
          dfs1(i.x,u); 
          if(i.y==1){
              dp1[u][1]+=(1+dp1[i.x][1]);
          }
          else{
              dp1[u][0]+=(1+dp1[i.x][0]+dp1[i.x][1]);
          }
        }
    }
}
void dfs2(int u=1,int p=0,ll cnt1=0,ll cnt2=0){
    dp2[u][0]=dp1[u][0]+cnt1;
    dp2[u][1]=dp1[u][1]+cnt2;
    for(auto i:g[u]){
        if(i.x!=p){
            if(i.y==1)dfs2(i.x,u,0,dp2[u][1]-dp1[i.x][1]);
            else dfs2(i.x,u,dp2[u][0]+dp2[u][1]-dp1[i.x][0]-dp1[i.x][1],0);
        }
    }
}
int solve(){
  int n;cin>>n;
  rep3(n-1){
      int a,b,c;cin>>a>>b>>c;
      g[a].eb(b,c);
      g[b].eb(a,c);
  }          
  dfs1();
  dfs2();
  ll sum=0;
  //for(int i=1;i<=n;i++)cout<<dp2[i][0]<<" "<<dp2[i][1]<<endl;
  for(int i=1;i<=n;i++)sum+=dp2[i][0]+dp2[i][1];
  cout<<sum<<endl;          
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