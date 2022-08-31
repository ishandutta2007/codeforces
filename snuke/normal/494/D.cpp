#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //<^>v

// Mod int
const int mod = 1000000007;
struct mint{
	ll x;
	mint():x(0){}
	mint(ll x):x((x%mod+mod)%mod){}
	mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
	mint operator+(const mint& a)const{ return mint(*this) += a;}
	mint operator-(const mint& a)const{ return mint(*this) -= a;}
	mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
//
typedef vector<mint> vm;
vi to[MX], co[MX];
vm d[MX], s[MX], e[MX];

void add(vm& a, vm& b, mint c) {
  a[0] += b[0];
  a[1] += b[1]+b[0]*c;
  a[2] += b[2]+b[1]*c*2+b[0]*c*c;
}

int vk[MX], uk[MX], k;

void cfs(int v, int p=-1) {
  vk[v] = k++;
  rep(i,to[v].size()) {
    int u = to[v][i];
    if (u == p) continue;
    cfs(u,v);
  }
  uk[v] = k;
}

void dfs(int v, int p=-1) {
  d[v][0] = 1;
  d[v][1] = d[v][2] = 0;
  rep(i,to[v].size()) {
    int u = to[v][i];
    if (u == p) continue;
    dfs(u,v);
    int c = co[v][i];
    add(d[v],d[u],c);
  }
}
void efs(int v, int p=-1) {
  rep(i,3) s[v][i] = d[v][i]+e[v][i];
  rep(i,to[v].size()) {
    int u = to[v][i];
    if (u == p) continue;
    int c = co[v][i];
    vm now(3);
    add(now,d[u],c);
    rep(j,3) now[j] = s[v][j]-now[j];
    add(e[u],now,c);
    efs(u,v);
  }
}
// LCA (0-indexed)
struct LCA {
  int n, bi;
  vi dep;
  vm cost;
  vector<vi> par;
  LCA(int n):n(n),dep(n),cost(n){}
  void calcDep(int v, int ndep=0, mint nco=0, int p=-1){
    //printf("%d %d\n",v,p);
    dep[v] = ndep; cost[v] = nco; par[0][v] = p;
    rep(i,to[v].size()) {
      int u = to[v][i];
      if(u != p) calcDep(u,ndep+1,nco+co[v][i],v);
    }
  }
  void init(){
    bi = 0;
    while(1<<bi <= n) bi++;
    par.resize(bi,vi(n,-1));
    calcDep(0);
    rep(i,bi-1)rep(j,n) par[i+1][j] = (par[i][j]==-1?-1:par[i][par[i][j]]);
  }
  int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a,b);
    int x = dep[a]-dep[b];
    for(int i = bi-1; i >= 0; --i){
      if(1<<i <= x) a = par[i][a], x -= 1<<i;
    }
    if(a == b) return a;
    for(int i = bi-1; i >= 0; --i){
      if(par[i][a] != par[i][b]) a = par[i][a], b = par[i][b];
    }
    return par[0][a];
  }
  mint dist(int a, int b){
    int c = lca(a,b);
    return cost[a]+cost[b] - cost[c]*2;
  }
};
//

inline bool wea(int u, int v) {
  return vk[u] <= vk[v] && vk[v] < uk[u];
}

int main(){
  int n;
  scanf("%d",&n);
  LCA lca(n);
  rep(i,n-1){
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    a--; b--;
    to[a].pb(b); co[a].pb(c);
    to[b].pb(a); co[b].pb(c);
  }
  lca.init();
  //rep(i,n){rep(j,n) printf("%I64d ",lca.dist(i,j).x); puts("");}
  rep(i,n) d[i].resize(3);
  rep(i,n) e[i].resize(3);
  rep(i,n) s[i].resize(3);
  cfs(0);
  dfs(0);
  efs(0);
  /*
  rep(i,n){
    printf("d %d :",i);
    rep(j,3) printf(" %I64d",d[i][j].x);
    puts("");
  }
  rep(i,n){
    printf("e %d :",i);
    rep(j,3) printf(" %I64d",e[i][j].x);
    puts("");
  }
  rep(i,n){
    printf("s %d :",i);
    rep(j,3) printf(" %I64d",s[i][j].x);
    puts("");
  }//*/
  //rep(i,n){rep(j,n)printf("%d",wea(i,j));puts("");}
  int q;
  scanf("%d",&q);
  rep(qi,q) {
    int a, b;
    scanf("%d%d",&a,&b);
    a--; b--;
    mint ans = s[a][2], del;
    mint dis = lca.dist(a,b);
    //cout << a << " " << b << endl;
    //cout << wea(b,a) << endl;
    if(wea(b,a)) { // in
      vm now(3);
      add(now,e[b],dis);
      del = now[2];
    } else { // out
      vm now(3);
      add(now,d[b],dis);
      del = now[2];
      del = ans-del;
    }
    ans -= del*2;
    printf("%I64d\n",ans.x);
  }
  
  return 0;
}