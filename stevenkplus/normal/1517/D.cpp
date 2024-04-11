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

const int inf = 1 << 30;
int main() {
   int n, m, k;
   cin >> n >> m >> k;
   vector<vector<int>> dp(n, vector<int>(m, -1)), ndp;
   vector<vector<vector<int>>> ed(n, vector<vector<int>>(m, vector<int>(4)));
   vector<int> di = {0, 1, 0, -1};
   vector<int> dj = {1, 0, -1, 0};
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j + 1 < m; ++j) {
         cin >> ed[i][j][0];
         ed[i][j + 1][2] = ed[i][j][0];
      }
   }
   for (int i = 0; i + 1 < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> ed[i][j][1];
         ed[i + 1][j][3] = ed[i][j][1];
      }
   }
   if (k % 2 == 0) {
      dp = vector<vector<int>>(n, vector<int>(m, 0));
      while (k) {
         ndp = vector<vector<int>>(n, vector<int>(m, inf));
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               for (int d = 0; d < 4; ++d) {
                  int ni = i + di[d];
                  int nj = j + dj[d];
                  if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                     ndp[i][j] = min(ndp[i][j], dp[ni][nj] + 2 * ed[i][j][d]);
                  }
               }
            }
         }
         dp = ndp;
         k -= 2;
      }
   }
   for (auto v: dp) {
      for (int i: v) {
         cout << i << " ";
      }
      cout << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases