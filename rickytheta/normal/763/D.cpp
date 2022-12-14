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
const ll MOD = 1000000009ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int n;
vi g[125252];

ll subhash[125252];
const ll B = 106;
unordered_map<ll,int> M;
int sum = 0;

ll dfs0(int p,int bef){
  ll val = 53;
  for(int to : g[p])if(to!=bef){
    val = val*dfs0(to,p)%MOD;
  }
  val = (val+B)%MOD;
  M[val]++;
  return subhash[p] = val;
}
ll modinv(ll p){
  ll r = 1, b = MOD-2;
  while(b){
    if(b&1)r=r*p%MOD;
    p=p*p%MOD;
    b>>=1;
  }
  return r;
}
void rootch(int bef,int to){
  ll tohash = subhash[to];
  ll befhash = subhash[bef];
  if(--M[tohash]==0)sum--;
  if(--M[befhash]==0)sum--;
  ll pipi2 = (befhash-B+MOD) * modinv(tohash) % MOD;
  subhash[bef] = (pipi2 + B) % MOD;
  subhash[to] = (subhash[bef] * (tohash-B+MOD) % MOD + B) % MOD;
  if(M[subhash[to]]++==0)sum++;
  if(M[subhash[bef]]++==0)sum++;
}
pii dfs1(int p,int bef){
  // DEBUG(p);
  // for(pii P : M)printf("%d : %d\n",P.first, P.second);
  pii ret = pii(sum, p);
  for(int to : g[p])if(to!=bef){
    // root to
    rootch(p,to);
    CHMAX(ret,dfs1(to,p));
    // root p
    rootch(to,p);
  }
  return ret;
}

int main(){
  scanf("%d",&n);
  REP(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    --u;--v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs0(0,-1);
  sum = M.size();
  pii ans = dfs1(0,-1);
  printf("%d\n",ans.second+1);
  return 0;
}