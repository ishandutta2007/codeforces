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
const int inf = 1000 << 20;
const ld PI = acos(ld(-1));

// ============= Solution ============= //
//

int sub_to_errichto() {
   int n;
   ll k;
   cin >> n >> k;
   vector<pii> v(n);
   for (auto &p: v) cin >> p.fi >> p.se;
   ld cur = 0, add = 1E5;
   auto norm = [&](ld ang) -> ld {
      if (ang < 0) return ang + 2 * PI;
      if (ang >= 2 * PI) return ang - 2 * PI;
      return ang;
   };

   // whether rad is too small, i.e. the number of pairs that intersect the circle is less than k
   auto ok = [&](ld rad) -> bool {
      using pdd = pair<ld, ld>;
      vector<pdd> segs;
      vector<ld> allAngs;
      for (auto p: v) {
         ld x = p.fi, y = p.se;
         if (x * x + y * y < rad * rad) {
            continue;
         }
         ld theta = atan2(y, x);
         ld alpha = acos(rad / sqrt(x * x + y * y));
         pp(p, theta, alpha);
         ld a = norm(theta + alpha), b = norm(theta - alpha);
         if (a > b) swap(a, b);
         segs.push_back(pdd(a, b));
         allAngs.push_back(a);
         allAngs.push_back(b);
      }
      sort(allAngs.begin(), allAngs.end());
      allAngs.resize(unique(allAngs.begin(), allAngs.end()) - allAngs.begin());
      auto get = [&](ld d) -> int {
         return lower_bound(allAngs.begin(), allAngs.end(), d) - allAngs.begin() + 1;
      };
      int m = sz(allAngs);
      vector<int> bit(m + 1);
      auto ask = [&](int x) -> int {
         int ret = 0;
         while (x) {
            ret += bit[x];
            x -= x & -x;
         }
         return ret;
      };
      auto inc = [&](int x) -> void {
         while (x <= m) {
            bit[x] += 1;
            x += x & -x;
         }
      };
      sort(segs.begin(), segs.end());

      ll cnt = 0; // count number of interval intersections (not disjoint & not contained)
      // this is equal to number of pairs of points that don't intersect the circle
      for (auto p: segs) {
         int a = get(p.fi);
         int b = get(p.se);
         pp(a, b);
         cnt += ask(b) - ask(a);
         inc(b);
      }

      pp(rad);
      pp(segs);
      pp(cnt);
      return 1LL * n * (n - 1) / 2 - cnt < k;
   };
   for (int i = 0; i < 60; ++i) { // 1E18 is good
      if (ok(cur + add)) cur += add;
      add /= 2;
   }

   cout << cur << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases