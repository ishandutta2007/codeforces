#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

// Big integer
// abs, iszero, len, +-*/=, <, ==
// _func: abs func
const int B = 9; // keta
inline ll ten(int n) { return n?ten(n-1)*10:1;}
const int BS = ten(B);
struct bint;
istream& operator>>(istream&i, bint&a);
ostream& operator<<(ostream&o, const bint&a);
struct bint {
  vi d;
  bool sg; // +/0false, -true
  bint(ll n=0) {
    sg = n<0;
    if (sg) n = -n;
    while (n) {
      d.pb(n%BS);
      n /= BS;
    }
  }
  bint(const string& s) {
    sg = s[0] == '-';
    int si = sg;
    for (int i = sz(s); i > si; i -= B) {
      d.pb(0);
      for (int j = max(si,i-B); j < i; ++j) d.back() = d.back()*10 + (s[j]-'0');
    }
    cut();
  }
  bint(const vi& d, bool sg=false):d(d),sg(sg) {}
  inline bint& cut() {
    while (sz(d) && !d.back()) d.pop_back();
    sg &= !iszero();
    return *this;
  }
  inline int size() const { return sz(d);}
  inline int& operator[](int i) { return d[i];}
  inline const int& operator[](int i) const { return d[i];}
  inline int len() const {
    if (!sz(d)) return 0;
    int l = (sz(d)-1)*B;
    int b = d.back();
    while (b) ++l, b /= 10;
    return l;
  }
  bint abs() const { bint a(*this); a.sg = false; return a;}
  inline bool iszero() const { return !sz(d);}
  ll toLL() const {
    if (bint(INF) < abs()) return sg?-INF:INF;
    ll x = 0;
    drep(i,sz(d)) x = x*BS+d[i];
    if (sg) x = -x;
    return x;
  }

  bint& _add(const bint& a) {
    if (sz(d) <= sz(a)) d.resize(sz(a)+1);
    else d.pb(0);
    int i = 0;
    while (i < sz(a)) {
      d[i] += a[i];
      if (d[i] >= BS) d[i] -= BS, ++d[++i];
      else ++i;
    }
    while (d[i] == BS) d[i] = 0, ++d[++i];
    if (!d.back()) d.pop_back();
    return *this;
  }
  bint& _asub(const bint& a) { // assume this >= a
    int i = 0;
    while (i < sz(a)) {
      d[i] -= a[i];
      if (d[i] < 0) d[i] += BS, --d[++i];
      else ++i;
    }
    if (i < sz(d)) while (d[i] == -1) d[i] = BS-1, --d[++i];
    return cut();
  }
  bint& _sub(const bint& a) {
    if (_cmp(a)) {
      bint b(a);
      swap(*this,b);
      return _asub(b);
    }
    return _asub(a);
  }
  bint& operator+=(const bint& a) {
    if (sg == a.sg) return _add(a);
    return _sub(a);
  }
  bint& operator-=(const bint& a) {
    if (sg != a.sg) return _add(a);
    sg ^= 1; _sub(a); if (!iszero()) sg ^= 1;
    return *this;
  }
  bint& operator*=(ll a) {
    if (!a) return *this = 0;
    if (a < 0) sg ^= 1, a = -a;
    if (LINF/BS < a) return (*this) *= bint(a);
    ll x = 0;
    rep(i,sz(d)) {
      x += a*d[i];
      d[i] = x%BS;
      x /= BS;
    }
    while (x) d.pb(x%BS), x /= BS;
    return *this;
  }
  bint mult(const bint& a) const { // no ntt
    if (sz(a) == 1) return bint(*this)*=a[0];
    if (a.iszero()) return 0;
    bint b = (*this)*a.d.back();
    b.sg ^= a.sg;
    drep(i,sz(a)-1) {
      b.d.insert(b.d.begin(),0);
      b += (*this)*a[i];
    }
    return b;
  }
  ll operator%(ll a) const {
    assert(a > 0);
    ll r = 0;
    drep(i,sz(d)) r = (r*BS+d[i])%a;
    if (sg) r = (a-r)%a;
    return r;
  }
  bint& operator/=(ll a) {
    assert(a);
    if (a < 0) sg ^= 1, a = -a;
    assert(LINF/BS >= a);
    ll x = 0;
    drep(i,sz(d)) {
      x = x*BS+d[i];
      d[i] = x/a;
      x %= a;
    }
    return cut();
  }
  bint operator+(const bint& a) const { return bint(*this)+=a;}
  bint operator-(const bint& a) const { return bint(*this)-=a;}
  bint operator*(ll a) const { return bint(*this)*=a;}
  bint operator*(const bint& a) const;
  bint& operator*=(const bint& a) { return *this = (*this)*a;}
  bint operator/(ll a) const { return bint(*this)/=a;}
  bint operator/(const bint& a) const { assert(false); return bint();} // TODO
  bint operator%(const bint& a) const { assert(false); return bint();} // TODO
  bint square() const;
  bint ex(ll t) const {
    if (!t) return 1;
    bint a = ex(t>>1).square();
    if (t&1) return a*(*this);
    return a;
  }

