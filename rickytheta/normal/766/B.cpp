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
int a[125252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  sort(a,a+n);
  REP(i,n-1){
    int x = a[i];
    int y = a[i+1];
    int sa = y-x;
    int wa = y+x;
    int left = upper_bound(a,a+n,sa)-a;
    int right = lower_bound(a,a+n,wa)-a;
    right--;
    if(left==i || left==i+1)left=i+2;
    if(right==i || right==i+1)right=i-1;
    if(left<=right){
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}