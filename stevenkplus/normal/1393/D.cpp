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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ============= Solution ============= //
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      grid[i][j] = s[j] - 'a';
    }
  }
  vector<int> ids(26);
  for (int &i: ids) i = rng();

  vector<vector<int>> counts(vector<vector<int>>(n + m, vector<int>(n + m)));
  vector<vector<int>> rowcounts(vector<vector<int>>(n + m, vector<int>(n + m + 1)));
  vector<vector<int>> rectcounts(vector<vector<int>>(n + m + 1, vector<int>(n + m + 1)));
  pp(n + m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = i + j;
      int y = i - j + m - 1;
      pp(grid[i][j], x, y);
      counts[x][y] += ids[grid[i][j]];
    }
  }
  for (int x = 0; x < n + m; ++x) {
    for (int y = 0; y < n + m; ++y) {
      rowcounts[x][y + 1] = rowcounts[x][y] + counts[x][y];
      rectcounts[x + 1][y + 1] = rectcounts[x][y + 1] + rowcounts[x][y + 1];
    }
  }
  pp(counts);
  pp(rowcounts);
  pp(rectcounts);

  auto ok = [&](int i, int j, int rad) -> bool {
    int x = i + j;
    int y = i - j + m - 1;
    int x1 = x - rad + 1, x2 = x + rad;
    int y1 = y - rad + 1, y2 = y + rad;
    if (x1 < 0 || y1 < 0 || x2 >= n + m + 1 || y2 >= n + m + 1) return false;
    auto &v = rectcounts;
    int val = v[x2][y2] + v[x1][y1] - v[x1][y2] - v[x2][y1];
    pp(i, j, rad, val);
    return val == (1 + 2 * (rad) * (rad - 1)) * ids[grid[i][j]];
  };

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int lo = 1;
      int hi = n;
      while (lo < hi) {
        int cand = (lo + hi + 1) / 2;
        if (ok(i, j, cand)) {
          lo = cand;
        } else {
          hi = cand - 1;
        }
      }
      ans += lo;
    }
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