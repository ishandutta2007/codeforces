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
// =========== Book ============ //

// ============= Solution ============= //
int main() {
   int n = 200000;
   vector<vector<int>> primefacs(n + 1);
   for (int i = 2; i <= n; ++i) {
      if (sz(primefacs[i])) continue;
      for (int j = i; j <= n; j += i) {
         primefacs[j].push_back(i);
      }
   }
   int T;
   cin >> T;
   vector<multiset<ll>> sets(160);
   while (T--) {
      int n, Q;
      cin >> n >> Q;
      vector<int> v(n);
      for (int &i: v) cin >> i;
      vector<int> factors;
      for (int p: primefacs[n]) {
         factors.push_back(n / p);
      }
      int k = sz(factors);
      vector<vector<ll>> vals(k);
      for (int i = 0; i < k; ++i) {
         sets[i].clear();
         vals[i].resize(factors[i]);
      }
      auto upd = [&](int i, int j, ll delta) -> void {
         vals[j][i % factors[j]] += delta * factors[j];
      };
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < k; ++j) {
            upd(i, j, v[i]);
         }
      }

      for (int i = 0; i < k; ++i) {
         for (int j = 0; j < factors[i]; ++j) {
            sets[i].insert(vals[i][j]);
         }
      }
      // pp(factors);
      // pp(v);
      // pp(vals);
      // pp(s);
      auto get = [&]() -> ll {
         ll val = 0;
         for (int i = 0; i < k; ++i) {
            val = max(val, *sets[i].rbegin());
         }
         return val;
      };
      cout << get() << "\n";
      // return 0;
      while (Q--) {
         int p, x;
         cin >> p >> x;
         --p;
         for (int j = 0; j < k; ++j) {
            sets[j].erase(sets[j].find(vals[j][p % factors[j]]));
            upd(p, j, x - v[p]);
            sets[j].insert(vals[j][p % factors[j]]);
         }
         v[p] = x;
         cout << get() << "\n";
      }
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