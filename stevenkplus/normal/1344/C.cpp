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
  auto dfs = y_combinator([&] (auto dfs, int cur, vector<vector<int>> &ed, vector<bool> &vis) -> void {
    if (vis[cur]) return;
    vis[cur] = true;
    for (int nxt: ed[cur]) {
      dfs(nxt, ed, vis);
    }
  });

  int n, m;
  cin >> n >> m;
  vector<vector<int>> ed(n), red(n);
  vector<bool> vis(n), rvis(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b; --a, --b;
    ed[a].push_back(b);
    red[b].push_back(a);
  }

  // toposort to check if it's a dag
  vector<int> deg(n);
  vector<int> to_check;
  for (int i = 0; i < n; ++i) {
    to_check.push_back(i);
    deg[i] = sz(red[i]);
  }
  for (int j = 0; j < sz(to_check); ++j) {
    int cur = to_check[j];
    if (deg[cur] == 0) {
      --deg[cur];
      for (auto nxt: ed[cur]) {
        --deg[nxt];
        if (deg[nxt] == 0) {
          to_check.push_back(nxt);
        }
      }
    }
  }

  bool cyc = false;
  for (int i: deg) {
    if (i != -1) {
      cyc = true;
    }
  }

  if (cyc) {
    cout << "-1\n";
    return 0;
  }

  int ans = 0;
  string s;
  for (int i = 0; i < n; ++i) {
    if (!vis[i] && !rvis[i]) {
      s += "A";
      ++ans;
    } else {
      s += "E";
    }
    dfs(i, ed, vis);
    dfs(i, red, rvis);
  }
  cout << ans << "\n";
  cout << s << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases