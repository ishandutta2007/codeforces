//https://codeforces.com/contest/999/problem/E
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
vector<int>g[10000];
int ch[10000];
int vis[10000];
int cnt=0;
void dfs1(int v){ 
    ch[v] = true; 
    for (auto to : g[v]) 
        if (!ch[to]) 
            dfs1(to); 
} 
  
void dfs2(int v) { 
    vis[v] = true; 
    ++cnt; 
    for (auto to : g[v]) 
        if(!vis[to] && !ch[to]) 
            dfs2(to); 
}
int solve(){
  int n,m,x;cin>>n>>m>>x;          
  rep3(m){
      int a,b;cin>>a>>b;
      g[a].pb(b);
  } 
   dfs1(x);         
   vector<pair<int,int>> val; 
   for (int i =1;i<=n;i++){ 
          if (!ch[i]) { 
            cnt = 0; 
            memset(vis, false, sizeof(vis)); 
            dfs2(i); 
            val.push_back(make_pair(cnt, i)); 
        } 
    }  
    sort(val.begin(), val.end()); 
    reverse(val.begin(), val.end());  
    int ans = 0; 
    for (auto it : val){ 
        if(!ch[it.second]) { 
            ++ans; 
            dfs1(it.second); 
        } 
    } 
    cout<<ans<<endl;
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