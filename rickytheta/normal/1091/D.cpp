#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

// mod
const ll MOD = 998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

ll modpow(ll a, ll b){
  ll r = 1;
  while(b){
    if(b&1)r=r*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return r;
}

int n;
ll fact[1252521];
ll ifact[1252521];

int main(){
  scanf("%d",&n);
  fact[0] = 1;
  FOR(i,1,n+1)fact[i] = fact[i-1] * i % MOD;
  ifact[n] = modpow(fact[n], MOD-2);
  FORR(i,0,n)ifact[i] = ifact[i+1] * (i+1) % MOD;
  ll ans = fact[n];
  FOR(x,2,n){
    ll add = fact[n] * (fact[x]+MOD-1) % MOD * ifact[x] % MOD;
    ans = (ans + add) % MOD;
  }
  printf("%lld\n",ans);
  return 0;
}