#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
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
const int MX = 1000005, INF = 1001001001;
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
// linear sieve
vi ps, pf;
void sieve(int mx) {
  pf = vi(mx);
  rep(i,mx) pf[i] = i;
  for (int i = 2; i < mx; ++i) {
    if (pf[i] == i) ps.pb(i);
    for (int j = 0; j < sz(ps) && ps[j] <= pf[i]; ++j) {
      int x = ps[j]*i;
      if (x >= mx) break;
      pf[x] = ps[j];
    }
  }
}
inline bool isp(int x) { return pf[x] == x && x >= 2;}
//

int f(int& x, int y) {
  if (x%y) return 0;
  return f(x/=y,y)+1;
}

int main() {
  sieve(MX);
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) {
    int a,b;
    scanf("%d%d",&a,&b);
    ll g = (ll)a*b;
    ll l = 0, r = MX-3;
    while (l+1<r) {
      ll c = (l+r)/2;
      if (c*c*c <= g) l = c; else r = c;
    }
    bool ok = true;
    if (l*l*l != g) ok = false;
    else {
      g = l;
      vi p;
      while (g != 1) {
        p.pb(pf[g]);
        g /= pf[g];
      }
      sort(rng(p)); uni(p);
      for (int x : p) {
        int s = f(a,x);
        int t = f(b,x);
        if ((s+t)%3) ok = false;
        if (s*2 < t || t*2 < s) ok = false;
      }
      if (a != 1 || b != 1) ok = false;
    }
    puts(ok?"Yes":"No");
  }
  return 0;
}