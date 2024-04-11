//https://codeforces.com/contest/1183/problem/E
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
 int n,k;cin>>n>>k;
 map<string,int> mp;
 string s;cin>>s;
 queue<string> q;
 q.push(s);
 mp[s]=0;
 while(!q.empty()){
     string v=q.front();
     q.pop();
     if(mp.size()==k)break;
     int l=v.length();
     for(int i=0;i<l;i++){
         string t=v.substr(0,i)+v.substr(i+1,l-i-1);
         if(mp.count(t)==0){
             mp[t]=mp[v]+1;
             q.push(t);
             if(mp.size()==k)goto x;
         }
     }
 }
 x:
 if(mp.size()<k){
     cout<<-1<<endl;ret;
 }
 int ans=0;
 for(auto i:mp)ans+=i.y;
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}