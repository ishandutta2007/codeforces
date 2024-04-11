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

// Segment tree
struct F { // sorted array
  vector<int> a;
  F(){}
  F(const vector<int>& a):a(a) {}
  F(int x):a(1,x) {}
  double operator()(int x) const {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
  }
  F operator+(const F& f) const {
    vector<int> res(a.size()+f.a.size());
    merge(a.begin(), a.end(),
          f.a.begin(), f.a.end(),
          res.begin());
    return F(res);
  }
};
struct seg {
  vector<F> d; int n;
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    d = vector<F>(n<<1);
  }
  void upd(int i) { d[i] = d[i<<1]+d[i<<1|1];}
  F& operator[](int i) { return d[n+i];}
  void init() { for (int i=n-1;i;--i) upd(i);}
  int get(int l, int r, int s, int t) {
    int res = get(l,r,t)-get(l,r,s);
    // cerr<<l<<" "<<r<<" "<<s<<" "<<t<<" "<<res<<endl;
    return res;
  }
  int get(int l, int r, int x) {
    l += n; r += n;
    int res = 0;
    while (l < r) {
      if (l&1) res += d[l++](x);
      if (r&1) res += d[--r](x);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};
//

int main() {
  int n,q;
  scanf("%d%d",&n,&q);
  seg t(n+1);
  rep(i,n) {
    int a;
    scanf("%d",&a);
    --a;
    t[i] = F(a);
  }
  t.init();

  vl c(n+1);
  rep(i,n+1) {
    c[i] = ll(i-1)*i/2;
  }

  rep(qi,q) {
    ll ans = c[n];
    int si,sj,ti,tj;
    scanf("%d%d%d%d",&si,&sj,&ti,&tj);
    --si; --sj;
    ans -= c[t.get(0,si,0,n)];
    ans -= c[t.get(ti,n,0,n)];
    ans -= c[t.get(0,n,0,sj)];
    ans -= c[t.get(0,n,tj,n)];
    ans += c[t.get(0,si,0,sj)];
    ans += c[t.get(0,si,tj,n)];
    ans += c[t.get(ti,n,0,sj)];
    ans += c[t.get(ti,n,tj,n)];
    printf("%lld\n",ans);
  }
  return 0;
}