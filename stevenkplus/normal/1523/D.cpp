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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ============= Solution ============= //
int main() {
      // v[x] -> number of ppl who like exactly subset x
      // dp[x] -> number of ppl who like at least subset x
      //
      // dp[x] := v[x]
      // for y = 1 << k,
         // for all x; x | y != x
            // dp[x] += dp[x | y]

   int n, m, p;
   cin >> n >> m >> p;
   vector<ll> v(n);
   for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < m; ++j) {
         v[i] = v[i] * 2 + (s[j] == '1' ? 1 : 0);
      }
   }

   ll ans = 0;
   for (int rep = 0; rep < 30; ++rep) {
      ll msk = v[rng() % n];
      map<ll, int> mp;
      for (int i = 0; i < n; ++i) {
         ++mp[v[i] & msk];
      }
      map<ll, int> dp = mp;
      for (int i = 0; i < m; ++i) {
         ll y = 1LL << i;
         if (!(msk & y)) continue;
         for (ll x = (msk & ~y); x; x = (x - 1) & (msk & ~y)) {
            dp[x] += dp[x | y];
         }
      }
      for (auto p: dp) {
         if (p.se >= (n + 1) / 2) {
            if (__builtin_popcountll(p.fi) > __builtin_popcountll(ans)) {
               ans = p.fi;
            }
         }
      }
   }

   for (int i = m - 1; i >= 0; --i) {
      cout << ((ans >> i) & 1);
   }
   cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases