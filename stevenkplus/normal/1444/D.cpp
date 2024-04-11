 #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
 #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
 #pragma GCC target("avx2")  //Enable AVX
 // AVX-enabled std::bitset Pragmas (before #includes!)
 // - bitset<200000> takes ~ 1ms per 1000 operations on GNU C++14 & GNU C++17
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
#define sub_to_errichto main
// =========== Book ============ //

// Returns all primes less than n
vector<int> listPrimes(int n) {
   vector<bool> sv(n);
   vector<int> res;
   for (int i = 2; i < n; ++i) {
      if (sv[i]) continue;
      res.push_back(i);
      for (int j = i; j <= (n - 1) / i; ++j) {
         sv[i * j] = 1;
      }
   }
   return res;
}

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

const int MAXN = 1 << 19;

// ============= Solution ============= //
int sub_to_errichto() {
   int T;
   cin >> T;
   while (T--) {
      int h;
      cin >> h;
      vector<int> vh(h);
      for (int &i: vh) cin >> i;
      int w;
      cin >> w;
      vector<int> vw(w);
      for (int &i: vw) cin >> i;
      if (h != w) {
         cout << "No\n";
         continue;
      }

      int n = h;
      auto solve = [&](vector<int> &v) -> bool {
         int sum = 0;
         for (int i: v) sum += i;
         if (sum % 2) return false;
         using BS = bitset<MAXN>;
         vector<BS> vis(n + 1);
         vis[0][0] = 1;
         for (int i = 0; i < n; ++i) {
            vis[i + 1] = vis[i] | (vis[i] << v[i]);
         }

         if (!vis[n][sum / 2]) return false;
         int cur = sum / 2;
         for (int i = n - 1; i >= 0; --i) {
            if (!vis[i][cur]) {
               cur -= v[i];
               v[i] *= -1;
            }
         }
         return true;
      };
      if (solve(vh) && solve(vw)) {
         cout << "Yes\n";
         vector<int> vhp, vhn;
         vector<int> vwp, vwn;
         for (int i: vh) {
            if (i >= 0) {
               vhp.push_back(i);
            } else {
               vhn.push_back(i);
            }
         }
         for (int i: vw) {
            if (i >= 0) {
               vwp.push_back(i);
            } else {
               vwn.push_back(i);
            }
         }
         sort(vhp.begin(), vhp.end());
         sort(vhn.begin(), vhn.end());
         sort(vwp.begin(), vwp.end());
         sort(vwn.begin(), vwn.end());
         bool flip = false;
         if (sz(vhp) > sz(vwp)) {
            swap(vhp, vwp);
            swap(vhn, vwn);
            flip = true;
         }
         reverse(vhp.begin(), vhp.end());
         reverse(vwn.begin(), vwn.end());
         vector<int> vh = vhp;
         for (int i: vhn) {
            vh.push_back(i);
         }
         vector<int> vw = vwp;
         for (int i: vwn) {
            vw.push_back(i);
         }

         int x = 0, y = 0;
         for (int i = 0; i < n; ++i) {
            x += vh[i];
            if (flip) {
               cout << y << " " << x << "\n";
            } else {
               cout << x << " " << y << "\n";
            }
            y += vw[i];
            if (flip) {
               cout << y << " " << x << "\n";
            } else {
               cout << x << " " << y << "\n";
            }
         }
      } else {
         cout << "No\n";
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