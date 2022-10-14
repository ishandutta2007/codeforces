//https://codeforces.com/contest/1242/problem/A
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
bool isPrime(ll N){
    if(N<2)return false;
    if(N<4)return true;
    if((N&1)==0)return false;
    if(N%3==0)return false;
    ll curr=5,s=sqrt(N);
    while(curr<=s){
        if(N%curr==0)return false;
        curr+=2;
        if(N%curr==0)return false;
        curr+=4;
    }
    return true;
}
int solve(){
  ll n;cin>>n;
  int cnt=0;
  if(isPrime(n)||n==1){
      cout<<n<<endl;
      ret;
  }
  
  vector<int> p;
  if(n%2==0){
      cnt++;
      p.push_back(2);
      while(n%2==0)n=n/2;
  }
  for(int i=3;i<=sqrt(n);i+=2){
      if(n%i==0){
          cnt++;
          p.pb(i);
          while(n%i==0)n=n/i;
          if(cnt>1)break;
      }
  }
  if(n>2)cnt++,p.pb(n);

  if(cnt>1)cout<<1<<endl;
  else cout<<p[0]<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}