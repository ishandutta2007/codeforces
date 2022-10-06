// =========== Template ========== //
#include <bits/stdc++.h>
// #include<bits/extc++.h>
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
using vi = vector<int>;
struct node;
ostream& operator<<(ostream &os, const node &node);
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
// struct splitmix64_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } }; // https://github.com/ecnerwala/cp-book/blob/master/src/hash_map.hpp
// struct splitmix64_hash_pll { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(pll x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.fi * 132453374217LL + x.se + FIXED_RANDOM); } }; // https://github.com/ecnerwala/cp-book/blob/master/src/hash_map.hpp thanks kevin
// template <typename K, typename V, typename Hash = splitmix64_hash> using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
// template <typename K, typename Hash = splitmix64_hash> using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;
// hash_map<ll, ll> hm; hash_map<pll, pll, splitmix64_hash_pll> hm2;
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

// ============= Solution ============= //
int main() {
   // directed graph a->b for every b that is closest to a
   // partition into minimum number (k) of sets -- each set is degree at most 4
   // each cluster is either j colors or 1...
   // dp[a][b] (a colors used so far, on the b-th cluster):
   // dp[a + 1][b + 1] += dp[a][b] * (n - a)
   // and dp[a + j][b + 1] += dp[a][b] * (n - a) * (n - a - 1) * ... * (n - a - (j - 1))


   // clusters can be computed by: for each i, see if it and its out-edges form a clique
   // if yes then mark its clique as visited and add to list of cliques
   // if no then mark self as visited and add as a singleton

   int n;
   cin >> n;
   vector<pii> points(n);
   auto getDist = [&](pii a, pii b) -> int {
      return abs(a.fi - b.fi) + abs(a.se - b.se);
   };
   vector<bool> visited(n);
   for (pii &p: points) cin >> p.fi >> p.se;
   vector<set<int>> guys(n);
   for (int i = 0; i < n; ++i) {
      set<int> closest;
      int minDist = 1E9;
      for (int j = 0; j < n; ++j) {
         if (i == j) continue;
         int dist = getDist(points[i], points[j]);
         if (dist < minDist) {
            minDist = dist;
            closest.clear();
         }
         if (dist == minDist) {
            closest.insert(j);
         }
      }
      guys[i] = closest;
      guys[i].insert(i);
   }
   vector<int> sizes;
   for (int i = 0; i < n; ++i) {
      bool bad = false;
      for (int j: guys[i]) {
         if (guys[i] != guys[j]) {
            bad = true;
            continue;
         }
      }
      if (bad) {
         sizes.push_back(1);
      } else if (i == *guys[i].begin()) {
         sizes.push_back(sz(guys[i]));
      }
   }

   using mint = modnum<998244353>;
   vector<mint> dp(n + 1);
   dp[0] = 1;
   for (int i: sizes) {
      vector<mint> ndp(n + 1);
      for (int j = 0; j < n; ++j) {
         ndp[j + 1] += dp[j] * (n - j);
         if (i > 1) {
            mint prod = 1;
            for (int k = 0; k < i; ++k) {
               prod *= n - j - k;
            }
            ndp[j + i] += dp[j] * prod;
         }
      }
      dp = ndp;
   }
   mint ans = 0;
   for (mint i: dp) ans += i;
   cout << ans << "\n";

}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases