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

const int inf = 1000 << 20;
const double pi = acos(-1.);

// ordered_set with order_of_key and find_by_order
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// WARNING: functions as a set (doesn't allow duplicates); insert pairs instead if duplicates are needed.
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ============= Solution ============= //


int main() {
  int n, m;
  cin >> n >> m;
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<vector<int>> ed(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b; --a, --b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  vector<int> seen(n); // 0, 1, or 2
  int c1, c2;
  bool bad = false;
  vector<int> v1, v2;
  auto dfs = y_combinator([&](auto dfs, int cur, int col) -> void {
    if (seen[cur]) {
      if (seen[cur] != col) {
        bad = true;
      }
      return;
    }
    seen[cur] = col;
    if (col == 1) {
      ++c1;
      v1.push_back(cur);
    } else {
      ++c2;
      v2.push_back(cur);
    }
    for (auto nxt: ed[cur]) {
      dfs(nxt, 3 -col);
    }
  });

  vector<vector<int>> v1s(n), v2s(n);
  for (int i = 0; i < n; ++i) {
    if (seen[i]) continue;
    c1 = 0; c2 = 0; v1.clear(); v2.clear(); dfs(i, 1);
    v1s[i] = v1;
    v2s[i] = v2;
  }

  vector<vector<int>> trace(n + 1, vector<int>(n + 1, -1));
  trace[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (trace[i][j] != -1) {
        trace[i + 1][j + sz(v1s[i])] = 1;
        trace[i + 1][j + sz(v2s[i])] = 2;
      }
    }
  }

  if (bad || trace[n][n2] == -1) {
    cout << "NO\n";
    return 0;
  }

  vector<int> ans(n);
  int cur = n2;
  for (int i = n - 1; i >= 0; --i) {
    pp(i, cur, trace[i + 1][cur]);
    if (trace[i + 1][cur] == 1) {
      cur -= sz(v1s[i]);
      for (int x: v1s[i]) {
        ans[x] = 2;
      }
    } else {
      cur -= sz(v2s[i]);
      for (int x: v2s[i]) {
        ans[x] = 2;
      }
    }
  }

  int v1count = 0;
  for (int i = 0; i < n; ++i) {
    if (!ans[i]) {
      if (v1count < n1) {
        ans[i] = 1;
        ++v1count;
      } else {
        ans[i] = 3;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << ans[i];
  }
  cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases