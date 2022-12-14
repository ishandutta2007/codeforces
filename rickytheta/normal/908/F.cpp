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

int n;
ll p[353531];
int type[353531];
char buf[353];

int main(){
  scanf("%d",&n);
  p[0] = -1000000000000ll;
  bool existg = false;
  REP(i,n){
    int tmp;
    scanf("%d",&tmp);
    scanf("%s",buf);
    p[i+1] = (ll)tmp;
    type[i+1] = buf[0]=='G' ? 0 : (buf[0]=='R' ? 1 : 2);
    if(type[i+1]==0)existg = true;
  }
  if(!existg){
    ll ans = 0;
    int fr = n+10, er = -1, fb = n+10, eb = -1;
    FOR(i,1,n+1){
      if(type[i]==1)CHMIN(fr,i),CHMAX(er,i);
      else CHMIN(fb,i),CHMAX(eb,i);
    }
    if(fr<=er)ans += p[er]-p[fr];
    if(fb<=eb)ans += p[eb]-p[fb];
    cout<<ans<<endl;
    return 0;
  }
  p[n+1] = 100000000000000ll;
  ll ans = 0;
  bool first = true;
  ll last = 0;
  int befg = 0, befr = 0, befb = 0;
  ll maxr = 0, maxb = 0;
  FOR(i,1,n+2){
    if(type[i]!=0){
      if(type[i]==1){
        CHMAX(maxr, p[i]-p[befr]);
        befr = i;
      }else{
        CHMAX(maxb, p[i]-p[befb]);
        befb = i;
      }
    }else{
      CHMAX(maxr, p[i]-p[befr]);
      CHMAX(maxb, p[i]-p[befb]);
      ll len = p[i] - p[befg];
      ans += min(len + (len-maxr) + (len-maxb), len + len);
      if(first){
        ans -= len;
        first = false;
      }
      last = len;
      befg = befr = befb = i;
      maxr = maxb = 0;
    }
  }
  ans -= last;
  cout<<ans<<endl;
  return 0;
}