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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> ed(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  vector<int> vis(n);
  int cnt = 0;
  vector<int> stack;
  vector<int> ans;
  auto dfs = y_combinator([&](auto dfs, int cur, int prv = -1, int color = 1) -> void {
    if (sz(ans)) return;
    if (vis[cur]) {
      ans.push_back(cur);
      while (stack.back() != cur) {
        ans.push_back(stack.back());
        stack.pop_back();
      }
    }
    ++cnt;
    if (cnt > k) return;
    stack.push_back(cur);
    vis[cur] = color;
    for (int nxt: ed[cur]) {
      if (nxt == prv) continue;
      dfs(nxt, cur, 3 - color);
    }
    stack.pop_back();
  });
  dfs(1);
  if (sz(ans)) {
    cout << 2 << "\n";
    cout << sz(ans) << "\n";
    for (int i: ans) cout << i + 1 << " ";
    cout << "\n";
  } else {
    int color = 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (vis[i] == color) ++cnt;
    }
    if (cnt < (k + 1) / 2) {
      color = 2;
    }
    cout << 1 << "\n";
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (vis[i] == color && cnt < (k + 1) / 2) {
        ++cnt;
        cout << i + 1 << " ";
      }
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