//https://codeforces.com/problemset/problem/954/E
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
bool ch(long double k,vector<int>&v){
    int n=sz(v);
    rep3(n)k-=v[i];
    return k<=0;
}
int solve(){
  ll n,t;cin>>n>>t;          
  ll a[n],temp[n];
  vector<pair<long double,long double>>v1,v2;
  rep3(n)cin>>a[i];
  rep3(n)cin>>temp[i];
  long double ans=0;
  long double m1=0,m2=0;
  rep3(n){
      if(temp[i]>t){
          v1.eb(temp[i]-t,a[i]);
          m1+=a[i]*(temp[i]-t);
      }
      else if(temp[i]==t){
          ans+=a[i];
      }
      else{
          v2.eb(t-temp[i],a[i]);
          m2+=a[i]*(t-temp[i]);
      }
  }
  if(m1>m2){
      for(auto i:v2)ans+=i.y;
      sort(all(v1));
      for(auto i:v1){
          if(i.x*i.y<=m2){
              ans+=i.y;
              m2-=i.x*i.y;
          }
          else{
              ans+=(m2/i.x);
              break;
          }
      }
  }
  else{
    for(auto i:v1)ans+=i.y;
    sort(all(v2));
    for(auto i:v2){
          if(i.x*i.y<=m1){
              ans+=i.y;
              m1-=i.x*i.y;
          }
          else{
              ans+=(m1/i.x);
              break;
          }
      }
  }
  cout<<fixed<<setprecision(15)<<ans<<endl;
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