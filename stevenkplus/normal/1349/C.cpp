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

const int inf = 1 << 30;

// ============= Solution ============= //
int main() {
  int n, m, t;
  cin >> n >> m >> t;
  vector<string> vinp(n);
  for (auto &s: vinp) cin >> s;
  vector<int> v(n * m);
  vector<vector<int>> ed(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      v[i * m + j] = vinp[i][j] == '1';
      if (j + 1 < m) ed[i * m + j].push_back(i * m + j + 1);
      if (j > 0) ed[i * m + j].push_back(i * m + j - 1);
      if (i + 1 < n) ed[i * m + j].push_back(i * m + j + m);
      if (i > 0) ed[i * m + j].push_back(i * m + j - m);
    }
  }
  vector<bool> vis(n * m);
  vector<int> times(n * m);
  vector<int> colors(n * m);
  vector<int> queue;
  auto push = [&](int node, int color, int time) {
    if (vis[node]) return;
    vis[node] = true;
    colors[node] = color;
    times[node] = time;
    queue.push_back(node);
  };
  for (int i = 0; i < n * m; ++i) {
    bool ok = false;
    for (int j: ed[i]) {
      if (v[i] == v[j]) ok = true;
    }
    if (ok) {
      push(i, v[i], 0);
    }
  }

  for (int i = 0; i < sz(queue); ++i) {
    int cur = queue[i];
    for (int nxt: ed[cur]) {
      push(nxt, colors[cur], times[cur] + 1);
    }
  }

  for (int i = 0; i < t; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    int x = a * m + b;
    int ans = v[x];
    if (vis[x] && times[x] <= c) {
      ans = colors[x];
      if (c % 2 == 1) ans = 1 - ans;
    }
    cout << ans << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases