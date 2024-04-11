//https://codeforces.com/contest/1279/problem/D
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
#define narak 998244353
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
ll xymodp(ll x,ll y,ll p){
    ll a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}
int gifts[1000001]={0};
int solve(){
  ll n;cin>>n;
  
  map<int,vector<int>> mp;
  lop(i,n,1){
      int k;cin>>k;
      lop(j,k,1){
          int g;cin>>g;gifts[g]++;
          mp[i+1].pb(g);
      }
  }
  ll nu=1,du=n*n;
  //du%=narak;
  vector<pair<ll,ll>> v;
  //cout<<mp.size()<<endl;
  for(auto i:mp){
      ll sum=0;
      for(auto j:i.sc)sum+=gifts[j];
      ll k=i.sc.size();
      k=k*du;
      //k%=narak;
      ll g=__gcd(sum,k);
      v.pb({sum/g,k/g});
  }
  //du=xymodp(du,narak-2,narak);
  ll a=0;
  for(auto i:v){
      //cout<<i.fr<<" "<<i.sc<<endl;
      //i.sc=narak;
      ll k=(ll)i.fr*xymodp(i.sc,narak-2,narak);
      //k=k*du;
      a=(a+k)%narak;
  }
  //a=(a*du)%narak;
  cout<<a<<endl;
  
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