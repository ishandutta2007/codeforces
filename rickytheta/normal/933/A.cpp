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
int a[2521];
int dp[2521][4];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  dp[0][0] = 0;
  REP(i,n)REP(j,4){
    CHMAX(dp[i+1][j],dp[i][j]);
    if(j%2==0){
      if(a[i]==1)CHMAX(dp[i+1][j],dp[i][j]+1);
      else CHMAX(dp[i+1][j+1],dp[i][j]+1);
    }else{
      if(a[i]==2)CHMAX(dp[i+1][j],dp[i][j]+1);
      else if(j+1<4) CHMAX(dp[i+1][j+1],dp[i][j]+1);
    }
  }
  int ans = 0;
  REP(j,4)CHMAX(ans,dp[n][j]);
  printf("%d\n",ans);
  return 0;
}