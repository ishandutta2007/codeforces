// http://codeforces.com/contest/632/problem/E
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
#define pcnt __builtin_popcountll
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
const int MX = 1001, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// FFT
struct C {
  double re, im;
  C(double re=0, double im=0): re(re), im(im) {}
  C& operator+=(const C& a) { re += a.re; im += a.im; return *this;}
  C& operator-=(const C& a) { re -= a.re; im -= a.im; return *this;}
  C& operator*=(const C& a) { return *this = C(re*a.re - im*a.im, re*a.im + im*a.re);}
  C& operator*=(double a) { re *= a; im *= a; return *this;}
  C& operator/=(double a) { re /= a; im /= a; return *this;}
  C operator+(const C& a) const { return C(*this) += a;}
  C operator-(const C& a) const { return C(*this) -= a;}
  C operator*(const C& a) const { return C(*this) *= a;}
  C operator*(double a) const { return C(*this) *= a;}
  C operator/(double a) const { return C(*this) /= a;}
  C operator~() const { return C(re,-im);}
};
int rup(double a) { return int(a+0.5);}
const double PI = acos(-1.0);
struct fft {
  int n, l;
  vector<C> d;
  fft(){}
  fft(int mx) { init(mx);}
  fft(vi& a, int mx=0) {
    if (!mx) mx = sz(a)*2-1;
    init(mx);
    rep(i,sz(a)) d[i].re = a[i];
    f();
  }
  fft(vi& a, vi& b, int mx=0) {
    if (!mx) mx = sz(a)+sz(b)-1;
    init(mx);
    rep(i,sz(a)) d[i].re = a[i];
    rep(i,sz(b)) d[i].im = b[i];
    f();
  }
  void init(int mx) {
    for (n=1,l=0;n<mx;n<<=1,++l);
    d.resize(n);
  }
  C& operator[](int i) { return d[i];}
  void operator*=(fft& a) {
    rep(i,n) d[i] *= a[i];
  }
  void f(int s=1) {
    rep(i,n){
      int j = 0;
      rep(k,l) if(i&(1<<k)) j |= (1<<(l-1-k));
      if(i < j) swap(d[i], d[j]);
    }
    for (int t = 1; t < n; t <<= 1) {
      C w(cos(PI/t), sin(PI/t)*s), x(1,0);
      v(C) W(t);
      rep(i,t) W[i] = x, x *= w;
      for (int i = 0; i < n; i += t<<1){
        rep(j,t) {
          C a = d[i+t+j]*W[j];
          d[i+t+j] = d[i+j]-a;
          d[i+j] += a;
        }
      }
    }
  }
  fft split() { // return imag
    fft a(n);
    a[0].re = d[0].re;
    srep(i,1,n) a[i] = C(d[i]-~d[n-i])/2;
    rep(i,n) d[i] = (d[i]-a[i])*C(0,-1);
    swap(d,a.d);
    return a;
  }
  void merge(fft& a) { // a:imag
    rep(i,n) d[i] += C(-a[i].im, a[i].re);
  }
  vi get(int w=0) {
    f(-1);
    if (!w) w = n;
    vi res(w);
    rep(i,w) res[i] = rup(d[i].re/n);
    return res;
  }
  vi getmod(int w) {
    f(-1);
    vi res(w);
    rep(i,w) res[i] = rup((d[i].re+d[i+w].re)/n);
    return res;
  }
  void get(vi& a, vi& b) {
    f(-1);
    int w = sz(a);
    if (w*2 <= n) {
      rep(i,w) a[i] = rup((d[i].re+d[i+w].re)/n);
      rep(i,w) b[i] = rup((d[i].im+d[i+w].im)/n);
    } else {
      rep(i,n) a[i] = rup(d[i].re/n);
      rep(i,n) b[i] = rup(d[i].im/n);
    }
  }
};
vi norm(vi a) {
  rep(i,sz(a)) a[i] = !!a[i];
  return a;
}
vi convolute(vi a, vi b) {
  fft s(a,b);
  fft t = s.split();
  s *= t;
  return s.get(sz(a)+sz(b)-1);
}
//

vi e;
vi ex(int t) {
  if (t == 1) return e;
  vi res = ex(t>>1);
  res = norm(convolute(res,res));
  if (t&1) res = norm(convolute(res,e));
  return res;
}

int main() {
  int n,t;
  scanf("%d%d",&n,&t);
  e = vi(MX);
  rep(i,n) {
    int x;
    scanf("%d",&x);
    e[x] = 1;
  }
  vi res = ex(t);
  vi ans;
  rep(i,sz(res)) if (res[i]) ans.pb(i);
  cout<<ans<<endl;
  return 0;
}