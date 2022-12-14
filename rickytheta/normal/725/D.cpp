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
  int n;
  scanf("%d",&n);
  ll bal,roooooooooooo;
  scanf("%lld%lld",&bal,&roooooooooooo);

  --n;
  multiset<pll> wining;
  multiset<ll> losing;
  REP(i,n){
    ll x,y;
    scanf("%lld%lld",&x,&y);
    if(x > bal){
      losing.insert(y+1-x);
    }else{
      wining.insert(pll(-x,y+1-x));
    }
  }
  int ans = losing.size()+1;
  while(ans > 1){
    ll least = *losing.begin();
    if(bal < least)break;
    losing.erase(losing.begin());
    bal -= least;
    while(wining.size()){
      pll wi = *wining.begin();
      if(-wi.first > bal){
        wining.erase(wining.begin());
        losing.insert(wi.second);
      }else{
        break;
      }
    }
    CHMIN(ans,(int)losing.size()+1);
  }
  printf("%d\n",ans);
  return 0;
}