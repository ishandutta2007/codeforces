#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define RANGE(x) x.begin(),x.end()

template<typename num>
num gcd(num a, num b){
  return b? gcd(b,a%b):a;
}

bool one(){
  int N;
  cin>>N;
  vi vals(N);
  ll g = 1;
  for(int i=0;i<N;++i)cin>>vals[i];
  for(int i=0;i<N;++i){
    if(g>1000000000)continue;
    g = g * ((i+2)/gcd<ll>(i+2,g));
    if(vals[i]%g ==0) return false;
  }

  return true;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    cout<<(one()?"YES":"NO")<<'\n';
  }
  cout<<flush;
}