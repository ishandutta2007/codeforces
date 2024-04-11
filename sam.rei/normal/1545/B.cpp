#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
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

#define RANGE(x) x.begin(),x.end()
void one(){
  int N;
  string s;
  cin>>N>>s;
  // see if there's two together
  
  // see free left
  // free right
  // everything else can be just whatever bookended by 2 1s
  int c0 =0;
  int g1= 0;
  bool found1 = false;
  for(char c:s){
    if(c=='0'){
      ++c0;
      found1=false;
    }
    if(c=='1'){
      if(found1){
        ++g1;
        found1=false;
      }
      else{
        found1=true;
      }
    }
  }
  // answer is g1 + c0 choose g1
  ll top = 1;
  ll bot = 1;
  for(int i=1;i<=c0;++i){
    bot*=i;
    bot%=mod;
    top*=g1+i;
    top%=mod;
  }
  ll res = top*modinv<ll>(bot,mod) %mod;
  cout<<res<<endl;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}