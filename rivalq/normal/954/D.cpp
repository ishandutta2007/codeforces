//https://codeforces.com/problemset/problem/954/D
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
int level1[10000];
int level2[10000];
vector<int>g[10000];
void bfs(int s,int level[],int n){
    int vis[n+1]={0};
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        vis[v]=1;
        q.pop();
        for(auto i:g[v]){
           if(!vis[i]){
               level[i]=1+level[v];
               q.push(i);
               vis[i]=1;
           }
        }
    }
}
int solve(){
 int n,m,s,t;cin>>n>>m>>s>>t;
 map<pii,int>mp;
 rep3(m){
     int a,b;cin>>a>>b;
     g[a].pb(b);
     g[b].pb(a);
     mp[{min(a,b),max(a,b)}]=1;
 }           
 bfs(s,level1,n);
 bfs(t,level2,n);
 int cnt=0;
 for(int i=1;i<=n;i++){
     for(int j=i+1;j<=n;j++){
         if(mp.count({i,j}))continue;
         int val1=level1[i]+level2[j]+1;
         int val2=level1[j]+level2[i]+1;
         if(min(val1,val2)>=level1[t])cnt++;
     }
 }           
 cout<<cnt<<endl;
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