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

ll n;
int k;
vector<ll> prs;
vector<int> fcnt;

ll mi[52];

ll dp[52][52][2];
ll sm[52][52][2];

ll calc(ll x){
  ll v = x % MOD;
  ll p = 1;
  REP(i,prs.size()){
    ll s = prs[i];
    int cnt = 0;
    while(x%s==0)x/=s,cnt++;
    p = p * dp[fcnt[i]][cnt][k&1] % MOD;
    // printf("x=%lld, s=%lld, fcnt=%d, cnt=%d -> pp=%lld\n",v,s,fcnt[i],cnt,dp[fcnt[i]][cnt][k]);
  }
  return p * v % MOD;
}

int main(){
  scanf("%lld%d",&n,&k);
  // precalc: modinv
  mi[0] = mi[1] = 1;
  FOR(x,2,52){
    mi[x] = MOD - (ll)(MOD/x) * mi[MOD%x] % MOD;
  }
  // precalc: dp
  REP(i,51)dp[i][i][0] = 1;
  FOR(x,1,k+1){
    // sum
    int cur = x%2;
    int old = 1-cur;
    REP(j,51)sm[0][j][old] = 0;
    REP(j,51)REP(i,51)sm[i+1][j][old] = (sm[i][j][old] + dp[i][j][old]) % MOD;
    // calc
    REP(i,51)REP(j,51)dp[i][j][cur] = (sm[i+1][j][old] - sm[j][j][old] + MOD) % MOD * mi[i+1] % MOD;
  }
  // precalc: factor
  ll tmp = n;
  for(ll x=2;x*x<=tmp;x++)if(tmp%x==0){
    int cnt = 0;
    prs.push_back(x);
    while(tmp%x==0)tmp/=x,cnt++;
    fcnt.push_back(cnt);
  }
  if(tmp>1)prs.push_back(tmp),fcnt.push_back(1);
  // calc
  ll ans = 0;
  for(ll i=1;i*i<=n;i++)if(n%i==0){
    ans = (ans + calc(i)) % MOD;
    if(n/i != i)ans = (ans + calc(n/i)) % MOD;
  }
  printf("%lld\n",ans);
  return 0;
}