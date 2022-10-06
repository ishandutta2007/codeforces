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

// ============= Solution ============= //
int sub_to_errichto() { // fml
   int T;
   cin >> T;
   while (T--) {
      int n, m, k;
      cin >> n >> m >> k;
      vector<vector<int>> ed(n);
      for (int i = 0; i < m; ++i) {
         int u, v;
         cin >> u >> v; --u, --v;
         ed[u].push_back(v);
         ed[v].push_back(u);
      }

      vector<int> deg(n);
      for (int i = 0; i < n; ++i) {
         deg[i] = sz(ed[i]);
      }
      vector<bool> deleted(n);
      vector<vector<int>> cands;
      int thres = k - 1;
      auto check = yc([&](auto rec, int cur) -> void {
         if (deleted[cur]) return;
         if (deg[cur] >= thres) return;
         if (deg[cur] == thres - 1 && 1LL * k * (k - 1) / 2 <= m) {
            vector<int> cand = {cur};
            for (int i: ed[cur]) {
               if (!deleted[i]) {
                  cand.push_back(i);
               }
            }
            cands.push_back(cand);
         }
         deleted[cur] = true;
         for (int i: ed[cur]) {
            --deg[i];
         }
         for (int i: ed[cur]) {
            rec(i);
         }
      });
      for (int i = 0; i < n; ++i) {
         check(i);
      }
      thres = k;
      cands.clear();
      for (int i = 0; i < n; ++i) {
         check(i);
      }

      vector<int> res;
      for (int i = 0; i < n; ++i) {
         if (!deleted[i]) {
            res.push_back(i);
         }
      }
      if (sz(res)) {
         cout << "1 " << sz(res) << "\n";
         for (int i: res) {
            cout << i + 1 << " ";
         }
         cout << "\n";
      } else {
         unordered_set<ll> conn;
         for (int i = 0; i < n; ++i) {
            for (int j: ed[i]) {
               if (i < j)
               conn.insert(1LL * i * n + j);
            }
         }
         vector<int> clique;
         for (auto cand: cands) {
            if (sz(cand) != k) {
               throw "gg";
            }
            bool bad = false;
            for (int i: cand) {
               for (int j: cand) {
                  if (i < j && !conn.count(1LL * i * n + j)) {
                     bad = true;
                     break;
                  }
               }
               if (bad) break;
            }
            if (!bad) {
               clique = cand;
               break;
            }
         }
         if (sz(clique)) {
            cout << "2\n";
            for (int i: clique) {
               cout << i + 1 << " ";
            }
            cout << "\n";
         } else {
            cout << "-1\n";
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