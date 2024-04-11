// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //
const double PI = acos(-1.);
namespace ecnerwala {

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
      friend modnum pow(modnum a, ll p) {
         modnum ans = 1; assert(p >= 0);
         for (; p; p /= 2, a *= a) if (p&1) ans *= a;
         return ans;
      }
      friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
      friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
      friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
      friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
      friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
      friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
   };

   namespace fft {

      using std::swap;
      using std::vector;
      using std::min;
      using std::max;

      inline int nextPow2(int s) { return 1 << (s > 1 ? 32 - __builtin_clz(s-1) : 0); }

      // Complex
      template <typename dbl> struct cplx { /// start-hash
         dbl x, y;
         cplx(dbl x_ = 0, dbl y_ = 0) : x(x_), y(y_) { }
         friend cplx operator+(cplx a, cplx b) { return cplx(a.x + b.x, a.y + b.y); }
         friend cplx operator-(cplx a, cplx b) { return cplx(a.x - b.x, a.y - b.y); }
         friend cplx operator*(cplx a, cplx b) { return cplx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
         friend cplx conj(cplx a) { return cplx(a.x, -a.y); }
         friend cplx inv(cplx a) { dbl n = (a.x*a.x+a.y*a.y); return cplx(a.x/n,-a.y/n); }
      };

      // getRoot implementations
      template <typename num> struct getRoot {
         static num f(int k) = delete;
      };
      template <typename dbl> struct getRoot<cplx<dbl>> {
         static cplx<dbl> f(int k) {
            dbl a=2*PI/k;
            return cplx<dbl>(cos(a),sin(a));
         }
      };
      template <int MOD> struct primitive_root {
         static const int value;
      };
      template <> struct primitive_root<998244353> {
         static const int value = 3;
      };
      template <int MOD> struct getRoot<modnum<MOD>> {
         static modnum<MOD> f(int k) {
            assert((MOD-1)%k == 0);
            return pow(modnum<MOD>(primitive_root<MOD>::value), (MOD-1)/k);
         }
      };

      template <typename num> class fft {
         static vector<int> rev;
         static vector<num> rt;

         public:
         static void init(int n);
         template <typename Iterator> static void go(Iterator begin, int n);

         static vector<num> scratch_a;
         static vector<num> scratch_b;
      };

      template <typename num> vector<int> fft<num>::rev({0,1});
      template <typename num> vector<num> fft<num>::rt(2, num(1));
      template <typename num> vector<num> fft<num>::scratch_a;
      template <typename num> vector<num> fft<num>::scratch_b;

      template <typename num> void fft<num>::init(int n) {
         if (n <= sz(rt)) return;
         rev.resize(n);
         for (int i = 0; i < n; i++) {
            rev[i] = (rev[i>>1] | ((i&1)*n)) >> 1;
         }
         rt.reserve(n);
         for (int k = sz(rt); k < n; k *= 2) {
            rt.resize(2*k);
            num z = getRoot<num>::f(2*k);
            for (int i = k/2; i < k; i++) {
               rt[2*i] = rt[i], rt[2*i+1] = rt[i]*z;
            }
         }
      }

      template <typename num> template <typename Iterator> void fft<num>::go(Iterator begin, int n) {
         init(n);
         int s = __builtin_ctz(sz(rev)/n);
         for (int i = 0; i < n; i++) {
            if (i < (rev[i]>>s)) {
               swap(*(begin+i), *(begin+(rev[i]>>s)));
            }
         }
         for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i += 2 * k) {
               Iterator it1 = begin + i, it2 = it1 + k;
               for (int j = 0; j < k; j++, ++it1, ++it2) {
                  num t = rt[j+k] * *it2;
                  *it2 = *it1 - t;
                  *it1 = *it1 + t;
               }
            }
         }
      }

      template <typename num> struct fft_multiplier {
         template <typename IterA, typename IterB, typename IterOut>
            static void multiply(IterA ia, int sza, IterB ib, int szb, IterOut io) {
               vector<num>& fa = fft<num>::scratch_a;
               vector<num>& fb = fft<num>::scratch_b;

               if (sza == 0 || szb == 0) return;
               int s = sza + szb - 1;
               int n = nextPow2(s);
               fft<num>::init(n);
               if (sz(fa) < n) fa.resize(n);
               if (sz(fb) < n) fb.resize(n);
               copy(ia, ia+sza, fa.begin());
               fill(fa.begin()+sza, fa.begin()+n, num(0));
               copy(ib, ib + szb, fb.begin());
               fill(fb.begin()+szb, fb.begin()+n, num(0));
               fft<num>::go(fa.begin(), n);
               fft<num>::go(fb.begin(), n);
               num d = inv(num(n));
               for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i] * d;
               reverse(fa.begin()+1, fa.begin()+n);
               fft<num>::go(fa.begin(), n);
               copy(fa.begin(), fa.begin()+s, io);
            }
      };

      template <typename num>
         struct fft_inverser {
            template <typename IterA, typename IterOut>
               static void inverse(IterA ia, int sza, IterOut io) {
                  vector<num>& fa = fft<num>::scratch_a;
                  vector<num>& fb = fft<num>::scratch_b;

                  if (sza == 0) return;
                  int s = nextPow2(sza) * 2;
                  fft<num>::init(s);
                  if (sz(fa) < s) fa.resize(s);
                  if (sz(fb) < s) fb.resize(s);
                  fb[0] = inv(*ia);
                  for (int n = 1; n < sza; ) {
                     fill(fb.begin() + n, fb.begin() + 4 * n, num(0));
                     n *= 2;
                     copy(ia, ia+min(n,sza), fa.begin());
                     fill(fa.begin()+min(n,sza), fa.begin()+2*n, 0);
                     fft<num>::go(fb.begin(), 2*n);
                     fft<num>::go(fa.begin(), 2*n);
                     num d = inv(num(2*n));
                     for (int i = 0; i < 2*n; i++) fb[i] = fb[i] * (2 - fa[i] * fb[i]) * d;
                     reverse(fb.begin()+1, fb.begin()+2*n);
                     fft<num>::go(fb.begin(), 2*n);
                  }
                  copy(fb.begin(), fb.begin()+sza, io);
               }
         };

      template <typename dbl>
         struct fft_double_multiplier {
            template <typename IterA, typename IterB, typename IterOut>
               static void multiply(IterA ia, int sza, IterB ib, int szb, IterOut io) {
                  vector<cplx<dbl>>& fa = fft<cplx<dbl>>::scratch_a;
                  vector<cplx<dbl>>& fb = fft<cplx<dbl>>::scratch_b;

                  if (sza == 0 || szb == 0) return;
                  int s = sza + szb - 1;
                  int n = nextPow2(s);
                  fft<cplx<dbl>>::init(n);
                  if (sz(fa) < n) fa.resize(n);
                  if (sz(fb) < n) fb.resize(n);

                  fill(fa.begin(), fa.begin() + n, 0);
                  { auto it = ia; for (int i = 0; i < sza; ++i, ++it) fa[i].x = *it; }
                  { auto it = ib; for (int i = 0; i < szb; ++i, ++it) fa[i].y = *it; }
                  fft<cplx<dbl>>::go(fa.begin(), n);
                  for (auto& x : fa) x = x * x;
                  for (int i = 0; i < n; ++i) fb[i] = fa[(n-i)&(n-1)] - conj(fa[i]);
                  fft<cplx<dbl>>::go(fb.begin(), n);
                  { auto it = io; for (int i = 0; i < s; ++i, ++it) *it = fb[i].y / (4*n); }
               }
         };

      template <typename mnum>
         struct fft_mod_multiplier {
            template <typename IterA, typename IterB, typename IterOut>
               static void multiply(IterA ia, int sza, IterB ib, int szb, IterOut io) {
                  using cnum = cplx<double>;
                  vector<cnum>& fa = fft<cnum>::scratch_a;
                  vector<cnum>& fb = fft<cnum>::scratch_b;

                  if (sza == 0 || szb == 0) return;
                  int s = sza + szb - 1;
                  int n = nextPow2(s);
                  fft<cnum>::init(n);
                  if (sz(fa) < n) fa.resize(n);
                  if (sz(fb) < n) fb.resize(n);

                  { auto it = ia; for (int i = 0; i < sza; ++i, ++it) fa[i] = cnum(int(*it) & ((1<<15)-1), int(*it) >> 15); }
                  fill(fa.begin()+sza, fa.begin() + n, 0);
                  { auto it = ib; for (int i = 0; i < szb; ++i, ++it) fb[i] = cnum(int(*it) & ((1<<15)-1), int(*it) >> 15); }
                  fill(fb.begin()+szb, fb.begin() + n, 0);

                  fft<cnum>::go(fa.begin(), n);
                  fft<cnum>::go(fb.begin(), n);
                  double r0 = 0.5 / n; // 1/2n
                  for (int i = 0; i <= n/2; i++) {
                     int j = (n-i)&(n-1);
                     cnum g0 = (fb[i] + conj(fb[j])) * r0;
                     cnum g1 = (fb[i] - conj(fb[j])) * r0;
                     swap(g1.x, g1.y); g1.y *= -1;
                     if (j != i) {
                        swap(fa[j], fa[i]);
                        fb[j] = fa[j] * g1;
                        fa[j] = fa[j] * g0;
                     }
                     fb[i] = fa[i] * conj(g1);
                     fa[i] = fa[i] * conj(g0);
                  }
                  fft<cnum>::go(fa.begin(), n);
                  fft<cnum>::go(fb.begin(), n);
                  using ll = long long;
                  const ll m = mnum::MOD;
                  auto it = io;
                  for (int i = 0; i < s; ++i, ++it) {
                     *it = mnum((ll(fa[i].x+0.5)
                              + (ll(fa[i].y+0.5) % m << 15)
                              + (ll(fb[i].x+0.5) % m << 15)
                              + (ll(fb[i].y+0.5) % m << 30)) % m);
                  }
               }
         };

      template <class multiplier, typename num>
         struct multiply_inverser {
            template <typename IterA, typename IterOut>
               static void inverse(IterA ia, int sza, IterOut io) {
                  if (sza == 0) return;
                  int s = nextPow2(sza);
                  vector<num> b(s,num(0));
                  vector<num> tmp(2*s);
                  b[0] = inv(*ia);
                  for (int n = 1; n < sza; ) {
                     // TODO: could be square instead of multiply
                     multiplier::multiply(b.begin(),n,b.begin(),n,tmp.begin());
                     n = min(sza,2*n);
                     multiplier::multiply(tmp.begin(),n,ia,n,tmp.begin());
                     for (int i = 0; i < n; i++) b[i] = 2 * b[i] - tmp[i];
                  }
                  copy(b.begin(), b.begin()+sza, io);
               }
         };

      template <class multiplier, typename T> vector<T> multiply(const vector<T>& a, const vector<T>& b) {
         if (sz(a) == 0 || sz(b) == 0) return {};
         vector<T> r(max(0, sz(a) + sz(b) - 1));
         multiplier::multiply(begin(a), sz(a), begin(b), sz(b), begin(r));
         return r;
      }

      template <class inverser, typename T> vector<T> inverse(const vector<T>& a) {
         vector<T> r(sz(a));
         inverser::inverse(begin(a), sz(a), begin(r));
         return r;
      }

   }} // namespace ecnerwala::fft


