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

int n,m,k;
char s[1252],t[1252];
short dp[1002][1002][11][2];

#define CH(a,b) (a)=max<int>((a),(b));

int main(){
  scanf("%d%d%d",&n,&m,&k);
  scanf("%s%s",s,t);
  REP(i,n+1)REP(j,m+1)REP(o,k+1)REP(b,2)dp[i][j][o][b] = -1;
  dp[0][0][0][0] = 0;
  int ans = 0;
  REP(i,n)REP(j,m)REP(o,k){
    if(dp[i][j][o][0]<0 && dp[i][j][o][1]<0)continue;
    // b==1
    // cut
    CH(dp[i][j][o+1][0],dp[i][j][o][1]);
    // continue
    if(s[i]==t[j]){
      CH(dp[i+1][j+1][o][1],dp[i][j][o][1]+1);
      CH(ans,dp[i][j][o][1]+1);
    }
    // b==0
    // through
    CH(dp[i+1][j][o][0],dp[i][j][o][0]);
    CH(dp[i][j+1][o][0],dp[i][j][o][0]);
    CH(dp[i+1][j+1][o][0],dp[i][j][o][0]);
    // new
    if(s[i]==t[j]){
      CH(dp[i+1][j+1][o][1],dp[i][j][o][0]+1);
      CH(ans,dp[i][j][o][0]+1);
    }
  }
  printf("%d\n",ans);
  return 0;
}