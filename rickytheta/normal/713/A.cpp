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

string totos(ll x){
  if(x==0)return "0";
  string ret = "";
  while(x){
    ret = (char)((x&1)?'1':'0')+ret;
    x/=10;
  }
  while(ret.size()<18)ret='0'+ret;
  return ret;
}

int n;
char buf[52];

int main(){
  map<string,int> M;
  scanf("%d",&n);
  while(n--){
    scanf("%s",buf);
    if(buf[0]=='+'){
      // add
      ll a;
      scanf("%lld",&a);
      string s = totos(a);
      M[s]+=1;
    }else if(buf[0]=='-'){
      // delete
      ll a;
      scanf("%lld",&a);
      string s = totos(a);
      M[s]-=1;
    }else{
      // query
      scanf("%s",buf);
      string yo(buf);
      while(yo.size()<18)yo='0'+yo;
      printf("%d\n",M[yo]);
    }
  }
  return 0;
}