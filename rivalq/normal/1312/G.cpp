//https://codeforces.com/contest/1312/problem/G
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
const int N=100000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    int tin,tout;
    map<int,int>mp;
};
vector<node> t;
bool in_s[10*N+10];
vector<int> order;
int cost[10*N+10];
void dfs(int u){
   if(in_s[u]){
       order.pb(u);
   }
   t[u].tin=order.size();
   for(auto i:t[u].mp){
       dfs(i.y);
   }
   t[u].tout=order.size();
}
void dfs2(int u,int p,int dp){
    if(in_s[u]){
        cost[u]=min(cost[p]+1,t[u].tin+dp);
    }
    else{
        if(u)cost[u]=cost[p]+1;
    }
    dp = min(dp,cost[u]-t[u].tin+in_s[u]);
    for(auto i:t[u].mp){
        dfs2(i.y,u,dp);
    }
}
int solve(){
   int n;cin>>n;
   t.resize(n+1);         
   rep3(n){
       int p;char c;cin>>p>>c;
       t[p].mp[c-97]=i+1;
   } 
   int k;cin>>k;
   int ans[k];
   rep3(k){
       int temp;cin>>temp;
       ans[i]=temp;
       in_s[temp]=1;
   }
   dfs(0);
   cost[0]=0;
   dfs2(0,-1,inf1);
   for(int i=0;i<k;i++)cout<<cost[ans[i]]<<" ";cout<<endl;
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