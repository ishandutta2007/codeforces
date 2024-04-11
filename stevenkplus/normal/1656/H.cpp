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

// https://codeforces.com/blog/entry/75044
istream& operator >> (istream& in, __int128& num) {
   // istream::get, istream::peek
   // Construct the answer in num, the same as read(num) from the blog, but using 
   // istream::get, istream::peek
   __int128 x = 0, f = 1;
   char ch = in.get();
   while (ch < '0' || ch > '9') {
      if (ch == '-') f = -1;
      ch = in.get();
   }
   while (ch >= '0' && ch <= '9') {
      x = x * 10 + ch - '0';
      ch = in.get();
   }
   num = x * f;
   return in;
}

   std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
   std::ostream::sentry s( dest );
   if ( s ) {
      __uint128_t tmp = value < 0 ? -value : value;
      char buffer[ 128 ];
      char* d = std::end( buffer );
      do
      {
         -- d;
         *d = "0123456789"[ tmp % 10 ];
         tmp /= 10;
      } while ( tmp != 0 );
      if ( value < 0 ) {
         -- d;
         *d = '-';
      }
      int len = std::end( buffer ) - d;
      if ( dest.rdbuf()->sputn( d, len ) != len ) {
         dest.setstate( std::ios_base::badbit );
      }
   }
   return dest;
}

int main() {
   using bigint = __int128_t;
   int T = 1;
   cin >> T;
   while (T--) {
      int n, m;
      cin >> n >> m;
      vector<bigint> a(n), b(m);
      for (bigint &i: a) cin >> i;
      for (bigint &i: b) cin >> i;

      int size = 1;
      while (size < n || size < m) size *= 2;
      vector<vector<bigint>> gcds(n, vector<bigint>(m));
      vector<vector<bigint>> sega(n, vector<bigint>(size * 2));
      vector<vector<bigint>> segb(m, vector<bigint>(size * 2));
      auto upd = [&](vector<bigint> &seg, int x, bigint val) -> void {
         for (seg[x += size] = val; x > 1; x /= 2) {
            bigint nval = __gcd(seg[x], seg[x ^ 1]);
            // if (seg[x / 2] == nval) break;
            seg[x / 2] = nval;
         }
      };

      pp('1');
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            gcds[i][j] = __gcd(a[i], b[j]);
            sega[i][size + j] = a[i] / gcds[i][j];
            segb[j][size + i] = b[j] / gcds[i][j];
         }
      }
      for (int i = 0; i < n; ++i) {
         for (int j = size - 1; j > 0; --j) {
            sega[i][j] = __gcd(sega[i][j * 2], sega[i][j * 2 + 1]);
         }
      }
      for (int i = 0; i < m; ++i) {
         for (int j = size - 1; j > 0; --j) {
            segb[i][j] = __gcd(segb[i][j * 2], segb[i][j * 2 + 1]);
         }
      }
      pp('2');

      vector<bool> goneA(n), goneB(m);
      while (true) {
         bool ok = true;
         for (int i = 0; i < n; ++i) {
            if (goneA[i]) continue;
            if (sega[i][1] != 1) {
               ok = false;
               goneA[i] = true;
               for (int j = 0; j < m; ++j) {
                  if (goneB[j]) continue;
                  upd(segb[j], i, 0);
               }
            }
         }
         for (int j = 0; j < m; ++j) {
            if (goneB[j]) continue;
            if (segb[j][1] != 1) {
               ok = false;
               goneB[j] = true;
               for (int i = 0; i < n; ++i) {
                  if (goneA[i]) continue;
                  upd(sega[i], j, 0);
               }
            }
         }
         if (ok) break;
      }
      pp('3');
      vector<bigint> ansa, ansb;
      for (int i = 0; i < n; ++i) {
         if (!goneA[i]) ansa.push_back(a[i]);
      }
      for (int i = 0; i < m; ++i) {
         if (!goneB[i]) ansb.push_back(b[i]);
      }
      if (sz(ansa) && sz(ansb)) {
         cout << "YES\n";
         cout << sz(ansa) << " " << sz(ansb) << "\n";
         for (bigint i: ansa) cout << i << " ";
         cout << "\n";
         for (bigint i: ansb) cout << i << " ";
         cout << "\n";
      } else {
         cout << "NO\n";
      }
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases