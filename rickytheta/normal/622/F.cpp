#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

ll powmod(ll a,ll b){
  ll r = 1;
  while(b){
    if(b&1)r=r*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return r;
}

ll inv(ll x){
  return powmod(x,MOD-2);
}

ll fact[1141919];
ll fval[1141919];

int main(){
  // f(x) := 1^k + 2^k + ... + x^k
  ll n,k;
  cin>>n>>k;
  fval[0] = 0;
  REPR(i,k+2){
    fval[i] = fval[i-1];
    fval[i] += powmod(i,k);
    fval[i] %= MOD;
  }
  if(n<=k+1){
    cout<<fval[n]<<endl;
    return 0;
  }

  ll prod = 1;
  REP(i,k+2){
    prod *= (n-i);
    prod %= MOD;
  }

  fact[0] = 1;
  REPR(i,1141919){
    fact[i] = fact[i-1]*i%MOD;
  }

  ll ans = 0;
  REP(i,k+2){
    ll l = prod;
    l *= inv(n-i);
    l %= MOD;
    l *= inv(fact[i]);
    l %= MOD;
    l *= inv(fact[k+1-i]);
    l %= MOD;
    if((k+1-i)%2==1) l *= -1;
    ans += fval[i] * l;
    ans = FIX(ans);
  }

  cout<<ans<<endl;
  return 0;
}