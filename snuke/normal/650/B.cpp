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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
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
{for(T&x:v)i>>x;return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;for(T&x:v)s<<' '<<x;return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, a, b, t;

int f(string& s) {
  vi l, r;
  int x = 0;
  rep(i,n) {
    if (i) {
      x += a*2+1;
      if (s[i] == 'w') x += b;
      l.pb(x);
    } else l.pb(0);
  }
  reverse(s.begin()+1,s.end());
  x = 0;
  rep(i,n) {
    if (i) {
      x += a+1;
      if (s[i] == 'w') x += b;
      r.pb(x);
    } else r.pb(0);
  }
  // cout<<l<<" "<<r<<endl;
  int res = 0;
  rep(i,n) {
    x = t-l[i];
    if (x < 0) break;
    int now = i;
    now += upper_bound(rng(r),x)-r.begin();
    mins(now,n);
    maxs(res,now);
  }
  return res;
}

int main() {
  string s;
  cin >> n >> a >> b >> t >> s;
  int c = 1;
  if (s[0] == 'w') c += b;
  t -= c;
  if (t < 0) dame;
  if (n == 1) {
    puts("1");
    return 0;
  }
  string s2 = s;
  reverse(s2.begin()+1,s2.end());
  int ans = max(f(s),f(s2));
  cout<<ans<<endl;
  return 0;
}