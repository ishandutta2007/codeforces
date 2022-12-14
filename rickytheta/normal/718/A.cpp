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

const int INF = 830252521;

char _s[252521];

int main(){
  int n,t;
  string s;
  scanf("%d%d",&n,&t);
  scanf("%s",_s);
  s = string(_s);
  bool flag = false;
  int beg = INF;
  REP(i,n){
    if(flag){
      if(s[i]>='5'){
        beg = i;
        break;
      }
    }else if(s[i]=='.'){
      flag = true;
    }
  }
  if(beg!=INF){
    int x = beg;
    while(t--){
      while(s.size()>x)s.pop_back();
      if(s[x-1]=='.'){
        int k = x-2;
        while(k>=0){
          int c = s[k];
          if(c!='9'){
            s[k]+=1;
            break;
          }else{
            s[k]='0';
            --k;
          }
        }
        if(k==-1)s='1'+s;
        break;
      }else{
        int k = x-1;
        beg = INF;
        flag = true;
        while(k>=0){
          int c = s[k];
          if(c!='9'){
            s[k]+=1;
            if(flag && s[k]>='5')CHMIN(beg,k);
            break;
          }else{
            s[k]='0';
            --k;
            if(k>=0 && s[k]=='.'){
              flag = false;
              --k;
            }
          }
        }
        if(k==-1){
          s='1'+s;
        }
        if(beg==INF)break;
        if(k==-1){
          ++beg;
        }
        x=beg;
      }
    }
  }
  while(s.size()>0 && s.back()=='0')s.pop_back();
  if(s.back()=='.')s.pop_back();
  puts(s.c_str());
  return 0;
}