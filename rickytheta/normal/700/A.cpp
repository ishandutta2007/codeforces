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

ll n;
Real l,v1,v2;
ll k;

bool check(Real x){
  Real bustime = 0.0;
  Real buspos = 0.0;
  if(v1*x >= l)return true;
  Real t2 = (l - v1 * x)/(v2-v1);
  if(t2>x)return false;
  REP(i,n){
    Real revtime = (buspos - v1*bustime)/(v1+v2);
    bustime += revtime;
    buspos -= revtime * v2;
    if(bustime>x)return false;
    Real gotime = min(t2,(l-buspos)/v2);
    bustime += gotime;
    buspos += gotime * v2;
    if(bustime>x)return false;
  }
  return true;
}

int main(){
  cin>>n>>l>>v1>>v2>>k;
  n = (n+k-1)/k;
  Real low=0, high=1e18;
  REP(_,100){
    Real mid = (low+high)/2.0;
    if(check(mid))high=mid;
    else low=mid;
  }
  printf("%.20lf\n",low);
  return 0;
}