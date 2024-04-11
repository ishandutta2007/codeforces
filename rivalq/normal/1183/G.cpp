//https://codeforces.com/contest/1183/problem/G
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
  map<int,int>mp;
  map<int,int>mp2;
  map<pii,int,greater<pii>> mp3;
  rep3(n){
      int t,f;cin>>t>>f;
      mp[t]++;
      mp2[t]+=f;
  }          
  for(auto i:mp){
      mp3[{i.y,mp2[i.x]}]++;
  }
  priority_queue<pii>pq;
  int ans=0;
  int cnt=0;
  auto itr=mp3.begin();
  for(int i=n;i>=1;i--){
      while(itr!=mp3.end() && itr->x.x>=i){
          int t=itr->y;
          while(t--)pq.push({itr->x.y,itr->x.x});
          itr++;
      }
      if(pq.empty())continue;
      ans+=i;
      cnt+=min(pq.top().x,i);
      pq.pop();
  }
  cout<<ans<<" "<<cnt<<endl;
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