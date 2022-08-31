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
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
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
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 400005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n;
vvi to;

vi t;
P dfs(int v, int p=-1) {
  P res(0,v);
  P r(n,v);
  t[v] = 1;
  rep(i, sz(to[v])) {
    int u = to[v][i];
    if (u == p) continue;
    mins(r, dfs(u,v));
    maxs(res.fi, t[u]);
    t[v] += t[u];
  }
  maxs(res.fi, n-t[v]);
  return min(r, res);
}
int efs(int v, int p=-1) {
  int res = t[v]>n/2?0:t[v];
  for (int u : to[v]) {
    if (u == p) continue;
    int r = efs(u,v);
    maxs(res, r);
  }
  return res;
}
vi ans;
void fs(int v, int a, int p=-1) {
  int x = n-t[v];
  if (x-a <= n/2) ans[v] = 1;
  for (int u : to[v]) {
    if (u == p) continue;
    int b = a;
    if (x <= n/2) maxs(b,x);
    fs(u,b,v);
  }
}

int main() {
  scanf("%d",&n);
  to = vvi(n);
  rep(i,n-1) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  t = vi(n);
  int c = dfs(0).se;
  t = vi(n);
  dfs(c);
  vp x;
  rep(i,sz(to[c])) {
    int u = to[c][i];
    x.pb(P(efs(u,c),i));
  }
  ans = vi(n);
  ans[c] = 1;
  sort(rng(x)); reverse(rng(x));
  rep(i,sz(to[c])) {
    int u = to[c][i];
    int a = x[0].fi;
    if (x[0].se == i) {
      a = 0;
      if (sz(x) > 1) a = x[1].fi;
    }
    fs(u,a,c);
  }
  cout<<ans<<endl;
  return 0;
}