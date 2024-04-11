//https://codeforces.com/problemset/problem/432/D
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
vector<int> z_function(string s) {
    int n=s.length();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;++i) {
        if (i<=r)z[i]=min(r-i+1,z[i-l]);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}
int solve(){
 map<int,pii>mp; 
 string s;cin>>s;
 vector<int>z=z_function(s); 
 int n=s.length();
 mp.insert({n,{0,1}});          
 int cnt=1;
 int sz=1;
 for(int i=1;i<n;i++){
   if(z[i]==n-i){
       cnt++;
       mp[z[i]].y=1;
   }
   if(z[i])mp[z[i]].x++,sz++;
 }
 if(cnt==0){
     cout<<0<<endl;ret;
 }
 int d=0;
 cout<<cnt<<endl;
 for(auto i:mp){
     if(i.y.y){
         cout<<i.x<<" "<<sz-d<<endl;
     }
     d+=i.y.x;
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