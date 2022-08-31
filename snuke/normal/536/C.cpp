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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Q;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi& a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-13;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

map<P,vi> cp;
set<P> s;

inline double xp(P a, P b) {
  return (double)(ll(a.fi-b.fi)*a.se*b.se)/(ll(b.se-a.se)*a.fi*b.fi);
}
inline bool ok(P a, P b, P c) {
  double x = xp(a,b);
  double y = xp(b,c);
  return x < y+eps;
}

int main(){
  int n;
  scanf("%d",&n);
  rep(i,n) {
    int a, b;
    scanf("%d%d",&a,&b);
    P p(a,b);
    s.insert(p);
    if (!cp.count(p)) {
      cp[p] = vi();
    }
    cp[p].pb(i+1);
  }
  vi ans;
  {
    P p(0,0);
    auto it = s.end(); --it;
    for (;;) {
      if (it->se <= p.se) {
        it = s.erase(it);
      } else {
        p = *it;
      }
      if (it == s.begin()) break;
      --it;
    }
  }
  vector<P> ps;
  for (P np : s) ps.pb(np);
  reverse(rng(ps));
  vector<P> t;
  for(P p : ps) {
    while (sz(t) >= 2) {
      if (ok(t[sz(t)-2],t[sz(t)-1],p)) break;
      t.pop_back();
    }
    t.pb(p);
  }
  for (P np : t) ans.insert(ans.end(),rng(cp[np]));
  sort(rng(ans));
  priv(ans);
  return 0;
}