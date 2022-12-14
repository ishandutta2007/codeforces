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

int n,k;
vector<bool> univ;
vi g[252521];
vector<bool> used;

int e1,e2;
int vv;
int dfs1(int p){
  used[p] = true;
  int ret = (int)univ[p];
  bool flag = true;
  REP(i,g[p].size()){
    int to = g[p][i];
    if(used[to])continue;
    int tmp = dfs1(to);
    if(tmp==k){
      e1=p;
      e2=to;
    }
    flag = flag && tmp<k;
    ret += tmp;
  }
  if(flag && ret >= k) vv = p;
  return ret;
}
pll dfs2(int p){
  // count, sumlen
  pll ret = pll((ll)univ[p], 0);
  REP(i,g[p].size()){
    int to = g[p][i];
    if(used[to])continue;
    used[to] = true;
    pll tmp = dfs2(to);
    tmp.second += tmp.first;
    ret.first += tmp.first;
    ret.second += tmp.second;
  }
  return ret;
}

int main(){
  scanf("%d%d",&n,&k);
  univ.assign(n,false);
  REP(i,2*k){
    int x;
    scanf("%d",&x);
    univ[x-1] = true;
  }
  REP(i,n-1){
    int x,y;
    scanf("%d%d",&x,&y);
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  used.assign(n,false);
  e1=e2=-1;
  vv=-1;
  dfs1(0);
  used.assign(n,false);
  if(e1!=-1){
    used[e1] = used[e2] = true;
    pll p1,p2;
    p1 = dfs2(e1);
    p2 = dfs2(e2);
    ll ans = p1.second + p2.second + k;
    printf("%I64d\n",ans);
  }else{
    assert(vv!=-1);
    used[vv] = true;
    pll po;
    po = dfs2(vv);
    ll ans = po.second;
    printf("%I64d\n",ans);
  }
  return 0;
}