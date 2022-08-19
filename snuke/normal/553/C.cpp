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
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
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

int n, m;
vvi to, co;
void readGraph() {
  to = vvi(n);
  co = vvi(n);
  rep(i,m) {
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    --a; --b; c ^= 1;
    to[a].pb(b); to[b].pb(a);
    co[a].pb(c); co[b].pb(c);
  }
}
bool ok;
int d[MX];

void dfs(int v, int c) {
  if (d[v] == (c^1)) ok = false;
  if (d[v] != -1) return;
  d[v] = c;
  rep(i,to[v].size()) {
    int u = to[v][i];
    dfs(u,c^co[v][i]);
  }
}

int main() {
  cin >> n >> m;
  readGraph();
  ok = true;
  mint ans = 1;
  rep(i,n) d[i] = -1;
  rep(i,n) {
    if (d[i] != -1) continue;
    dfs(i,0);
    if (i) ans *= 2;
  }
  if (ok) cout<<ans.x<<endl;
  else cout<<0<<endl;
  return 0;
}