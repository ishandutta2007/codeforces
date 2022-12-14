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

int mylog(ll x){
  int ret = 0;
  while(x>0){
    ret++;
    x>>=1;
  }
  return ret;
}

int n;
ll b[125252];
vl bb[61];
ll tmp[125252];
ll ans[125252];

int solve(){
  REP(i,n)bb[mylog(b[i])-1].push_back(b[i]);
  int anslen = 0;
  FORR(i,0,61){
    int tmplen = 0;
    int ansit = 0;
    bool flag = true;
    REP(j,bb[i].size()){
      ll x = bb[i][j];
      if(!flag)return -1;
      tmp[tmplen++] = x;
      flag = false;
      while(ansit < anslen){
        ll y = ans[ansit++];
        tmp[tmplen++] = y;
        if((y>>i)&1){
          flag = true;
          break;
        }
      }
    }
    while(ansit < anslen)tmp[tmplen++] = ans[ansit++];
    REP(j,tmplen)ans[j] = tmp[j];
    anslen = tmplen;
  }
  return anslen;
}

int main(){
  if(false){
    // test
    srand(time(NULL));
    n = 100000;
    b[0] = rand();
    FOR(i,1,n)b[i] = b[i-1] + 1 + rand();
    // REP(i,n)printf("%lld%c",b[i],i==n-1?'\n':' ');
    FORR(i,1,n)b[i] = b[i] ^ b[i-1];
    // REP(i,n)printf("%lld%c",b[i],i==n-1?'\n':' ');
    int anslen = solve();
    if(anslen == -1){
      puts("NG1");
    }else{
      // REP(i,n)printf("%lld%c",ans[i],i==n-1?'\n':' ');
      FOR(i,1,n)ans[i] = ans[i] ^ ans[i-1];
      // REP(i,n)printf("%lld%c",ans[i],i==n-1?'\n':' ');
      FOR(i,1,n)if(ans[i] <= ans[i-1]){
        puts("NG2");
        break;
      }
    }
    puts("END");
    return 0;
  }
  scanf("%d",&n);
  REP(i,n)scanf("%lld",b+i);
  int anslen = solve();
  if(anslen != -1){
    puts("Yes");
    REP(i,anslen)printf("%lld%c",ans[i],i==anslen-1?'\n':' ');
  }else{
    puts("No");
  }
  return 0;
}