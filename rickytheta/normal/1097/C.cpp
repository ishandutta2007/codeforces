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

int n;
char buf[525252];

int main(){
  scanf("%d",&n);
  int ans = 0;
  map<int,int> lft, rig;
  bool zero = false;
  REP(i,n){
    scanf("%s",buf);
    int l = strlen(buf);
    bool lok=false, rok=false;
    int lval=-1, rval=-1;
    {
      bool ok = true;
      int sm = 0;
      REP(j,l){
        sm += buf[j]=='(' ? 1 : -1;
        if(sm<0)ok = false;
      }
      if(ok)lok=true, lval=sm;
    }
    reverse(buf,buf+l);
    {
      bool ok = true;
      int sm = 0;
      REP(j,l){
        sm += buf[j]=='(' ? -1 : 1;
        if(sm<0)ok = false;
      }
      if(ok)rok=true, rval=sm;
    }
    fill(buf,buf+l,'\0');
    if(lok && rok){
      assert(lval==0 && rval==0);
      if(zero)ans++;
      zero ^= 1;
    }else if(lok){
      if(rig[lval]>0){
        rig[lval]--; ans++;
      }else{
        lft[lval]++;
      }
    }else if(rok){
      if(lft[rval]>0){
        lft[rval]--; ans++;
      }else{
        rig[rval]++;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}