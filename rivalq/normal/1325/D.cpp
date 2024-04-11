//https://codeforces.com/contest/1325/problem/D
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
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
 ll u,v;cin>>u>>v;           
 if(u==0 && v==0){
     cout<<0<<endl;
     ret;
 }
 if(u==v){
     cout<<1<<endl<<u<<endl;ret;
 }
 if(u>v || v%2!=u%2){
     cout<<-1<<endl;ret;
 } 
 ll x1=0,x2=0;
 ll j1=u;
 ll j2=(v-u)/2;
 int f=0;
 for(int i=0;i<=63;i++){
     ll k=1LL<<i;
     if(j2&k){
         if(j1&k){
           cout<<3<<endl;
           cout<<u<<" "<<(v-u)/2<<" "<<(v-u)/2<<endl;
           ret;
         }
         else{
             x1+=k;
             x2+=k;
         }
     }
     else{
         if(j1&k){
             x1+=k;
         }
     }
 }
 cout<<2<<endl;
 cout<<x1<<" "<<x2<<endl;          
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