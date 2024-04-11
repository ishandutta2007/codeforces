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
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
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

namespace neal {
  template<typename float_t>
    struct complex {
      float_t x, y;
      complex<float_t>(float_t _x = 0, float_t _y = 0) : x(_x), y(_y) {}
      float_t real() const {
        return x;
      }
      void real(float_t _x) {
        x = _x;
      }
      float_t imag() const {
        return y;
      }
      void imag(float_t _y) {
        y = _y;
      }
      complex<float_t>& operator+=(const complex<float_t> &other) {
        x += other.x;
        y += other.y;
        return *this;
      }
      complex<float_t>& operator-=(const complex<float_t> &other) {
        x -= other.x;
        y -= other.y;
        return *this;
      }
      complex<float_t> operator+(const complex<float_t> &other) const {
        return complex<float_t>(*this) += other;
      }
      complex<float_t> operator-(const complex<float_t> &other) const {
        return complex<float_t>(*this) -= other;
      }
      complex<float_t> operator*(const complex<float_t> &other) const {
        return {x * other.x - y * other.y, x * other.y + other.x * y};
      }
      complex<float_t> operator*(float_t mult) const {
        return {x * mult, y * mult};
      }
    };
}
// https://cp-algorithms.com/algebra/fft.html
using cd = neal::complex<ld>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if (i < j)
      swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i+j], v = a[i+j+len/2] * w;
        a[i+j] = u + v;
        a[i+j+len/2] = u - v;
        w = w * wlen;
      }
    }
  }
  if (invert) {
    for (cd & x : a)
      x = x * (1. / n);
  }
}
// result will only be precise to 9E15
vector<ll> fftmultiply(vector<ll> a, vector<ll> b) {
  vector<ll> res(sz(a) + sz(b) - 1);
  int size = 1;
  while (size < sz(res)) size *= 2;
  vector<cd> av(size), bv(size);
  for (int i = 0; i < sz(a); ++i) av[i] = a[i];
  for (int i = 0; i < sz(b); ++i) bv[i] = b[i];
  fft(av, false);
  fft(bv, false);
  for (int i = 0; i < size; ++i) av[i] = av[i] * bv[i];
  fft(av, true);
  for (int i = 0; i < sz(res); ++i) res[i] = ll(av[i].real() + 0.5);
  return res;
}

// =========== Solution ============= //

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> inp(n);
  for (auto &i: inp) cin >> i;
  vector<int> prefs(n + 1);
  for (int i = 0; i < n; ++i) prefs[i + 1] = prefs[i] + (inp[i] < x);
  vector<ll> freqs(n + 1);
  for (auto i: prefs) ++freqs[i];
  pp(prefs);
  pp(freqs);
  vector<ll> rfreqs = freqs;
  reverse(rfreqs.begin(), rfreqs.end());
  vector<ll> prod = fftmultiply(freqs, rfreqs);
  pp(prod);
  prod[n] -= n + 1;
  prod[n] /= 2;
  pp(prod);
  for (int i = n; i <= 2 * n; ++i) {
    cout << prod[i] << " ";
  }
  cout << "\n";
}
// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - initialize & re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 forgot to initialize set with dummy node (n) [cf 1136e]
// - 3/28/20 array bounds (map was size MAXN instead of MAXK) [cf 1210b]
// - 3/29/20 array bounds ([MAXN][MAXN][4] -> [MAXN][MAXN * 2][4]) [cf 1051d]
// - 3/29/20 special cases (answer cannot be empty string) [cf 848a]
// - 3/29/20 special case / bad initialization of (ans, ansi) when backtracking [cf 733f]
// - 3/30/20 special case / "0" has length 0 in binary [cf 748b]
// - 4/2/20 fakesolve -- setup of dp states missed possible transitions / solutions [cf 771D]
// - 4/2/20 fakesolve -- cant count inversions in linear time, misunderstand structure of problem [cf 771D]
// - 4/3/20 (TLE) re-initialization was too slow [cf 1329 D]
// - 4/3/20 (WA) bottom-up segtree query didn't handle [0, n) correctly
// - 4/5/20 array bounds -- two different array sizes needed [cf 18d]
// - 4/5/20 fakesolve -- greedy sol was wrong,  needed dp [cf 18d]
// - 4/6/20 fakesolve -- tried to do LIS backtracking incorrectly w/ greedy approach, needed true backtracking [cf 650d]
// - 4/6/20 array bounds -- indexing with count into vector of size n; needs to be n + 1
// - 4/7/20 typo -- forgot to change i -> j when copying var declarations x -> y (4 copies) [cf 690b1]
// - 4/8/20 implementation error -- forgot to iterate in sorted order of x [cf 1045g]
// - 4/8/20 plane sweep implementation error -- insertion & removal orders are distinct (x_i & x_i + r_i) [cf 1045g]
// - 4/8/20 inf not big enough -- 1000 << 20 vs 1 billion + 1 billion [cf 1045g]