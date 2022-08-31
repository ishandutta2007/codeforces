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
typedef vector<P> vp;
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

int n, h, w;
string s;

int main() {
  cin >> n >> h >> w;
  cin >> s;
  mint ans = 0;
  int x = 0, y = 0;
  int ax = 0, bx = 0;
  int ay = 0, by = 0;
  vi lx, ly;
  vi rx, ry;
  rep(i,n) {
    if (s[i] == 'R') y++;
    if (s[i] == 'L') y--;
    if (s[i] == 'U') x++;
    if (s[i] == 'D') x--;
    if (x < ax) {
      ax = x;
      // lx.pb(i);
      ans += mint(i+1)*(w-(by-ay));
    }
    if (x > bx) {
      bx = x;
      // rx.pb(i);
      ans += mint(i+1)*(w-(by-ay));
    }
    if (y < ay) {
      ay = y;
      // ly.pb(i);
      ans += mint(i+1)*(h-(bx-ax));
    }
    if (y > by) {
      by = y;
      // ry.pb(i);
      ans += mint(i+1)*(h-(bx-ax));
    }
    if (h-(bx-ax) == 0 || w-(by-ay) == 0) {
      cout<<ans.x<<endl;
      return 0;
    }
  }
  // cout<<x<<" "<<y<<endl;
  if (x == 0 && y == 0) {
    puts("-1");
    return 0;
  }
  mint z = n+1;
  rep(i,n) {
    if (s[i] == 'R') y++;
    if (s[i] == 'L') y--;
    if (s[i] == 'U') x++;
    if (s[i] == 'D') x--;
    if (x < ax) {
      ax = x;
      lx.pb(i);
      ans += (z+i)*(w-(by-ay));
    }
    if (x > bx) {
      bx = x;
      rx.pb(i);
      ans += (z+i)*(w-(by-ay));
    }
    if (y < ay) {
      ay = y;
      ly.pb(i);
      ans += (z+i)*(h-(bx-ax));
    }
    if (y > by) {
      by = y;
      ry.pb(i);
      ans += (z+i)*(h-(bx-ax));
    }
    if (h-(bx-ax) == 0 || w-(by-ay) == 0) {
      cout<<ans.x<<endl;
      return 0;
    }
  }
  z += n;

  vp p;
  for (int t : lx) p.pb(P(t,0));
  for (int t : rx) p.pb(P(t,0));
  for (int t : ly) p.pb(P(t,1));
  for (int t : ry) p.pb(P(t,1));
  bx = h-(bx-ax);
  by = w-(by-ay);
  sort(rng(p));
  int pi = 0;
  if (sz(p) == 0) { // error
    puts("-1");
    return 0;
  }
  while (bx && by) {
    int i = p[pi].fi;
    int t = p[pi].se;
    if (t) {
      ans += (z+i)*bx;
      by--;
    } else {
      ans += (z+i)*by;
      bx--;
    }
    pi = pi+1;
    if (pi == sz(p)) {
      z += n;
      pi = 0;
    }
  }
  cout<<ans.x<<endl;
  return 0;
}