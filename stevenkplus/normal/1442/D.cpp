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

const int MAXN = 1000000;
const int MAXK = 20;

ll dist[MAXN][MAXK];

// ============= Solution ============= //
int sub_to_errichto() {
   int n, k;
   cin >> n >> k;
   vector<vector<int>> data(n);
   for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      data[i].resize(t);
      for (int &j: data[i]) {
         cin >> j;
      }
   }
   vector<ll> sums(n);
   vector<int> lens(n);
   for (int i = 0; i < n; ++i) {
      for (int j: data[i]) {
         sums[i] += j;
         ++lens[i];
      }
   }

   ll ans = 0;
   vector<ll> memo = {0}, memo2 = {0};
   int lo = 0, hi = 0;
   int lo2 = 0, hi2 = 0;
   for (int pos = 0; pos < n; ++pos) {
      pp("On", pos);
      if (pos == hi) {
         lo = pos;
         hi = pos + 100;
         vector<ll> dp(k + 1);
         for (int i = 0; i < n; ++i) {
            if ((lo <= i && i < hi)) continue;
            for (int j = k - lens[i]; j >= 0; --j) {
               dp[j + lens[i]] = max(dp[j + lens[i]], dp[j] + sums[i]);
            }
         }
         memo = dp;
         pp("Recomputing", lo, hi, memo);
      }
      if (pos == hi2) {
         lo2 = pos;
         hi2 = pos + 10;
         vector<ll> dp = memo;
         for (int i = 0; i < n; ++i) {
            if (!(lo <= i && i < hi)) continue;
            if ((lo2 <= i && i < hi2)) continue;
            for (int j = k - lens[i]; j >= 0; --j) {
               dp[j + lens[i]] = max(dp[j + lens[i]], dp[j] + sums[i]);
            }
         }
         memo2 = dp;
         pp("Recomputing 2", lo2, hi2, memo2);
      }
      vector<ll> dp = memo2;
      // consider partially taking pos-th array
      for (int i = 0; i < n; ++i) {
         if (!(lo2 <= i && i < hi2)) continue;
         if (i == pos) continue;
         for (int j = k - lens[i]; j >= 0; --j) {
            dp[j + lens[i]] = max(dp[j + lens[i]], dp[j] + sums[i]);
         }
      }

      vector<ll> prefs(lens[pos] + 1);
      for (int i = 0; i < lens[pos]; ++i) {
         prefs[i + 1] = prefs[i] + data[pos][i];
      }
      ll mx = 0;
      for (int i = 0; i <= k; ++i) {
         if (k - i > lens[pos]) continue;
         mx = max(mx, dp[i] + prefs[k - i]);
      }
      ans = max(ans, mx);
   }
   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases