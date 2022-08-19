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
#include <numeric>
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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

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

int n;
vi to[MX];

mint s[MX];
vector<mint> d[MX], l[MX], r[MX];

void dfs(int v, int p=-1) {
  int m = to[v].size();
  d[v].resize(m);
  l[v].resize(m);
  r[v].resize(m);
  s[v] = 1;
  rep(i,m) {
    int u = to[v][i];
    if (u == p) continue;
    dfs(u,v);
    d[v][i] = s[u];
    s[v] *= s[u]+1;
  }
}
void rfs(int v, mint x, int p=-1) {
  int m = to[v].size();
  rep(i,m) {
    int u = to[v][i];
    if (u == p) d[v][i] = x;
  }
  s[v] = 1;
  rep(i,m) {
    l[v][i] = s[v];
    s[v] *= d[v][i]+1;
  }
  s[v] = 1;
  drep(i,m) {
    r[v][i] = s[v];
    s[v] *= d[v][i]+1;
  }
  rep(i,m) {
    int u = to[v][i];
    if (u == p) continue;
    mint y = l[v][i]*r[v][i];
    rfs(u,y,v);
  }
}

int main(){
  scanf("%d",&n);
  rep(i,n-1) {
    int a = i+1, b;
    scanf("%d",&b); --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  dfs(0);
  rfs(0,0);
  vi ans;
  rep(v,n) ans.pb(s[v].x);
  priv(ans);
  return 0;
}