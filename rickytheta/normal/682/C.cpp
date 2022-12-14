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
vector<pii> g[125252];

// cut, cnt
pii dfs(int pos,ll d){
  pii ret;
  ret.first = 0;
  ret.second = 0;
  for(pii info : g[pos]){
    int to = info.first;
    int cost = info.second;
    ll nd = d+cost;
    if(nd<0)nd=0;
    pii po = dfs(to,nd);
    ret.first += po.first;
    ret.second += po.second;
  }
  ret.second += 1;
  if(a[pos] < d){
    ret.first = ret.second;
  }
  return ret;
}

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  REP(i,n-1){
    int to,c;
    scanf("%d%d",&to,&c);
    --to;
    // g[i+1].push_back(pii(to,c));
    g[to].push_back(pii(i+1,c));
  }
  pii ans = dfs(0,0);
  printf("%d\n",ans.first);
  return 0;
}