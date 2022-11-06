#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll gcd(ll a, ll b, ll& x, ll& y){
  if(b == 0){
    x=1;
    y=0;
    return a;
  }
  ll d = gcd(b,a%b,x,y);
  ll temp = x;
  x=y;
  y=temp-y*(a/b);
  return d;
}
ll inv(ll a, ll m){
  ll x,y;
  assert(1==gcd(a,m,x,y));
  return (x+m)%m;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    ll res=2;
    ll n,k;
    cin>>n>>k;
    ll curr = 1;
    for(ll m=2;(m-1)*k+1<=n;++m){
      // add the n choose m
      for(ll j=n-(m-2)*(k-1);j>n-(m-1)*(k-1);--j){
	curr*=inv(j,MOD);
	curr%=MOD;
      }
      for(ll j=n-(m-2)*k-1;j>n-(m-1)*k-1;--j){
	curr*=j;
	curr%=MOD;
      }
      //cout<<curr<<endl;
      curr*=inv(n-m+1,MOD);
      curr%=MOD;
      res+=curr;
      res%=MOD;
      //cout<<curr<<endl;
    }
    cout<<(res+MOD)%MOD<<"\n";
  }
  cout<<flush;
}