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

// ============= Solution ============= //
int main() { // plan out your code a bit more!
   int n;
   cin >> n;
   vector<pii> ab(n);
   for (int i = 0; i < n; ++i) {
      cin >> ab[i].fi >> ab[i].se;
   }
   sort(ab.begin(), ab.end());
   vector<int> r(n);
   for (int i = 0; i < n; ++i) {
      auto it = lower_bound(ab.begin(), ab.end(), pii(ab[i].fi + ab[i].se + 1, -1));
      r[i] = it - ab.begin();
   }

   int size = 1;
   while (size < n) size *= 2;
   ll infl = 1LL << 60;
   vector<ll> seg(2 * size, infl);
   auto ask = [&](int l, int r) -> ll {
      pp("ask", l, r);
      pp(seg);
      ll res = infl;
      l += size, r += size;
      while (l < r) {
         pp(l, r);
         if (l & 1) {
            res = min(res, seg[l]);
            ++l;
         }
         if (r & 1) {
            --r;
            res = min(res, seg[r]);
         }
         l /= 2;
         r /= 2;
      }
      return res;
   };
   auto set = [&](int x, ll val) {
      x += size;
      seg[x] = val;
      x /= 2;
      while (x) {
         seg[x] = min(seg[x * 2], seg[x * 2 + 1]);
         x /= 2;
      }
   };
   vector<ll> dp(n);
   dp[n - 1] = 0;
   set(n - 1, 0);
   for (int i = n - 2; i >= 0; --i) {
      dp[i] = ask(i + 1, r[i]);
      if (r[i] < n) {
         dp[i] = min(dp[i], dp[r[i]] + ab[r[i]].fi - ab[i].fi - ab[i].se);
      }
      set(i, dp[i]);
   }
   pp(dp);
   pp(r);

   ll ans = dp[0];
   for (int i = 0; i < n; ++i) {
      ans += ab[i].se;
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