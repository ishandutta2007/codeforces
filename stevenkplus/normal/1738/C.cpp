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

// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   int N = 101;
   vector<vector<vector<vector<int>>>> dp(N, vector<vector<vector<int>>>(N, vector<vector<int>>(2, vector<int>(2))));
   // first axis: number of evens
   // second axis: number of odds
   // dp = 1 -> winning for current player
   // t = 0 -> alice's turn
   dp[0][0][0][0] = 1;
   dp[0][0][1][1] = 1;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         for (int k = 0; k < 2; ++k) {
            for (int t = 0; t < 2; ++t) {
               if (dp[i][j][k][t]) continue;
               // inc i
               if (i + 1 < N) {
                  dp[i + 1][j][k][t ^ 1] = 1;
               }
               // inc j
               if (j + 1 < N) {
                  int nk = k;
                  if ((t ^ 1) == 0) nk ^= 1;
                  dp[i][j + 1][nk][t ^ 1] = 1;
               }
            }
         }
      }
   }

   while (T--) {
      int n;
      cin >> n;
      vector<int> v(n);
      for (int &i: v) cin >> i;
      int evens = 0, odds = 0;
      for (int i: v) {
         if (i % 2 == 0) ++evens;
         else ++odds;
      }
      string ans = "Bob";
      if (dp[evens][odds][0][0]) {
         ans = "Alice";
      }
      cout << ans << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases