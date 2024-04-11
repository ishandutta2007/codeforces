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

#define mx(a, b) a = max(a, b)
#define sub_to_errichto main
const int inf = 1000 << 20;

// ============= Solution ============= //
int sub_to_errichto() {
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;
      vector<int> v(n + 1);
      ll sm = 0;
      for (int i = 1; i <= n; ++i) {
         cin >> v[i];
         sm += v[i];
      }
      pp(v, sm);
      if (sm % n) {
         cout << "-1\n";
         continue;
      }

      int av = sm / n;
      vector<pair<pii, int>> ans;
      bool bad = false;
      auto go = [&](int i, int j, int x) {
         if (x == 0) return;
         ans.push_back({{i, j}, x});
         v[i] -= i * x;
         v[j] += i * x;
      };

      vector<pii> pairs;

      // 1) move everything to v[1]
      for (int i = 2; i <= n; ++i) {
         if (v[1] + v[i] >= i) {
            int val = v[1] + v[i];
            val -= val % i;
            go(1, i, val - v[i]);
            go(i, 1, v[i] / i);
         } else {
            pairs.push_back(pii(v[i] - i, i));
         }
      }
      sort(pairs.begin(), pairs.end());
      for (pii p: pairs) {
         int i = p.se;
         if (v[1] + v[i] >= i) {
            int val = v[1] + v[i];
            val -= val % i;
            go(1, i, val - v[i]);
            go(i, 1, v[i] / i);
         } else if (v[i] > av) {
            bad = true;
         }
      }

      // 2) redistribute
      for (int i = 2; i <= n; ++i) {
         go(1, i, av - v[i]);
      }

      if (bad) {
         cout << "-1\n";
      } else {
         cout << sz(ans) << "\n";
         for (auto p: ans) {
            cout << p.fi.fi << " " << p.fi.se << " " << p.se << "\n";
         }
      }
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases