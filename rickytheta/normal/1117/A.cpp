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
int a[125252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  int maxlen = 0, maxval = -1;
  int curlen = 0, curval = -1;
  REP(i,n){
    if(curval != a[i]){
      curval = a[i];
      curlen = 1;
    }else{
      curlen++;
    }
    if(curval > maxval){
      maxval = curval;
      maxlen = 0;
    }
    if(curval == maxval){
      CHMAX(maxlen, curlen);
    }
  }
  printf("%d\n",maxlen);
  return 0;
}