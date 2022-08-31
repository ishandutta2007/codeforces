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
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n;
P a[MX], b[MX];
int pre[MX];
int xs, ys;
map<int,int> mx, my;
queue<int> q;

// Binary Indexed Tree
struct bit {
  typedef set<P> TT;
  vector<TT> d; int x2;
  bit(){}
  bit(int mx){ x2 = 1; while(x2 < mx) x2 <<= 1; d.resize(x2+1);}
  void add(int i, P x) {
    ++i;
    for(;i<=x2;i+=i&-i) {
      d[i].insert(x);
    }
  }
  void del(int i, P x){
    ++i;
    for(;i<=x2;i+=i&-i) {
      d[i].erase(x);
    }
  }
  void nxt(int i, int y, int nd){
    ++i;
    vector<P> ps;
    for(;i;i-=i&-i) {
      for (auto p : d[i]) {
        if (p.fi > y) break;
        ps.pb(p);
      }
    }
    for (auto p : ps) {
      int j = p.se;
      del(a[j].fi, p);
      pre[j] = nd;
      q.push(j);
    }
  }
};

int main() {
  scanf("%d",&n);
  rep(i,n) {
    scanf("%d%d",&a[i].fi,&a[i].se);
    scanf("%d%d",&b[i].fi,&b[i].se);
    mx[a[i].fi] = 0;
    mx[b[i].fi] = 0;
    my[a[i].se] = 0;
    my[b[i].se] = 0;
  }
  mx[0] = my[0] = 0;
  for (auto& p : mx) p.se = xs++;
  for (auto& p : my) p.se = ys++;
  rep(i,n) a[i].fi = mx[a[i].fi];
  rep(i,n) a[i].se = my[a[i].se];
  rep(i,n) b[i].fi = mx[b[i].fi];
  rep(i,n) b[i].se = my[b[i].se];
  // rep(i,n) ai[a[i]] = i;
  rep(i,n) pre[i] = INF;
  bit t(xs+3);
  rep(i,n) {
    if (a[i] == P(0,0)) {
      pre[i] = -1;
      q.push(i);
    } else t.add(a[i].fi, P(a[i].se,i));
  }
  while (sz(q)) {
    int v = q.front(); q.pop();
    t.nxt(b[v].fi, b[v].se, v);
  }
  if (pre[n-1] == INF) cout<<-1<<endl;
  else {
    vi ans;
    for (int i = n-1; i != -1; i = pre[i]) {
      ans.pb(i+1);
    }
    reverse(rng(ans));
    cout<<sz(ans)<<endl;
    priv(ans);
  }
  return 0;
}