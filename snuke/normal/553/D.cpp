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

int n, m, sb;
vvi to;
void readGraph() {
  to = vvi(n);
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b); to[b].pb(a);
  }
}

bool c[MX];
int d[MX];
bool f(double x) {
  rep(i,n) d[i] = sz(to[i])-int(sz(to[i])*x);
  queue<int> q;
  rep(i,n) {
    if (c[i] || !d[i]) {
      d[i] = 0;
      q.push(i);
    }
  }
  while (sz(q)) {
    int v = q.front(); q.pop();
    for (int u : to[v]) {
      if (!d[u]) continue;
      d[u]--;
      if (!d[u]) q.push(u);
    }
  }
  rep(i,n) if (d[i]) return true;
  return false;
}

int main() {
  scanf("%d%d%d",&n,&m,&sb);
  rep(i,sb) {
    int a;
    scanf("%d",&a);
    c[a-1] = true;
  }
  readGraph();
  double l = -eps, r = 1, cent;
  rep(ti,50) {
    cent = (l+r)/2;
    if (f(cent)) l = cent; else r = cent;
  }
  f(l);
  vi ans;
  rep(i,n) if (d[i]) ans.pb(i+1);
  if (sz(ans) == 0) {
    rep(i,n) if (!c[i]) ans.pb(i+1);
  }
  cout<<sz(ans)<<endl;
  priv(ans);
  return 0;
}