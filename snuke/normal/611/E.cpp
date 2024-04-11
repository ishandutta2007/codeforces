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
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n;
int a[3];
int b[MX];
int s[8];
int c[8];

bool f(vi p, int m) {
  vi d;
  rep(i,m) {
    while (sz(p) && a[2] < p.back()) {
      d.pb(p.back());
      p.pop_back();
    }
    if (sz(p)) p.pop_back();
  }
  drep(i,sz(d)) p.pb(d[i]);
  while (m && sz(p) && p.back() > a[1]) {
    if (p.back() > a[0]+a[1]) return false;
    p.pop_back();
    --m;
  }
  rep(i,m) {
    if (sz(p) && a[1] >= p.back()) p.pop_back();
  }
  rep(i,m) {
    if (sz(p) && a[0] >= p.back()) p.pop_back();
  }
  return sz(p) == 0;
}

int main() {
  scanf("%d",&n);
  rep(i,3) scanf("%d",&a[i]);
  rep(i,n) scanf("%d",&b[i]);
  sort(a,a+3);
  sort(b,b+n);
  reverse(b,b+n);
  rep(i,8)rep(j,3)if(i>>j&1) s[i] += a[j];
  // sort(s,s+8);
  int ans = 0;
  vi p;
  rep(i,n) {
    int j = -1;
    drep(nj,8) if (b[i] <= s[nj]) j = nj;
    if (j == -1) {
      puts("-1");
      return 0;
    }
    if (j < 5) {
      p.pb(b[i]);
      continue;
    }
    // cout<<j<<endl;
    // for (int nj = j; nj < 8; ++nj) if (c[nj]) {
    //   c[nj]--;
    //   // int mx = 0;
    //   // rep(k,8) if ((nj&k) == k) {
    //   //   if (s[k] >= b[i]) maxs(mx, nj^k);
    //   // }
    //   // c[mx]++;
    //   j = -1;
    //   break;
    // }
    // if (j == -1) continue;
    c[7^j]++;
    ++ans;
  }
  // int sum = 0;
  // rep(i,8) if (i >= 5) sum += c[i];
  // sort(rng(p));
  // rep(i,sum) if (sz(p)) p.pop_back();
  while (c[1] && sz(p)) {
    if (p.back() > s[1]) break;
    p.pop_back();
    c[1]--;
  }
  vi pp;
  reverse(rng(p));
  while (sz(p) && p.back() > s[2]) {
    pp.pb(p.back());
    p.pop_back();
  }
  // reverse(rng(p));
  while (c[2] && sz(p)) {
    if (p.back() > s[2]) break;
    p.pop_back();
    c[2]--;
  }
  for (int xx : pp) p.pb(xx);
  sort(rng(p));
  {
    int l = -1, r = sz(p), m;
    while (l+1<r) {
      m = (l+r)>>1;
      if (f(p,m)) r = m; else l = m;
    }
    ans += r;
  }
  cout<<ans<<endl;
  return 0;
}