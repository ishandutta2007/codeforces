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

// ============= Solution ============= //
int sub_to_errichto() { // fml
   int T;
   cin >> T;
   vector<int> primes = listPrimes(1E5);
   while (T--) {
      ll p, q;
      cin >> p >> q;
      ll cur = q;
      if (p % q) {
         cout << p << "\n";
         continue;
      }
      auto vp = [&](int x, ll p) {
         int ans = 0;
         while (p % x == 0) {
            ++ans;
            p /= x;
         }
         return ans;
      };
      ll ans = 0;
      auto check = [&](int x) {
         if (q % x == 0) {
            // consider p / x^vp_x(p) * x^vp_x(q) / x
            int a = vp(x, p);
            int b = vp(x, q);
            ll cand = p;
            for (int i = 0; i < a - b + 1; ++i) {
               cand /= x;
            }
            ans = max(ans, cand);
         }
      };
      for (int i: primes) {
         check(i);
         int a = vp(i, cur);
         for (int j = 0; j < a; ++j) {
            cur /= i;
         }
      }
      if (cur > 1) {
         check(cur);
      }

      cout << ans << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases