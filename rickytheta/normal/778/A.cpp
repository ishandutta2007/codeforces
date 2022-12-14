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

char t[252521];
char p[252521];
int n,m;
int a[252521];
int b[252521];

bool ok(int k){
  int it = 0;
  REP(i,n){
    if(b[i]<=k)continue;
    if(it<m && t[i]==p[it])it++;
  }
  return it==m;
}

int main(){
  scanf("%s%s",t,p);
  n = strlen(t);
  m = strlen(p);
  REP(i,n)scanf("%d",a+i);
  REP(i,n)b[a[i]-1] = i+1;
  int low = -1, high = n+1;
  while(low + 1 < high){
    int mid = (low+high)/2;
    if(ok(mid))low = mid;
    else high = mid;
  }
  printf("%d\n",low);
  return 0;
}