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
   vector<int> a(n), b(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
   }

   vector<int> x(n), y(n);
   for (int i = 0; i < n; ++i) {
      x[i] = min(a[i], b[i]);
      y[i] = max(a[i], b[i]);
   }
   vector<pii> byx(n), byy(n);
   for (int i = 0; i < n; ++i) {
      byx[i] = pii(x[i], i);
      byy[i] = pii(y[i], i);
   }
   sort(byx.begin(), byx.end());
   sort(byy.begin(), byy.end());
   reverse(byy.begin(), byy.end());
   int lidx = 0;
   int ridx = 0;
   vector<bool> vis(n);
   auto getl = [&]() -> int {
      while (lidx < n && vis[byx[lidx].se]) {
         ++lidx;
      }
      if (lidx == n) return -1;
      return byx[lidx].se;
   };
   auto getr = [&]() -> int {
      while (ridx < n && vis[byy[ridx].se]) {
         ++ridx;
      }
      if (ridx == n) return -1;
      return byy[ridx].se;
   };

   int ans = 0;
   int l = 0, r = 2 * n;
   bool bad = false;
   auto go = [&]() {
      if (bad) return false;
      int taken = 0, cost = 0;
      auto takel = [&](bool force) -> bool {
         if (bad) return false;
         int nxt = getl();
         if (nxt == -1) return false;
         if (x[nxt] < l || force) {
            if (y[nxt] < l || y[nxt] > r) {
               bad = true;
               return false;
            }
            pp("takel", x[nxt], y[nxt]);

            ++taken;
            vis[nxt] = true;
            if (a[nxt] == y[nxt]) ++cost;
            r = y[nxt];
            return true;
         }
         return false;
      };

      auto taker = [&](bool force) {
         if (bad) return false;
         int nxt = getr();
         if (nxt == -1) return false;
         if (y[nxt] > r || force) {
            if (x[nxt] < l || x[nxt] > r) {
               bad = true;
               return false;
            }
            pp("taker", y[nxt], x[nxt]);

            ++taken;
            vis[nxt] = true;
            if (a[nxt] == x[nxt]) ++cost;
            l = x[nxt];
            return true;
         }
         return false;
      };

      if (!takel(true)) return false;
      while (takel(false) || taker(false));
      pp(cost, taken);
      cost = min(cost, taken - cost);
      ans += cost;
      return true;
   };

   while (go());

   if (bad) ans = -1;
   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases