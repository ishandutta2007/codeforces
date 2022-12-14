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

int main(){
  ll now = 2;
  int level = 1;
  int n;
  cin>>n;
  REP(i,n){
    ll k = i+1;
    ll d = i+2;
    ll d2 = d*d;
    //  d2 
    ll cnt = 0;
    if(now%d2!=0){
      ll tmp = now-1ll;
      ll x = tmp/k;
      ll y = tmp%k;
      ll id = (k+2)*(k-1-y) + x + 1;
      ll poi = d2 - id;
      cnt += poi;
      now += poi*k;
    }
    ll s = now / d2;
    ll y = k;
    ll add = (y*y-s)/k;
    s += add*k;
    cnt += add*d2;
    now += add*k*d2;
    now = y*d;
    printf("%lld\n",cnt);
  }
  return 0;
}