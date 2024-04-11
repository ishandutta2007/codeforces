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

int n,r;
int x[1252];
double y[1252];

int main(){
  scanf("%d%d",&n,&r);
  REP(i,n)scanf("%d",x+i);
  REP(i,n){
    y[i] = r;
    REP(j,i){
      if(abs(x[i]-x[j]) > 2*r)continue;
      double yy = y[j];
      double dx = x[i] - x[j];
      double dx2 = dx*dx;
      double low = max(y[i],y[j]);
      double high = 1e7;
      REP(_,80){
        double mid = (low+high)/2;
        double dy = yy - mid;
        double dy2 = dy*dy;
        if(dx2+dy2 > 4*r*r){
          high = mid;
        }else{
          low = mid;
        }
      }
      y[i] = low;
    }
  }
  REP(i,n)printf("%.9f%c",y[i],i==n-1?'\n':' ');
  return 0;
}