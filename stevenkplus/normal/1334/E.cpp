// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");
  private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }
  public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }
  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }
  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};


const ll infl = 1LL << 60;
// ============= Solution ============= //

typedef modnum<998244353> mint;
int main() {
  ll D;
  cin >> D;
  vector<pll> v;
  for (ll i = 2; i * i <= D; ++i) {
    while (D % i == 0) {
      if (sz(v) == 0 || v.back().fi != i) v.push_back(pii(i, 0));
      ++v.back().se;
      D /= i;
    }
  }
  if (D != 1) {
    v.push_back(pll(D, 1));
  }
  vector<mint> fac(60);
  fac[0] = 1;
  for (int i = 1; i < 60; ++i) {
    fac[i] = fac[i - 1] * i;
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    ll a, b;
    cin >> a >> b;
    mint c = 1, d = 1;
    int ci = 0, di = 0;
    for (auto p: v) {
      int x = 0, y = 0;
      while (a % p.fi == 0) a /= p.fi, ++x;
      while (b % p.fi == 0) b /= p.fi, ++y;
      int xy = min(x, y);
      x -= xy;
      y -= xy;
      ci += x;
      di += y;
      c /= fac[x];
      d /= fac[y];
      pp(x, y);
    }
    c *= fac[ci];
    d *= fac[di];
    pp(ci, di);
    cout << c * d << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases