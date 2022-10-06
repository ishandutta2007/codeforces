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
// =========== Book ============ //

// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, k;
      cin >> n >> k;
      vector<int> a(k), b(k);
      set<int> nums;
      for (int i = 0; i < k; ++i) {
         cin >> a[i] >> b[i];
         if (a[i] > b[i]) swap(a[i], b[i]);
      }
      for (int i = 1; i <= 2 * n; ++i) nums.insert(i);
      for (int i: a) nums.erase(i);
      for (int i: b) nums.erase(i);
      vector<int> v(nums.begin(), nums.end());
      for (int i = 0; i < 2 * (n - k); ++i) {
         if (i < (n - k)) {
            a.push_back(v[i]);
         } else {
            b.push_back(v[i]);
         }
      }

      auto contains = [&](int l, int r, int x) -> bool {
         return l <= x && x <= r;
      };
      auto isect = [&](int l, int r, int l2, int r2) -> bool {
         if (contains(l, r, l2) != contains(l, r, r2)) return true;
         else return false;
      };
      pp(a);
      pp(b);
      int ans = 0;
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < i; ++j) {
            if (isect(a[i], b[i], a[j], b[j])) ++ans;
         }
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