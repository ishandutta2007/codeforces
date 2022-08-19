#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
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
const int MX = 200005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n;
ll m;

// sliding queue
struct SQ { // max
  typedef ll TT;
  typedef pair<TT,ll> TP; // ab-x, ab
  deque<TP> q;
  void add(ll i, TT x) {
    while (sz(q) && q.back().fi >= x) q.pop_back();
    q.pb(TP(x,i));
  }
  TT get(ll i) { // i <= pos
    while (sz(q) > 1 && i-q[0].se > m) {
      if (q[0].fi+((i-q[0].se)-m) < q[1].fi) break;
      q.pop_front();
    }
    if (sz(q)) return q[0].fi+max(0ll,(i-q[0].se)-m);
    return LINF; // INF!
  }
};
//


int main() {
  scanf("%d%I64d",&n,&m);
  vl a(n);
  vl b(n);
  rep(i,n) {
    scanf("%I64d",&a[i]);
    mins(a[i],m);
    if (i != n-1) {
      scanf("%I64d",&b[i]);
      mins(b[i],m);
    }
  }
  ll ans = 0;
  vl x(n);
  x[0] = a[0];
  SQ q;
  ll s = a[0], t = 0;
  q.add(0,0);
  rep(i,n-1) {
    s += b[i]; t += x[i];
    q.add(s,s-t);
    s += a[i+1];
    // cout<<s<<" "<<t<<" "<<q.get(s)<<endl;
    // rep(j,sz(q.q)) cout<<q.q[j]<<endl;
    x[i+1] = (s-t)-q.get(s);
  }
  // cout<<x<<endl;
  rep(i,n) ans += x[i];
  cout<<ans<<endl;
  return 0;
}