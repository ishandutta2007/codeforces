#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
ll x,y,a,b;
ll maxi(ll v){
  return v+min((x-a*v)/b,(y-b*v)/a); 
}
ll ternarymax(ll l, ll r){
  ll m1 = (r+2*l) / 3;
  ll m2 = (l+2*r) / 3;

  ll r1 = maxi(m1);
  ll r2 = maxi(m2);
  if(r-l>2){ 
    if(r1>r2){
      return ternarymax(l,m2);
    }
    else return ternarymax(m1,r);
  }
  return max(max(maxi(l),maxi(r)),max(r1,r2));
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cin>>x>>y>>a>>b;
    if(b<a)swap(a,b);
    if(y<x)swap(x,y);
    int res = 0;
    // ma+nb <=x, na+mb<=y
    // (m+n)(a+b)<=x+y
    // (m-n)(a-b) approx x-y
    ll initial = min(x/a,y/b);
    if(a==b)cout<<initial<<"\n";
    else {
      ll v = min(initial,(y*b-x*a)/(b*b-a*a)-2);
      v = max(v,0ll);
      ll v2 = v + 4;
      
      ll maxi = min(x/a,y/b);
      //cout<<v<<" "<<v2<<" "<<initial<<endl;
      while(v<=initial && v<=v2){
	maxi = max(maxi,
		   v+ min((y-v*b)/a,(x-v*a)/b));
	++v;
      }
      cout<<maxi<<"\n";
    }
  }
  cout<<flush;
}