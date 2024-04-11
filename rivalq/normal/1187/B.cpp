//https://codeforces.com/contest/1187/problem/B
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
bool ch(vector<int>a,int b[],int m){
    rep3(26){
        if(a[i]<b[i])return 0;
    }
    return 1;
}
int solve(){
 int n;cin>>n;           
 string s;cin>>s;
 int q;cin>>q;
 vector<int>v[n+1];
 rep3(n+1)v[i].resize(26,0);
 for(int i=0;i<n;i++){
     v[i+1]=v[i];
     v[i+1][s[i]-'a']++;
 }
 rep3(q){
     string t;cin>>t;
     int l=t.length();
     int u=s.length();
     int ans=u;
     int b[26]={0};
     rep3(t.length())b[t[i]-'a']++;
     while(l<=u){
         int m=(l+u)/2;
         if(ch(v[m],b,m))u=m-1,ans=m;
         else l=m+1;
     }
     cout<<ans<<endl;
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