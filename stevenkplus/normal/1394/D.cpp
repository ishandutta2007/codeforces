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
const ll infl = 1LL << 60;

// ============= Solution ============= //
int main() {
  int n;
  cin >> n;
  vector<int> t(n), h(n);
  for (int &i: t) cin >> i;
  for (int &i: h) cin >> i;
  vector<vector<int>> ed(n), edsame(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    ed[u].push_back(v);
    ed[v].push_back(u);
  }
  vector<int> deg(n), outdeg(n);
  for (int i = 0; i < n; ++i) {
    deg[i] = sz(ed[i]);
    for (int nxt: ed[i]) {
      if (h[nxt] == h[i]) {
        edsame[i].push_back(nxt);
      } else if (h[nxt] > h[i]) {
        ++outdeg[i];
      }
    }
  }

  vector<pll> dp(n);
  vector<bool> vis(n);
  auto dfs = y_combinator([&](auto dfs, int cur, int prv = -1) -> void {
    pp("dfs", cur);
    vis[cur] = true;
    ll chsum = 0;
    vector<ll> chdiffs;
    for (int nxt: edsame[cur]) {
      if (nxt == prv) continue;
      dfs(nxt, cur);
      chsum += dp[nxt].se;
      chdiffs.push_back(dp[nxt].fi - dp[nxt].se);
    }
    sort(chdiffs.begin(), chdiffs.end());
    vector<ll> chdiffsums({0});
    for (ll val: chdiffs) chdiffsums.push_back(chdiffsums.back() + val);

    vector<ll> res(2);
    for (int par = 0; par < 2; ++par) {
      res[par] = infl;
      for (int i = 0; i < sz(chdiffsums); ++i) {
        int out = i + par + outdeg[cur];
        ll times = max(deg[cur] - out, out);
        pp(cur, par, i, times);
        ll cost = times * t[cur] + chdiffsums[i] + chsum;
        res[par] = min(res[par], cost);
      }
    }
    dp[cur] = pll(res[0], res[1]);
  });

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i);
      ans += dp[i].fi;
    }
  }
  pp(dp);
  cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases

// - initialize & re-initialize efficiently between test cases