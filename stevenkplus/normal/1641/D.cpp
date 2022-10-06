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

template<typename T> vector<T> apply_ord(vector<T> v, vector<pii> ord) {
   vector<T> res(sz(v));
   for (int i = 0; i < sz(v); ++i) {
      res[i] = v[ord[i].se];
   }
   return res;
}

// ============= Solution ============= //
// maintain a data structure that supports insertion and deletion of sets of 5 numbers
// and can tell you, given an input set of 5 numbers, whether there exists a previously added set that is disjoint from it
//
// sort sets inc w
// use data structure to find the lexicographically minimum pair (i, j) such that a[i] and a[j] are disjoint
// set up data structure to contain sets a[0]...a[i]
// then sliding window -- decrease i, increase j until finding match, repeat
// guaranteed to iterate over all viable i, and guaranteed to find minimum j for all viable i

struct my_hash: public std::unary_function<array<int, 5>, std::size_t> {
   size_t operator()(const array<int, 5> &ar) const {
      int res = 0;
      auto h = hash<int>();
      for (int i = 0; i < 5; ++i) {
         res ^= h(ar[i]);
      }
      return res;
   }
};

int main() {
   int n, m;
   unordered_map<ll, unordered_map<ll, int>> cnts;
   int tot = 0;
   auto add = [&](vector<int> v, int sign) {
      for (int i = 0; i < (1 << m); ++i) {
         pll p;
         ll a = 1;
         ll b = 1;
         for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
               p.fi += a * v[j];
               p.se += b * v[j];
               a *= 37;
               b *= 1313;
            }
         }
         cnts[p.fi % 1000][p.se] += sign;
      }
      // pp(v, cnts, sign);
      tot += sign;
   };
   auto check = [&](vector<int> v) -> bool {
      int res = 0;
      for (int i = 0; i < (1 << m); ++i) {
         pll p;
         ll a = 1;
         ll b = 1;
         for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
               p.fi += a * v[j];
               p.se += b * v[j];
               a *= 37;
               b *= 1313;
            }
         }
         res += cnts[p.fi % 1000][p.se] * (__builtin_popcount(i) % 2 == 0 ? 1 : -1);
      }
      // pp(v, res, tot);
      return res > 0;
   };

   cin >> n >> m;
   vector<vector<int>> ar(n, vector<int>(m));
   vector<int> w(n);
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> ar[i][j];
      }
      sort(ar[i].begin(), ar[i].end());
      cin >> w[i];
   }
   vector<pii> ord(n);
   for (int i = 0; i < n; ++i) {
      ord[i].fi = w[i];
      ord[i].se = i;
   }
   sort(ord.begin(), ord.end());
   ar = apply_ord(ar, ord);
   w = apply_ord(w, ord);

   int cur = 0;
   while (cur < n && !check(ar[cur])) {
      add(ar[cur], 1);
      ++cur;
   }
   if (cur == n) {
      cout << "-1\n";
      exit(0);
   }
   // pp(ar);
   // pp(w);
   // pp(cur);
   int j = cur;
   int ans = w[j] + w[j];
   for (int i = cur - 1; i >= 0; --i) {
      while (j < n && !check(ar[j])) {
         ++j;
      }
      if (j == n) break;
      ans = min(ans, w[i] + w[j]);
      add(ar[i], -1);
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