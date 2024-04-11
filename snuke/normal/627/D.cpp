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
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{for(T&x:v)i>>x;return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;for(T&x:v)s<<' '<<x;return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}

const int MX = 200005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, m, x;
int c[MX];
vi to[MX];
int used[MX];

int root;
void rfs(int v, int p=-1) {
  used[v] = 1;
  for (int u : to[v]) if (u != p) {
    if (c[u] < x) root = v;
    else rfs(u,v);
  }
}
int mx;
int dp[MX];
int dfs(int v, int p=-1) {
  int s = 1;
  bool ok = true;
  int nx = 0;
  dp[v] = 0;
  for (int u : to[v]) if (u != p) {
    if (c[u] < x) ok = false; else {
      int ns = dfs(u,v);
      s += ns;
      if (!ns) {
        ok = false;
        maxs(nx, dp[v]+dp[u]);
        maxs(dp[v], dp[u]);
      }
    }
  }
  nx += s;
  maxs(mx, nx);
  dp[v] += s;
  if (!ok) s = 0;
  return s;
}

bool f() {
  rep(i,n) used[i] = 0;
  rep(i,n) if (!used[i] && c[i] >= x) {
    root = -1;
    rfs(i);
    if (root == -1) return true;
    mx = 0;
    dfs(root);
    // cout<<x<<" "<<i<<" "<<root<<" "<<mx<<endl;
    if (mx >= m) return true;
  }
  return false;
}

int main() {
  scanf("%d",&n);
  scanf("%d",&m);
  rep(i,n) scanf("%d",&c[i]);
  rep(i,n-1) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  int l = 0, r = 1000001;
  while (l+1<r) {
    x = (l+r)>>1;
    if (f()) l = x; else r = x;
  }
  cout<<l<<endl;
  return 0;
}