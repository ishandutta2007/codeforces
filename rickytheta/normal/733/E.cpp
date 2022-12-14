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

int n;
char s[1252525];
int cntright[1252525];
int cntleft[1252525];
int revright[1252525];
int revleft[1252525];
ll sumright[1252525];
ll sumleft[1252525];

int main(){
  scanf("%d",&n);
  scanf("%s",s);
  // cnt
  REP(i,n){
    if(s[i]=='U'){
      cntright[i+1] = cntright[i]+1;
      cntleft[i+1] = cntleft[i];
      revright[cntright[i+1]] = i+1;
    }else{
      cntright[i+1] = cntright[i];
      cntleft[i+1] = cntleft[i]+1;
      revleft[cntleft[i+1]] = i+1;
    }
  }
  // sum
  REP(i,n){
    if(s[i]=='U'){
      sumright[i+1] = sumright[i]+(n-i);
      sumleft[i+1] = sumleft[i];
    }else{
      sumright[i+1] = sumright[i];
      sumleft[i+1] = sumleft[i]+(i+1);
    }
  }
  // query
  REP(q,n){
    // DEBUG(q);
    // left ->
    int l = cntright[q];
    // right <-
    int r = cntleft[n]-cntleft[q+1];
    if(s[q]=='U'){
      // ->
      if(r>l){
        // go out to left
        int rightbnd = l+1;
        int leftbnd = l;
        int rrr = revleft[cntleft[q+1]+rightbnd];
        // int lll = revright[cntright[q]-leftbnd];
        int lll = 0;
        ll ans = 0ll;
        ans += (sumright[q]-sumright[lll]-(ll)leftbnd*(n-q))*2ll;
        ans += (sumleft[rrr]-sumleft[q+1]-(ll)rightbnd*(q+1))*2ll;
        ans += q+1;
        printf("%I64d",ans);
      }else{
        // go out to right
        int rightbnd = r;
        int leftbnd = r;
        // int rrr = revleft[cntleft[q+1]+rightbnd];
        int rrr = n;
        int lll = revright[cntright[q]-leftbnd];
        ll ans = 0ll;
        ans += (sumright[q]-sumright[lll]-(ll)leftbnd*(n-q))*2ll;
        ans += (sumleft[rrr]-sumleft[q+1]-(ll)rightbnd*(q+1))*2ll;
        ans += n-q;
        printf("%I64d",ans);
      }
    }else{
      // <-
      if(l>r){
        // go out to right
        int rightbnd = r;
        int leftbnd = r+1;
        // int rrr = revleft[cntleft[q+1]+rightbnd];
        int rrr = n;
        int lll = revright[cntright[q]-leftbnd];
        ll ans = 0ll;
        ans += (sumright[q]-sumright[lll]-(ll)leftbnd*(n-q))*2ll;
        ans += (sumleft[rrr]-sumleft[q+1]-(ll)rightbnd*(q+1))*2ll;
        ans += n-q;
        printf("%I64d",ans);
      }else{
        // go out to left
        int rightbnd = l;
        int leftbnd = l;
        int rrr = revleft[cntleft[q+1]+rightbnd];
        // int lll = revright[cntright[q]-leftbnd];
        int lll = 0;
        ll ans = 0ll;
        ans += (sumright[q]-sumright[lll]-(ll)leftbnd*(n-q))*2ll;
        ans += (sumleft[rrr]-sumleft[q+1]-(ll)rightbnd*(q+1))*2ll;
        ans += q+1;
        printf("%I64d",ans);
      }
    }
    if(q!=n-1){
      putchar(' ');
    }else{
      putchar('\n');
    }
  }
  return 0;
}