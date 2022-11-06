#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define RANGE(x) x.begin(),x.end()
ll one(){
  ll x,y;
  cin>>x>>y;
  // n mod x = y mod n
  if(x>y){
    return x+y;
  }
  if(x==y)return x;
  // take y > n>=x
  // if y > x
  // if n<x
  // y mod n = n , is not possible
  // y >n>=x
  // take n = x + (y mod x)/2
  // then (y mod x)/2 = y mod x 

  int p = (y % x)/2;
  int k = y-p;
  // k mod x is p
  // y mod x = p
  return k;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<<one()<<'\n';
  }
  cout<<flush;
}