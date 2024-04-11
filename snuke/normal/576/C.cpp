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
typedef pair<P,int> Q;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 1000005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int M = 1000;

int n;
Q p[MX];
vi per;

void con(vi& a) {
  for(int x : a) per.pb(x+1);
}

int main() {
  scanf("%d",&n);
  rep(i,n) scanf("%d%d",&p[i].fi.fi,&p[i].fi.se);
  rep(i,n) p[i].se = i;
  int f = 0;
  int ai = 0;
  sort(p,p+n);
  while (ai < n) {
    int sx = p[ai].fi.fi;
    vector<P> q;
    while (ai < n) {
      if (p[ai].fi.fi < sx+M) {
        q.pb(P(p[ai].fi.se,p[ai].se));
        ++ai;
      } else break;
    }
    sort(rng(q));
    vi a;
    rep(i,sz(q)) a.pb(q[i].se);
    if (f) reverse(rng(a));
    f ^= 1;
    con(a);
  }
  priv(per);
  return 0;
}