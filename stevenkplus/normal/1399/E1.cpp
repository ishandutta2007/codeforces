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

typedef priority_queue<pll> MAX_PQ;
// ============= Solution ============= //
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    ll S;
    cin >> n >> S;
    vector<vector<pii>> ed(n);
    for (int i = 0; i < n - 1; ++i) {
      int v, u, w;
      cin >> v >> u >> w;
      --v, --u;
      ed[v].push_back(pii(u, w));
      ed[u].push_back(pii(v, w));
    }
    vector<int> par(n), weight(n), size(n);
    auto dfs = y_combinator([&](auto dfs, int cur, int prv = -1, int wt = 0) -> void {
      par[cur] = prv;
      weight[cur] = wt;
      // weight[cur] = 1E6;
      bool isleaf = true;
      for (auto p: ed[cur]) {
        if (p.fi == prv) continue;
        dfs(p.fi, cur, p.se);
        size[cur] += size[p.fi];
        isleaf = false;
      }
      if (isleaf) size[cur] += 1;
    });
    dfs(0);
    MAX_PQ pq;
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
      // size[i] = 1E5;
      ll cost = 1LL * weight[i] * size[i];
      cur += cost;
      ll save = 1LL * (weight[i] - weight[i] / 2) * size[i];
      pp(save);
      pq.push(pll(save, i));
      pp(pq.top());
    }

    int ans = 0;
    while (cur > S) {
      if (ans > n * 20) break;
      pll p = pq.top();
      pq.pop();
      pp(cur, p, weight, size);
      pp(p, p.fi);
      cur -= p.fi;
      ++ans;
      int i = p.se;
      weight[i] /= 2;
      ll save = 1LL * (weight[i] - weight[i] / 2) * size[i];
      pq.push(pll(save, i));
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