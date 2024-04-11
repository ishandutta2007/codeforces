#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
const ll mod = 1000000007;
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
ll equ(vector<ll>& win,  vector<vector<ll>>& others, int K){
  vector<ll> probs(1<<K,1);// probability that we beat the entirety of this subset directly just within this subset
  vector<vector<ll>> prodsum(K,vector<ll>(1<<K,0));
  for(int j=0;j<K;++j){
    prodsum[j][0]= mod+1-win[j];
    for(int i=1;i<(1<<K);++i){
      int p =  __builtin_ctz(i);
      assert((i>>p)&1);
      prodsum[j][i] = (prodsum[j][ i-(1<<p)]*others[j][p])%mod;
    }
  }
  for(int i=1;i<(1<<K);++i){
    // probs i is 1 - sum(prob there is some subset we completely beat which fully loses
    // we definitely beat 1
    ll res = 1;
    for(int j=(i-1)&i;;j=(j-1)&i){
      // this set's mult - that set's mult
      ll pf = 1;
      for(int p=0;p<K;++p){
        if(((i-j)>>p)&1){
          // i is not set but p is
          pf *= prodsum[p][j];
          pf%=mod;
        }
      }
      res-=(pf*probs[j]%mod);
      res%=mod;
      if(j==0)break;
    }
    probs[i]=res;
    //cerr<<i<<" "<<probs[i]<<endl;
  }
  return probs[(1<<K)-1];
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;++i){
    cin>>A[i];
  }
  vector<vector<ll>> ps(N,vector<ll>(N,0));
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j)ps[i][j] = (A[i]*modinv<ll>(A[i]+A[j],mod))%mod;
  }
  ll res = 0;
  for(int spec=0;spec<N;++spec){
    vector<vector<ll>> temp(N-1,vector<ll>(N-1,0));
    for(int j=0;j<N-1;++j){
      for(int i=0;i<N-1;++i){
        temp[i][j] = ps[i+(i>=spec)][j+(j>=spec)]; 
      }
    }
    vector<ll> spwins(N-1);
    for(int i=0;i<N-1;++i){
      spwins[i] = ps[spec][i+(i>=spec)]; 
    }
    res += equ(spwins,temp,N-1);
  }
  
  cout<<((res%mod)+mod)%mod<<endl;
}