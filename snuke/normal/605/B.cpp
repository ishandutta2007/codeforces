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
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n, m;
vp a, b;
vp ans;

int main() {
  scanf("%d%d",&n,&m);
  rep(i,m) {
    int c, tp;
    scanf("%d%d",&c,&tp);
    if (tp) a.pb(P(c,i));
    else b.pb(P(c,i));
  }
  sort(rng(a));
  sort(rng(b));
  vi d;
  rep(i,n-1) {
    rep(j,i) {
      if (sz(d) >= sz(b)) break;
      d.pb(a[i].fi);
    }
  }
  if (sz(d) < sz(b)) {
    puts("-1");
    return 0;
  }
  rep(i,sz(b)) {
    if (b[i].fi < d[i]) {
      puts("-1");
      return 0;
    }
  }
  ans = vp(m);
  int bi = 0;
  rep(i,n-1) {
    ans[a[i].se] = P(i+1,i+2);
    rep(j,i) {
      if (bi >= sz(b)) break;
      ans[b[bi].se] = P(j+1,i+2);
      ++bi;
    }
  }
  rep(i,m) {
    printf("%d %d\n", ans[i].fi, ans[i].se);
  }
  return 0;
}