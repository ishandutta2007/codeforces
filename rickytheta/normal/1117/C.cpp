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

int sx,sy,tx,ty;
int vx,vy;
int n;
char wind[125252];
int dx[256],dy[256];

int main(){
  scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
  scanf("%d",&n);
  scanf("%s",wind);
  dx['U'] = 0; dy['U'] = 1;
  dx['D'] = 0; dy['D'] =-1;
  dx['L'] =-1; dy['L'] = 0;
  dx['R'] = 1; dy['R'] = 0;
  vx = vy = 0;
  REP(i,n){
    vx += dx[wind[i]];
    vy += dy[wind[i]];
  }
  ll low = 0, high = 1ll<<60;
  while(low+1<high){
    ll t = (low+high)/2;
    ll loop = t / n;
    ll cx = sx + loop * vx;
    ll cy = sy + loop * vy;
    ll rest = t - loop*n;
    REP(i,rest){
      cx += dx[wind[i]];
      cy += dy[wind[i]];
    }
    ll dist = abs(tx-cx) + abs(ty-cy);
    if(dist <= t){
      high = t;
    }else{
      low = t;
    }
  }
  if(high == (1ll<<60)){
    puts("-1");
  }else{
    printf("%lld\n",high);
  }
  return 0;
}