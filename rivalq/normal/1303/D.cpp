//https://codeforces.com/contest/1303/problem/D
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
 ll n,m;cin>>n>>m;    
 ll sum=0;       
 ll arr[m];rep3(m)cin>>arr[i],sum+=arr[i];
if(sum<n){
   cout<<-1<<endl;ret;
}
 ll bits[64]={0};  
 ll mask[64]={0};         
 for(int j=63;j>=0;j--){
     ll k=1LL<<j;
     for(auto i:arr){
         if(k&i)bits[j]++;
         if(k&n)mask[j]++;
     }
 }
 int ans=0;
 int i=0;
 for(int j=0;j<63;){
    if(mask[j]){
       if(bits[j]){
           bits[j]--;
           bits[j+1]+=(bits[j]/2);
           j++;
       }
       else{
           while(bits[j]==0){
               j++;
               ans++;
           } 
           bits[j]--;
       }
    } 
    else{
        bits[j+1]+=(bits[j]/2);
        j++;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}