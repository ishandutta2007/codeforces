//https://codeforces.com/contest/825/problem/D
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
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
bool ch(ll a[],ll b[],ll cnt,ll m){
    ll cnt2=0;
    rep3(26){
        if(a[i]>=m*b[i])continue;
        else cnt2+=(m*b[i]-a[i]);
    }
    return cnt>=cnt2;
}
int solve(){
 string s,t;cin>>s>>t;           
 int cnt=0;
 ll a[26]={0};
 ll b[26]={0};
 int n=s.length();
 int m=t.length();
 queue<int>idx;
 rep3(n){
     if(s[i]=='?')cnt++,idx.push(i);
     else a[s[i]-'a']++;
 }           
 rep3(m)b[t[i]-'a']++;
 int l=0;
 int u=1000000;
 ll ans=0;
 while(l<=u){
     ll m=(l+u)/2;
     if(ch(a,b,cnt,m))l=m+1,ans=m;
     else u=m-1;
 }
 rep3(26){
   int req=ans*b[i]-a[i];
   if(req<=0)continue;
   while(req>0){
       if(idx.empty()){
           cout<<"fault"<<endl;
           ret;
       }
       s[idx.front()]='a'+i;
       idx.pop();
       req--;
   }
 }
 while(!idx.empty()){
     s[idx.front()]='a';
     idx.pop();
 }
 cout<<s<<endl;
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