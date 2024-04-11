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
      int n, m;
      cin >> n >> m;
      vector<string> inp(n);
      for (string &s: inp) cin >> s;

      vector<vector<int>> mat(n, vector<int>(m));
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            mat[i][j] = inp[i][j] == '1';
         }
      }

      vector<vector<int>> ans;
      auto go = [&](int a, int b, int c, int d, int e, int f) {
         ans.push_back({a, b, c, d, e, f});
         mat[a][b] = !mat[a][b];
         mat[c][d] = !mat[c][d];
         mat[e][f] = !mat[e][f];
      };
      auto gg = [&](vector<int> v) {
         go(v[0], v[1], v[2], v[3], v[4], v[5]);
      };
      for (int i = 0; i < n - 2; ++i) {
         for (int j = 0; j < m; ++j) {
            if (mat[i][j]) {
               go(i, j, i + 1, j, i + 1, j + 1 < m ? j + 1 : j - 1);
            }
         }
      }
      for (int j = 0; j < m - 2; ++j) {
         for (int i = n - 2; i < n; ++i) {
            if (mat[i][j]) {
               go(i, j, n - 2, j + 1, n - 1, j + 1);
            }
         }
      }

      auto omat = mat;
      int a = n - 2, b = n - 1, c = m - 2, d = m - 1;
      int cnt = mat[a][c] + mat[a][d] + mat[b][c] + mat[b][d];
      for (int i = a; i <= b; ++i) {
         for (int j = c; j <= d; ++j) {
            vector<int> v;
            for (int ii = a; ii <= b; ++ii) {
               for (int jj = c; jj <= d; ++jj) {
                  if (ii == i && jj == j) continue;
                  v.push_back(ii);
                  v.push_back(jj);
               }
            }
            if (cnt == 4) {
               gg(v);
            } else if (cnt == 3 && !omat[i][j]) {
               gg(v);
            } else if (cnt == 2 && omat[i][j]) {
               gg(v);
            } else if (cnt == 1 && !omat[i][j]) {
               gg(v);
            }
         }
      }
      cout << sz(ans) << "\n";
      for (auto v: ans) {
         for (int i: v) {
            cout << i + 1 << " ";
         }
         cout << "\n";
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