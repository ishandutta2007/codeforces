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

char t[12525];
int n;

char qs[3][12525];
char qt[3][12525];
int sidrev[12525];
char ans[12525];

int main(){
  scanf("%s",t);
  n = strlen(t);
  REP(i,3){
    int z = 0;
    REP(j,n){
      int z = 0;
      if(i==0)z = j%26;
      if(i==1)z = (j/26)%26;
      if(i==2)z = (j/26/26);
      qs[i][j] = 'a'+z;
    }
    printf("? %s\n", qs[i]); fflush(stdout);
    scanf("%s",qt[i]);
  }
  REP(i,n){
    int id = (qs[2][i]-'a')*26*26 + (qs[1][i]-'a')*26 + (qs[0][i]-'a');
    sidrev[id] = i;
  }
  REP(i,n){
    int id = (qt[2][i]-'a')*26*26 + (qt[1][i]-'a')*26 + (qt[0][i]-'a');
    int pos = sidrev[id];
    ans[pos] = t[i];
  }
  printf("! %s\n",ans); fflush(stdout);
  return 0;
}