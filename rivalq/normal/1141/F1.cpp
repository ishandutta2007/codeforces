//https://codeforces.com/contest/1141/problem/F2
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
int solve(){
 int n;cin>>n;           
 int a[n+1]={0};
 ll dp[n+1][n+1]={0};
 ll pre[n+1]={0};
 for(int i=0;i<=n;i++){
     a[i]=pre[i]=0;
     for(int j=0;j<=n;j++)dp[i][j]=0;
 }
 map<ll,vector<pii>>mp;
 rep3(n){
     int t;cin>>t;
     a[i+1]=t;
     pre[i+1]=a[i+1]+pre[i];
 }           
 for(int i=1;i<=n;i++){
     for(int j=i;j<=n;j++){
         dp[i][j]=pre[j]-pre[i-1];
         mp[dp[i][j]].pb({j,i});
     }
 }
 vector<pii> v;
 for(auto i:mp){
     int l=-1;
     vector<pii> temp;
     sort(all(i.y));
     for(auto j:i.y){
        if(j.y>l){
            temp.pb({j.y,j.x});
            l=j.x;
        }
     }
    if(temp.size()>v.size()){
        v=temp;
    } 
 }
 cout<<sz(v)<<endl;
 for(auto i:v){
     cout<<i.x<<" "<<i.y<<endl;
 }
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