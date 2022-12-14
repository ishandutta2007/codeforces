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

char buf[252];
int main(){
  scanf("%s",buf);
  int k = strlen(buf);
  char c = buf[k-1];
  ll n = 0;
  REP(i,k-1){
    n *= 10;
    n += buf[i]-'0';
  }
  // n,c
  ll ans = 0;
  --n;
  ans += (ll)(n/4) * 16;
  if(n%2==1){
    ans += 7;
  }
  if(c>='d'){
    ans += 1+('f'-c);
  }else{
    ans += 4+(c-'a');
  }
  printf("%I64d\n",ans);
  return 0;
}