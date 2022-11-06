#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1000000007;
#define RANGE(x) x.begin(),x.end()
template<typename num>
num gcd(num a, num b, num& x, num& y){
  if(b == 0){
    x=1;
    y=0;
    return a;
  }
  num d = gcd(b,a%b,x,y);
  num temp = x;
  x=y;
  y=temp-y*(a/b);
  return d;
}
template<typename num>
num modinv(num a, num m){
  num x,y;
  assert(1==gcd(a,m,x,y));
  return (x+m)%m;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>>n;
  ll res=0;
  ll facts[1000001];
  facts[0]=1;
  for(int i=1;i<=n;++i){
    facts[i]=(facts[i-1]*i)%M;
    //cout<<i<<" "<<facts[i]<<endl;
  }
  
  // result is filling in in any order, blocking 2 at a time, literally doesn't matter how you play the winner is set.
  // fix empty spaces, permute afterward
  for(int k=n%2;k*2<=n;k+=2){
    // ways to pick blank spaces is (not first) (n-1 -(k-1) choose k) + (n-3-(k-2) choose k-1)
    // n-k choose k + n-k-1 choose k-1
    // times n-k!
    ll numways =(((facts[n-k]*modinv<ll>(facts[k],M))%M)*modinv<ll>(facts[n-k*2],M))%M;
    res += numways*facts[n-1-k]%M;
    res%=M;
  }
  cout<<(M+((2*res*n)%M))%M<<endl;
}