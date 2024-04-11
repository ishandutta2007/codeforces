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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;
      n *= 2;
      string s;
      cin >> s;
      map<int, int> left;
      int val = 0;
      int ans = 0;
      for (int i = 0; i < n; ++i) {
         if (s[i] == '(') {
            // process left
            left[val] += 1;
            ans += 1;
            val += 1;
         } else {
            val -= 1;
            ans -= left[val];
            if (left[val]) {
               left[val] = 1;
            }
            left[val + 1] = 0;
            ans += 1;
            // process right
         }
         pp(i, s[i], ans, left, val);
      }
      // left[i] -> how many nodes on the left have value i
      // process_left(i) -> left[val[i]] += 1, ans += 1
      // process_right(i) ->
      //   ans -= left[val[i]]
      //   ans += 1
      //   left[val[i]] = 0
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