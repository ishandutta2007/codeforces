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

ll n,m;

typedef vector<vl> mat;

mat matmul(mat &a, mat &b){
  int n = a.size();
  mat ret(n,vl(n,0ll));
  REP(k,n)REP(i,n)REP(j,n){
    (ret[i][j] += a[i][k]*b[k][j]%MOD) %= MOD;
  }
  return ret;
}

int main(){
  scanf("%lld%lld",&n,&m);
  mat I(m,vl(m,0ll)), A(m,vl(m,0ll));
  REP(i,m)I[i][i] = 1;
  REP(i,m-1)A[i][i+1] = 1;
  A[0][0] = A[m-1][0] = 1;
  mat R = I;
  while(n){
    if(n&1)R=matmul(R,A);
    A=matmul(A,A);
    n >>= 1;
  }
  printf("%lld\n",R[0][0]);
  return 0;
}