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

int main(){
  string s;
  cin>>s;
  s += "+";
  int type = 0;
  int cur = 0;
  REP(i,s.size()){
    if(isdigit(s[i])){
      cur *= 10;
      cur += s[i]-'0';
    }else{
      if(type==0){
        REP(_,cur)putchar('+');
      }else{
        REP(_,cur)putchar('-');
      }
      cur = 0;
      if(s[i]=='+'){
        type = 0;
      }else{
        type = 1;
      }
    }
  }
  // http://esolangs.org/wiki/brainfuck_algorithms#Print_value_of_cell_x_as_number_for_ANY_sized_cell_.28ie_8bit.2C_16bit.2C_etc.29
  puts("[>>+>+<<<-]>>>[<<<+>>>-]<<+>[<->[>++++++++++<[->-[>+>>]>[+[-<+>]>+>>]<<<<<]>[-]++++++++[<++++++>-]>[<<+>>-]>[<<+>>-]<<]>]<[->>++++++++[<++++++>-]]<[.[-]<]<");
  return 0;
}