//https://codeforces.com/contest/1037/problem/D
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
 vector<int> g[n+1];
 rep3(n-1){
     int a,b;cin>>a>>b;
     g[a].pb(b);
     g[b].pb(a);
 }
 queue<int> q;
 vector<int> q1;
 rep3(n){
     int a;cin>>a;
     q1.pb(a);
 }
 vector<int> q2;
 q.push(1);
 int i=1;
 int vi[n+1]={0};
 vi[0]=1;
 g[1].pb(0);
 while(!q.empty()){
   int v=q.front();
   q.pop();
   vi[v]=1;
   priority_queue<int> p1,p2;
   for(auto i:g[v]){
       if(!vi[i]){
          p1.push(i);
          vi[i]=1;
          //cout<<i<<" ";
       }
   }
   //cout<<endl;
   for(int j=0;j<g[v].size()-1;j++){
       p2.push(q1[i]);
       q.push(q1[i]);
       //cout<<q1[i]<<" ";
       i++;
   }
   //cout<<endl;
   if(p1.size()!=p2.size()){
       cout<<"No"<<endl;
       ret;
   }
   while(!p1.empty()){
       int v1=p1.top();
       int v2=p2.top();
       p1.pop();p2.pop();
       if(v1!=v2){
           cout<<"No"<<endl;ret;
       }
   }
 }
 cout<<"Yes"<<endl;
   
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