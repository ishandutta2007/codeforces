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

int k;
vi cand;
bool dp[27][125252];
int bef[27][125252];
int rev[125252];

int main(){
  scanf("%d",&k);
  // cand
  FOR(i,1,10000){
    int c = i * (i-1) / 2;
    if(c > k)break;
    cand.push_back(c);
    rev[c] = i;
  }
  int n = cand.size();
  dp[0][0] = true;
  REP(i,26){
    REP(s,k+1){
      REP(j,n){
        int v = cand[j];
        if(s-v>=0 && dp[i][s-v]){
          dp[i+1][s] = true;
          bef[i+1][s] = s-v;
          break;
        }
      }
    }
  }
  vi po;
  int cur = k;
  FORR(i,0,26){
    int nxt = bef[i+1][cur];
    po.push_back(rev[cur-nxt]);
    cur = nxt;
  }
  REP(i,26){
    int v = po[i];
    while(v--)putchar('a'+i);
  }
  puts("");
  return 0;
}