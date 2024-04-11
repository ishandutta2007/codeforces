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
#define pb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
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
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 10000005, M = 1005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int c[M+3][M+3];

ll a, b;

ll con(int x, int y) {
  if (x < M) return c[x][y];
  if (y == 0) return 1;
  if (y == 1) return x;
  if (y == 2) return ll(x-1)*x/2;
  return INF;
}
bool f(ll x, ll n) {
  ll pre = -1;
  for (ll i = x/a; i >= 0; --i) {
    ll j = (x-a*i)/b;
    ll s = con(i+j,j);
    n -= s;
    if (pre != j) n -= s;
    if (n < 0) return false;
    pre = j;
  }
  return true;
}

int cnt;
ll g(ll x) {
  cnt = 0;
  ll res = 0;
  ll pre = -1;
  for (ll i = x/a; i >= 0; --i) {
    ll j = (x-a*i)/b;
    ll s = con(i+j,j);
    ll t = pre!=j?2:1;
    cnt += s*t;
    res += s*((a*i+b*j)*t+b);
    if (pre != j) res += s*a;
    pre = j;
  }
  return res;
}

int main() {
  c[0][0] = 1;
  rep(i,M) {
    rep(j,i+1) c[i+1][j] += c[i][j], c[i+1][j+1] += c[i][j];
    rep(j,i+2) mins(c[i+1][j], INF);
  }
  int n;
  cin >> n >> a >> b;
  if (a > b) swap(a,b);
  if (!a) {
    cout<<b*(n-1)<<endl;
    return 0;
  }
  ll l = 0, r = b*n+1;
  while (l+1<r) {
    ll md = (l+r)>>1;
    if (f(md,n)) l = md; else r = md;
  }
  ll ans = g(l);
  n -= cnt;
  ans += n*(r+a+b);
  cout<<ans<<endl;
  return 0;
}