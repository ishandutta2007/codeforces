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
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

#define bsf __builtin_ctzll
ll gcd(ll a, ll b) {
  // a = abs(a); b = abs(b);
  if (!a || !b) return a|b;
  int t = bsf(a|b); a >>= bsf(a);
  do { b >>= bsf(b); if (a > b) swap(a, b); b -= a;} while (b);
  return a << t;
}
ll lcm(ll x, ll y) { return x/gcd(x,y)*y;}


int main() {
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) {
    ll x,y,s,t;
    scanf("%I64d%I64d%I64d%I64d",&x,&y,&s,&t);
    ll g = gcd(x,y);
    if (s == x/g && t == y/g) {
      puts("0");
      continue;
    }
    if (s == 0 || s == t) {
      puts("-1");
      continue;
    }
    // cerr<<x<<" "<<y<<" "<<s<<" "<<t<<endl;
    ll z = (y+t-1)/t*t-y;
    y += z;
    // cerr<<y<<" "<<z<<endl;
    ll l = -1, r = INF*2;
    while (l+1<r) {
      ll c = (l+r)/2;
      ll nl = x, nr = x+c*t+z;
      ll ny = y+c*t;
      ll ns = ny/t*s;
      if (nl <= ns && ns <= nr) r = c; else l = c;
    }
    ll ans = r*t+z;
    cout<<ans<<endl;
  }
  return 0;
}