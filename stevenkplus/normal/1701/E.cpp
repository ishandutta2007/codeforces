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
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;

// ============= Solution ============= //
// dp1[x][y] -> s[:x] = t[:y]
// dp2[x][y] -> s[x:] = t[y:]
// if dp1[x][y] != -1:
// take y (only if s[x] == t[y]) -> dp1[x + 1][y + 1] <= dp[x][y]
// del y -> dp1[x][y + 1] <= y + (y + 1 - x)


// if dp2[x][y] != -1:
// take y (only if s[n - 1 - x] = t[m - 1 - y]) -> dp2[x + 1][y + 1] <= dp[x][y] + 1
// del y -> dp2[x][y + 1] <= dp[x][y] + 1
// ans = 1 + dp1[x][y] + dp2[n - x][m - y] over all x,y, or dp2[n][m]

int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, m;
      cin >> n >> m;
      string s, t;
      cin >> s >> t;
      swap(s, t);
      swap(n, m);
      const int inf = 1000 << 20;
      vector<vector<int>> dp1(n + 1, vector<int>(m + 1, inf));
      vector<vector<int>> dp2(n + 1, vector<int>(m + 1, inf));
      dp1[0][0] = 0;
      dp2[0][0] = 0;
      for (int i = 0; i <= n; ++i) {
         for (int j = 0; j < m; ++j) {
            if (dp1[i][j] == inf) continue;
            if (i < n && s[i] == t[j]) {
               dp1[i + 1][j + 1] = min(dp1[i + 1][j + 1], dp1[i][j]);
            }
            dp1[i][j + 1] = min(dp1[i][j + 1], j + 1 + j + 1 - i);
         }
      }
      for (int i = 0; i <= n; ++i) {
         for (int j = 0; j < m; ++j) {
            if (i < n && s[n - i - 1] == t[m - j - 1]) {
               dp2[i + 1][j + 1] = min(dp2[i + 1][j + 1], dp2[i][j] + 1);
            }
            dp2[i][j + 1] = min(dp2[i][j + 1], dp2[i][j] + 1);
         }
      }

      pp(dp1);
      pp(dp2);
      int ans = inf;
      for (int x = 0; x <= n; ++x) {
         for (int y = 0; y <= m; ++y) {
            ans = min(ans, 1 + dp1[x][y] + dp2[n - x][m - y]);
            if (dp1[x][y] == 0) {
               ans = min(ans, dp2[n - x][m - y]);
            }
         }
      }
      if (ans == inf) ans = -1;
      cout << ans << "\n";
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