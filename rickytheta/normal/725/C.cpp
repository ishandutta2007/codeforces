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

const int n = 27;
char s[252];
char ans[2][15];
int main(){
  scanf("%s",s);
  char d;
  FOR(c,'A','Z'+1){
    if(count(s,s+n,c)==2){
      d = c;
      break;
    }
  }
  int a=-1,b=-1;
  REP(i,n)if(s[i]==d){
    if(a==-1)a=i;
    else b=i;
  }
  int len = b-a-1;
  if(len==0){
    puts("Impossible");
    return 0;
  }
  int lo = len/2;
  int y = 0;
  int x = 12-lo;
  int it = a-1;
  REP(i,27){
    ++it;
    if(it==27)it=0;

    if(i!=0 && s[it]==d)continue;
    ans[y][x] = s[it];
    if(y==0 && x<13-1){
      ++x;
    }else if(y==0 && x==13-1){
      y=1;
    }else if(y==1 && x>0){
      --x;
    }else{
      y=0;
    }
  }
  ans[0][13] = ans[1][13] = '\0';
  puts(ans[0]);
  puts(ans[1]);

  //
  return 0;
}