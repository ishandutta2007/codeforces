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

set<int> r, l;
int n;
string s;

vvi d;
vi t;
vi ans;

int main() {
  cin >> s;
  n = sz(s);
  rep(i,n) if (s[i] == 'L') l.insert(i); else r.insert(i);
  while(sz(l) || sz(r)) {
    int lx = INF, rx = INF;
    if (sz(l)) lx = *(l.begin());
    if (sz(r)) rx = *(r.begin());
    int f = 0;
    if (lx > rx) f = 1;
    t.pb(f);
    int p = -1;
    vi e;
    while (1) {
      int x = 0;
      if (f) {
        auto it = r.lower_bound(p);
        if (it == r.end()) break;
        x = *it;
        r.erase(it);
      } else {
        auto it = l.lower_bound(p);
        if (it == l.end()) break;
        x = *it;
        l.erase(it);
      }
      e.pb(x);
      p = x;
      f ^= 1;
    }
    d.pb(e);
    t.back() += 2*(sz(e)%2);
  }
  int m = sz(d);
  cout<<m-1<<endl;
  vi ts(4);
  rep(i,m) ts[t[i]]++;
  if (ts[2] || ts[3]) {
  } else if (!ts[0] || !ts[1]) {
  } else {
    int l0 = 0, l1 = 0;
    rep(i,m) if (t[i] == 0) l0 = i;
    rep(i,m) if (t[i] == 1) l1 = i;
    if (d[l0].back() < d[l1].back()) {
      ts[2]++;
      d[l0].pb(d[l1].back());
      d[l1].pop_back();
    } else {
      ts[3]++;
      d[l1].pb(d[l0].back());
      d[l0].pop_back();
    }
  }
  if (ts[2] || ts[3]) {
    int f = 0;
    if (ts[2] < ts[3]) f = 1;
    vvi g(2);
    rep(i,m) {
      if (t[i] < 2) continue;
      g[t[i]%2].pb(i);
    }
    vi ls;
    rep(i,m) if (t[i] == f) ls.pb(i);
    ls.pb(g[f][0]);
    rep(i,m) if (t[i] == (f^1)) ls.pb(i);
    rep(i,m) {
      if (i >= sz(g[f^1])) break;
      ls.pb(g[f^1][i]);
      if (i+1 >= sz(g[f])) break;
      ls.pb(g[f][i+1]);
    }
    rep(i,m) ans.insert(ans.end(),rng(d[ls[i]]));
  } else if (!ts[0] || !ts[1]) {
    rep(i,m) ans.insert(ans.end(),rng(d[i]));
  } else {
    puts("-1");
  }
  rep(i,n) ans[i]++;
  priv(ans);
  return 0;
}