// ============= Solution ============= //
// observation:
// compute for each generation the number of ways to reach each cell,
// where a generation occurs after the [a, b] operation.
// 
// the way to update (go from one generation to the next) is a matrix transform
// but furthermore, this matrix transform is a convolution
// - (coeff A[i][j] only depends on j - i)
// - formula: for a generation (a, b), and previous state v[0], v[1], ...
// - next state w satisfies
//   contribution of v[i] to w[j] is
//   v[i] * chs(a + b, b + i - j); // go "right" b + i - j times, go "left" a + j - i times
//     -- going left --> decrease index by 1
//     -- going right --> keep index constant
// 
// Solution:
// - precompute all factorials & reciprocols (so you can do choose in O(1))
// - use FFT to go from one generation to the next
//

#define MOD 998244353
int main() {
   using mint = ecnerwala::modnum<MOD>;
   int n;
   cin >> n;
   vector<int> a(n), b(n);
   for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
   const int maxn = 2E5 + 10;
   vector<mint> fac(maxn), ifac(maxn);
   for (int i = 0; i < maxn; ++i) {
      fac[i] = i == 0 ? 1 : i * fac[i - 1];
      ifac[i] = 1 / fac[i];
   }
   auto chs = [&](int n, int k) -> mint { // this gets inlined, right?
      if (k < 0 || k > n) return 0;
      return fac[n] * ifac[k] * ifac[n - k];
   };

   ecnerwala::fft::fft_multiplier<mint> multiplier;
   vector<mint> v = {1};
   for (int it = 0; it < n; ++it) {
      int x = sz(v), y = x + a[it] - b[it];
      vector<mint> mult(x + y);
      pp(a[it], b[it]);
      for (int i = 0; i < x + y; ++i) {
         // all j - i lie between -(x-1) and y-1
         mult[i] = chs(a[it] + b[it], b[it] + i - (x - 1));
      }
      reverse(mult.begin(), mult.end());
      vector<mint> w2(sz(v) + sz(mult) - 1);
      multiplier.multiply(v.begin(), sz(v), mult.begin(), sz(mult), w2.begin());
// andrew why are you like this??

      pp(v, mult, w2);
      vector<mint> w3(w2.begin() + x, w2.begin() + x + y);
      // vector<mint> w(sz(v) + a[it] - b[it]);
      // for (int i = 0; i < sz(v); ++i) { // 8 billion ops, because sum((5i)^2 for i = 1...1000) ~ 8 bililon
         // for (int j = 0; j < sz(w); ++j) {
            // w[j] += v[i] * chs(a[it] + b[it], b[it] + j - i);
         // }
      // }
      pp(w3, w2);
      v = w3;
   }

   mint ans = 0;
   for (mint i: v) ans += i;
   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases