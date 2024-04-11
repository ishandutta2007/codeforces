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
const int MX = 500005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// FFT
#include <complex>
typedef complex<double> C;
const double PI = acos(-1.0);
struct fft {
  int n, l;
  vector<C> d;
  fft(int mx) {
    for (n=1,l=0;n<mx;n<<=1,++l);
    d.resize(n);
    // cerr<<n<<endl;
  }
  void f(int s=1) {
    rep(i,n){
      int j = 0;
      rep(k,l) if(i&(1<<k)) j |= (1<<(l-1-k));
      if(i < j) swap(d[i], d[j]);
    }
    for (int t = 1; t < n; t <<= 1) {
      C w(cos(PI/t), sin(PI/t)*s);
      for (int i = 0; i < n; i += t<<1){
        C v(1,0);
        rep(j,t) {
          C a = d[i+j] + d[i+t+j]*v;
          C b = d[i+j] - d[i+t+j]*v;
          d[i+j] = a; d[i+t+j] = b;
          v *= w;
        }
      }
    }
  }
};
//

char cs[MX];

void solve() {
  int n;
  scanf(" %d %s",&n,cs);
  // cerr<<n<<" "<<cs<<endl; return;
  vi s(n);
  rep(i,n) {
    if (cs[i] == 'V') s[i] = 0;
    else if (cs[i] == 'K') s[i] = 1;
    else s[i] = -1;
  }
  int m = n*2+3;
  vi cnt(n+1);
  rep(bi,2) {
    fft a(m), b(m);
    rep(i,n) {
      if (s[i] == bi) a.d[i].real(1);
      if (s[i] == (bi^1)) b.d[n-i].real(1);
    }
    a.f(); b.f();
    rep(i,a.n) a.d[i] *= b.d[i];
    a.f(-1);
    rrep(i,n) cnt[i] |= ll(a.d[n-i].real()+0.5);
    // cerr<<cnt<<endl;
  }
  vi ans;
  rrep(i,n) {
    int c = 0;
    for (int j = i; j <= n; j += i) if (cnt[j]) c = 1;
    if (!c) ans.pb(i);
  }
  // cerr<<ans<<endl;
  printf("%d\n",sz(ans));
  priv(ans);
}

int main() {
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) solve();
  return 0;
}