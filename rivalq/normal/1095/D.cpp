//https://codeforces.com/contest/1095/problem/D
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
 pii p[n+1];
 rep3(n){
     int a,b;cin>>a>>b;
     p[i+1].fr=a;
     p[i+1].sc=b;
 }
 if(n==3){
     cout<<"1 2 3"<<endl;
     ret;
 }
 set<int> g[n+1];
 for(int i=1;i<=n;i++){
     int a=p[i].fr;
     int b=p[i].sc;
     if(p[a].fr==b || p[a].sc==b){
         g[i].insert(a);
         g[a].insert(b);
     }
     else{
         g[i].insert(b);
         g[b].insert(a);
     }
 }
 int k=1;
 while(n--){
     cout<<k<<" ";
     k=*g[k].begin();
 }
 cout<<endl;
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