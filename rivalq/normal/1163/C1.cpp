//https://codeforces.com/contest/1163/problem/C2
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
int solve(){
 int n;cin>>n;           
 map<vector<int>,int>mp;
 vector<pii>v;
 rep3(n){
     int a,b;cin>>a>>b;
     v.pb({a,b});
 }           
 for(int i=0;i<n;i++){
     int x1=v[i].x;
     int y1=v[i].y;
     for(int j=i+1;j<n;j++){
         if(i==j)continue;
        int x2=v[j].x;
        int y2=v[j].y;
        int a=y2-y1;
        int b=x2-x1;
        int g=gcd(a,b);
        a/=g;
        b/=g;
        if(a<0)a=-a,b=-b;
        int c=y1*(b)-x1*(a);
        mp[{a,-b,c}]++;
     }
 }  
 map<pii,int>mp2;
 for(auto i:mp){
        mp2[{i.x[0],i.x[1]}]++; 
 }
 ll sum=0;
 for(auto i:mp2)sum+=i.y;
 ll ans=0;
 for(auto i:mp2){
     ans+=i.y*(sum-i.y);
 }
 cout<<ans/2<<endl;
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