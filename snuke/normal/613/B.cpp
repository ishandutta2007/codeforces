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
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, ma, cf, cm;
P a[MX];
ll m;
ll s[MX];
vi as;
ll xs[MX];

int main() {
  scanf("%d%d%d%d%I64d",&n,&ma,&cf,&cm,&m);
  rep(i,n) scanf("%d",&a[i].fi);
  rep(i,n) a[i].se = i;
  as = vi(n,ma);
  sort(a,a+n);
  ll t = 0;
  ll pre = 0;
  rep(i,n) {
    t += (a[i].fi-pre)*i;
    s[i] = t;
    pre = a[i].fi;
  }
  ll ans = 0;
  int ai = 0;
  drep(i,n) {
    int l = 0, r = i+1;
    while (l+1<r) {
      int c = (l+r)>>1;
      if (s[c] <= m) l = c; else r = c;
    }
    ll x = 0;
    ll y = m-s[l];
    ll z = y/r;
    x = a[l].fi+z;
    mins(x,(ll)ma);
    ll now = (ll)cf*(n-i-1)+x*cm;
    xs[i] = x;
    maxs(ans,now);
    if (ans == now) ai = i;
    m -= ma-a[i].fi;
    if (m < 0) break;
  }
  if (m >= 0) {
    ll now = (ll)cf*n+(ll)cm*ma;
    maxs(ans, now);
    if (ans == now) ai = n;
  }
  if (ai == n) {
  } else {
    rep(i,ai+1) {
      as[a[i].se] = max(a[i].fi,(int)xs[ai]);
    }
  }
  cout<<ans<<endl;
  priv(as);
  return 0;
}