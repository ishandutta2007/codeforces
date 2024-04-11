//https://codeforces.com/contest/1324/problem/D
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
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
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
const int inf1=1e9;
const int inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
 int n;cin>>n;           
 int a[n]={0};
 rep3(n){
     int t;cin>>t;
     a[i]+=t;
 }
 rep3(n){
     int t;cin>>t;
     a[i]-=t;
 }
 ordered_set s1;
 int ans=0;
 rep3(n){ 
     s1.insert({-a[i],inf2});
     ans+=i-s1.order_of_key({-a[i],inf2});
     s1.erase({-a[i],inf2});
     s1.insert({a[i],i});
 }
 cout<<ans<<endl;
 ret;
}
signed main(){
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