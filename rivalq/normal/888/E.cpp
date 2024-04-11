//https://codeforces.com/contest/888/problem/E
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
set<ll>s1,s2;
vector<ll>v1,v2;
int n,m;
void process(vector<ll>&v1,set<ll>&s1){
  int sz=sz(v1);
  for(int i=0;i<(1<<sz);i++){
      ll sum=0;
      for(int j=0;j<sz;j++){
          if((1<<j)&i)sum=(sum+v1[j])%m;
      }
      s1.insert(sum);
  }
}
int solve(){
  cin>>n>>m;          
  rep3(n/2){
      int t;cin>>t;v1.pb(t);
  }          
  rep3(n-n/2){
      int t;cin>>t;v2.pb(t);
  }
  process(v1,s1);
  process(v2,s2);
  ll ans=max(*s1.rbegin(),*s2.rbegin());
  for(auto i:s1){
      ll val1=m-i-1;
      ll val2=2*m-1-i;
      auto itr1=s2.upper_bound(val1);
      itr1--;
      ans=max(ans,(i+*itr1)%m);
      auto itr2=s2.upper_bound(val2);
      itr2--;
      ans=max(ans,(i+*itr2)%m); 
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}