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

// ============= Solution ============= //
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> inp(n, vector<int>(m));
  vector<vector<bool>> vis(n, vector<bool>(m));
  auto dfs = y_combinator([&](auto dfs, int i, int j) -> void {
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (!inp[i][j]) return;
    if (vis[i][j]) return;
    vis[i][j] = 1;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
  });

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      inp[i][j] = s[j] == '#';
    }
  }

  set<int> sr, sc;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (inp[i][j]) {
        sr.insert(i);
        sc.insert(j);
        if (!vis[i][j]) {
          ++ans;
          dfs(i, j);
        }
      }
    }
  }

  // check convexity
  for (int i = 0; i < n; ++i) {
    int state = 0;
    for (int j = 0; j < m; ++j) {
      if (inp[i][j]) {
        if (state == 0 || state == 2) ++state;
      } else {
        if (state == 1) ++state;
      }
    }
    if (state == 3) ans = -1;
  }
  // check convexity
  for (int j = 0; j < m; ++j) {
    int state = 0;
    for (int i = 0; i < n; ++i) {
      if (inp[i][j]) {
        if (state == 0 || state == 2) ++state;
      } else {
        if (state == 1) ++state;
      }
    }
    if (state == 3) ans = -1;
  }


  if ((sz(sr) == n && sz(sc) < m) || (sz(sr) < n && sz(sc) == m)) {
    ans = -1;
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