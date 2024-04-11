//https://codeforces.com/problemset/problem/1312/F
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define int            long long
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
const int inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int dp[100000][3]={-1};
int x,y,z;
int mex(set<int>s){
    for(int i=0;;i++){
        if(s.count(i)==0){
            return i;
        }
    }
    return 0;
}
int m=0,c=0;
int cbrute(int n,int l){
    if(n==0 || n==1){
        return dp[n][1]=dp[n][0]=dp[n][2]=n;
    }
    if(dp[n][l]!=-1)return dp[n][l];
    set<int>s;
    int x1=cbrute(max(0LL,n-x),0);
    s.insert(x1);
    if(l!=1)s.insert(cbrute(max(0LL,n-y),1));
    if(l!=2)s.insert(cbrute(max(0LL,n-z),2));
    dp[n][l]=mex(s);
    return dp[n][l];
}
int calc(int n,int l){
    if(n<c)return cbrute(n,l);
    else return cbrute((n-c)%m+c,l);
}
signed solve(){
  memset(dp,-1,sizeof(dp));  
  int n;cin>>n>>x>>y>>z;
  int arr[n];rep3(n)cin>>arr[i];    
  int mask=0;  
  map<int,int> mp; 
  rep3(10000){
      mask=(mask<<6)|((cbrute(i,0)<<4)|(cbrute(i,1)<<2)|(cbrute(i,2)));
      mask=(((mask>>30)<<30)^mask);
      if(mp.count(mask)){
          c=mp[mask]; // after it attains perodicity;
          m=i-mp[mask]; // period
          break;
      }
      mp[mask]=i;
  }
  if(m==0 && c==0){
      cout<<"*"<<endl;ret;
  }
  int xo=0;
  rep3(n){
      xo=xo^calc(arr[i],0);
  }
  int ans=0;
  rep3(n){
      int xoo=xo^calc(arr[i],0);
      if(xoo==calc(max(0LL,arr[i]-x),0))ans++;
      if(xoo==calc(max(0LL,arr[i]-y),1))ans++;
      if(xoo==calc(max(0LL,arr[i]-z),2))ans++;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}