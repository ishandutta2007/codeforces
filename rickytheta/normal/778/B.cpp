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

int n,m;
map<string,int> s2id;
vector<string> bank;
int lop[5252], rop[5252], op[5252];
const int VAL = 0, OR = 1, AND = 2, XOR = 3;
const int QUESTION = 83025;
char buf[25252];

int val[5252];

int mini[5252], maxi[5252];

int main(){
  scanf("%d%d",&n,&m);
  REP(i,n){
    scanf("%s",buf);
    string def(buf);
    s2id[def] = i;
    scanf("%s",buf);  // :=
    scanf("%s",buf);
    string lopstr(buf);
    if(lopstr[0]=='0'||lopstr[0]=='1'){
      // to bank
      int id = bank.size();
      bank.push_back(lopstr);
      lop[i] = -id-1;
      op[i] = VAL;
    }else{
      if(lopstr=="?"){
        lop[i] = QUESTION;
      }else{
        lop[i] = s2id[lopstr];
      }
      scanf("%s",buf);  // operator
      if(buf[0]=='O')op[i] = OR;
      else if(buf[0]=='A')op[i] = AND;
      else if(buf[0]=='X')op[i] = XOR;
      else assert(false);
      scanf("%s",buf);
      string ropstr(buf);
      if(ropstr=="?"){
        rop[i] = QUESTION;
      }else{
        rop[i] = s2id[ropstr];
      }
    }
  }
  REP(k,m){
    // k-bit
    // set zero
    int zerosum = 0;
    REP(i,n){
      if(op[i]==VAL){
        int bankid = -lop[i]-1;
        val[i] = bank[bankid][k]-'0';
      }else{
        int lval = lop[i]==QUESTION ? 0 : val[lop[i]];
        int rval = rop[i]==QUESTION ? 0 : val[rop[i]];
        if(op[i]==OR)val[i]=lval|rval;
        else if(op[i]==AND)val[i]=lval&rval;
        else if(op[i]==XOR)val[i]=lval^rval;
        else assert(false);
      }
      zerosum += val[i];
    }
    // set one
    int onesum = 0;
    REP(i,n){
      if(op[i]==VAL){
        int bankid = -lop[i]-1;
        val[i] = bank[bankid][k]-'0';
      }else{
        int lval = lop[i]==QUESTION ? 1 : val[lop[i]];
        int rval = rop[i]==QUESTION ? 1 : val[rop[i]];
        if(op[i]==OR)val[i]=lval|rval;
        else if(op[i]==AND)val[i]=lval&rval;
        else if(op[i]==XOR)val[i]=lval^rval;
        else assert(false);
      }
      onesum += val[i];
    }
    if(zerosum<onesum){
      mini[k] = 0;
      maxi[k] = 1;
    }else if(zerosum>onesum){
      mini[k] = 1;
      maxi[k] = 0;
    }else{
      mini[k] = maxi[k] = 0;
    }
  }
  REP(i,m)putchar('0'+mini[i]);
  puts("");
  REP(i,m)putchar('0'+maxi[i]);
  puts("");
  return 0;
}