  bool _cmp(const bint& a) const {
    if (sz(d) != sz(a)) return sz(d) < sz(a);
    drep(i,sz(d)) if (d[i] != a[i]) return d[i] < a[i];
    return false;
  }
  bool operator<(const bint& a) const {
    if (sg != a.sg) return sg;
    return sg?a._cmp(*this):_cmp(a);
  }
  bool operator<=(const bint& a) const { return !(a < (*this));}
  bool operator==(const bint& a) const { return sg == a.sg && d == a.d;}
  string str() const {
    if (!sz(d)) return "0";
    ostringstream os;
    if (sg) os<<'-';
    os<<d.back();
    drep(i,sz(d)-1) os<<setw(B)<<setfill('0')<<d[i];
    return os.str();
  }
};
ll extgcd(ll a, ll b, ll& x, ll& y) { for (ll u = y = 1, v = x = 0; a;) { ll q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
ll mod_inv(ll a, ll m) { ll x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
template<int mod, int primitive_root>
struct NTT {
  int get_mod() const { return mod;}
  void _ntt(vi& a, int sign) {
    const int n = sz(a);
    int h = mod_pow(primitive_root, (mod - 1) / n, mod); // h^n = 1
    if (sign == -1) h = mod_inv(h, mod); //h = h^-1 % mod
    int i = 0;
    for (int j = 1; j < n-1; ++j) {
      for (int k = n>>1; k > (i ^= k); k >>= 1);
      if (j < i) swap(a[i], a[j]);
    }
    for (int m = 1; m < n; m *= 2) {
      const int m2 = m*2;
      const ll base = mod_pow(h, n/m2, mod);
      vl w(m);
      w[0] = 1;
      for (int j = 1; j < m; ++j) w[j] = w[j-1]*base%mod;
      for (int s = 0; s < n; s += m2) {
        rep(x,m) {
          int j = s+x;
          int d = a[j+m]*w[x]%mod;
          a[j+m] = a[j]-d;
          if (a[j+m] < 0) a[j+m] += mod;
          a[j] -= mod-d;
          if (a[j] < 0) a[j] += mod;
        }
      }
    }
  }
  void ntt(vi& input) { _ntt(input, 1);}
  void intt(vi& input) {
    _ntt(input, -1);
    const int n_inv = mod_inv(sz(input), mod);
    for (auto& x : input) x = (ll)x*n_inv%mod;
  }
  vi convolution(const vi& a, const vi& b) {
    int ntt_size = 1;
    while (ntt_size < sz(a)+sz(b)) ntt_size *= 2;
    vi _a = a, _b = b;
    _a.resize(ntt_size); _b.resize(ntt_size);
    ntt(_a); ntt(_b);
    rep(i,ntt_size) _a[i] = (ll)_a[i]*_b[i]%mod;
    intt(_a);
    _a.resize(sz(a)+sz(b));
    return _a;
  }
  vi square(const vi& a) {
    int ntt_size = 1;
    while (ntt_size < sz(a)*2) ntt_size *= 2;
    vi _a = a;
    _a.resize(ntt_size);
    ntt(_a);
    rep(i,ntt_size) _a[i] = (ll)_a[i]*_a[i]%mod;
    intt(_a);
    _a.resize(sz(a)*2);
    return _a;
  }
};
const int P1 = 1811939329;
const int P2 = 2013265921; // P1<P2
const int P3 = 2113929217;
typedef NTT<P1,13> NTT_1;
typedef NTT<P2,31> NTT_2;
typedef NTT<P3, 5> NTT_3;
const ll P12 = (ll)P1*P2;
const int IP1_2 = mod_inv(P1,P2);
const int IP12_3 = mod_inv(P12,P3);
const ll P12_R = P12%BS;
const ll P12_Q = P12/BS;
vi _garner(vi& x, vi& y, vi& z) {
  ll c = 0;
  rep(i,sz(x)) {
    y[i] = ((ll)y[i]-x[i]+P2)*IP1_2 % P2;
    ll s = x[i] + (ll)y[i]*P1;
    z[i] = (z[i]-s%P3+P3)*IP12_3 % P3;
    s += c + P12_R*z[i];
    c = P12_Q*z[i] + s/BS;
    x[i] = s%BS;
  }
  return x;
}
bint bint::operator*(const bint& a) const {
  if (sz(a) <= 10) return mult(a);
  NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
  vi x = ntt1.convolution(d, a.d);
  vi y = ntt2.convolution(d, a.d);
  vi z = ntt3.convolution(d, a.d);
  return bint(_garner(x,y,z),sg^a.sg).cut();
}
bint bint::square() const {
  NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
  vi x = ntt1.square(d);
  vi y = ntt2.square(d);
  vi z = ntt3.square(d);
  return bint(_garner(x,y,z),false).cut();
}
istream& operator>>(istream&i, bint&a) {string s;i>>s;a=bint(s);return i;}
ostream& operator<<(ostream&o, const bint&a) { return o<<a.str();}
//

ll n;
int cnt;
int f(ll i, ll j) {
  i = n-i; j = n-j;
  cout<<i<<" "<<j<<endl;
  int res;
  cin>>res;
  ++cnt;
  return res;
}

bint area(P s, P t) {
  return bint(t.fi-s.fi)*(t.se-s.se);
}

int main() {
  cin>>n;

  P s(0,0);
  P t(n,n);
  P x(0,0);
  while (1) {
    bint a = (area(s,t)-area(s,x))/3+1;
    ll i, j;
    {
      ll l = x.fi, r = t.fi;
      while (l+1<r) {
        ll c = (l+r)>>1;
        if (area(P(c,s.se),t) < a) r = c; else l = c;
      }
      i = l;
    }
    {
      ll l = x.se, r = t.se;
      while (l+1<r) {
        ll c = (l+r)>>1;
        if (area(P(s.fi,c),t) < a) r = c; else l = c;
      }
      j = l;
    }
    int res = f(i,j);
    if (!res) break;
    if (res == 1) {
      t.fi = i;
    } else if (res == 2) {
      t.se = j;
    } else {
      x = P(i+1,j+1);
    }
    if (x.fi >= t.fi) s.se = x.se, x = s;
    if (x.se >= t.se) s.fi = x.fi, x = s;
  }
  cerr<<cnt<<endl;
  return 0;
}