//https://codeforces.com/problemset/problem/1272/E
#include<bits/stdc++.h>
#define rep1(i,n,a)    for(int i=0;i<n;i+=a)
#define rep2(i,n,a)    for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep1(i,n,1)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define trav(a,x)      for(auto x:a)
#define endl           "\n"
#define eb             emplace_back
#define fr             first
#define sc             second
#define gcd(a,b)       __gcd(a,b)
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)         (int)a.size()
#define pii            pair<int,int>
#define psi            pair<string,int>
#define pss            pair<string,string>
#define pll            pair<ll,ll>
#define vec            vector<int>
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
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
 int n;cin>>n;
 int arr[n+1];
 rep3(n)cin>>arr[i+1];
 vector<int>g[n+1];
 for(int i=1;i<=n;i++){
     if(i-arr[i]>=1)g[i-arr[i]].pb(i);
     if(i+arr[i]<=n)g[i+arr[i]].pb(i);
 }
 int p[n+1];
 multiset<pii> pq;
 int dis[n+1];
 rep1(i,n+1,1)dis[i]=inf1;
 for(int i=1;i<=n;i++){
     p[i]=arr[i]%2;
     if(p[i])pq.insert({0,i}),dis[i]=0;
 }
 int vi[n+1]={0};
 while(!pq.empty()){
       pii v=*pq.begin();
       pq.erase(pq.begin());
       int node=v.sc;
       int wei=v.fr;
       if(vi[node])continue;
       vi[node]=1;
       for(auto i:g[node]){
           int e=i;
           int w=1;
           if(dis[node]+w<dis[e]){
               dis[e]=dis[node]+w;
               pq.insert({dis[e],e});
           }
       }
 }
 int dis2[n+1];
 int vi2[n+1]={0};
 for(int i=1;i<=n;i++){
     if(p[i]==0)pq.insert({0,i}),dis2[i]=0;
     else dis2[i]=inf1;
 }
 while(!pq.empty()){
       pii v=*pq.begin();
       pq.erase(pq.begin());
       int node=v.sc;
       int wei=v.fr;
       if(vi2[node])continue;
       vi2[node]=1;
       for(auto i:g[node]){
           int e=i;
           int w=1;
           if(dis2[node]+w<dis2[e]){
               dis2[e]=dis2[node]+w;
               pq.insert({dis2[e],e});
           }
       }
 }
 for(int i=1;i<=n;i++){
    if(p[i]){
        if(vi2[i])cout<<dis2[i]<<" ";
        else cout<<-1<<" ";
    }
    else{
        if(vi[i])cout<<dis[i]<<" ";
        else cout<<-1<<" ";
    }
 }
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}