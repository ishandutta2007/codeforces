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

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int k,pa,pb;

ll modpow(ll a,ll b,ll m){
  ll r=1;
  while(b){
    if(b&1)r=r*a%m;
    a=a*a%m;
    b>>=1;
  }
  return r;
}
ll minv(ll a){
  return modpow(a,MOD-2,MOD);
}

pll add(pll x,pll y){
  return pll((x.first*y.second+y.first*x.second)%MOD, x.second*y.second%MOD);
}
pll mul(pll x,pll y){
  return pll(x.first*y.first%MOD, x.second*y.second%MOD);
}
pll div(pll x,pll y){
  return pll(x.first*y.second%MOD, x.second*y.first%MOD);
}

pll dp[1001][2002];

int main(){
  scanf("%d%d%d",&k,&pa,&pb);
  pll ppa = pll(pa,pa+pb);
  pll ppb = pll(pb,pa+pb);
  FORR(i,0,k+1)FORR(j,0,2*k+2){
    if(i==k){
      dp[i][j] = mul(div(add(mul(pll(j+k,1),ppb),ppa),mul(ppb,ppb)),ppb);
    }else if(j>=k){
      dp[i][j] = pll(j,1);
    }else{
      dp[i][j] = add(mul(ppa,dp[i+1][j]), mul(ppb,dp[i][j+i]));
    }
  }
  // REP(i,k+1){
  //   REP(j,2*k+2)printf("%lld/%lld ",dp[i][j].first,dp[i][j].second);puts("");
  // }
  pll ar = dp[1][0];
  ll ans = ar.first * minv(ar.second) % MOD;
  cout<<ans<<endl;
  return 0;
}