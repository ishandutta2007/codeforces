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
int mat[100][100]; // mat[10 * a + b][10 * c + d] = 1 --> can't have c_a = b & c_c = d
int cannot[100];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<set<int>> inedges(n);
  vector<vector<pii>> outedges(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    outedges[u].push_back(pii(w, v));
  }
  for (auto v: outedges) {
    pp(v);
    sort(v.begin(), v.end());
    for (int i = 0; i < sz(v); ++i) {
      int to = v[i].se;
      int ch = 10 * sz(v) + i;
      if (inedges[to].find(ch) != inedges[to].end()) {
        pp(i, to);
        pp(ch);
        cannot[ch] = true;
      }
      inedges[to].insert(ch);
      pp(to, ch);
    }
  }
  for (auto s: inedges) {
    vector<int> v(s.begin(), s.end());
    pp(s);
    pp(v);
    for (int i: v) {
      for (int j: v) {
        mat[i][j] = true;
      }
    }
  }

  vector<int> stk(k + 1);
  int ans = 0;
  auto rec = y_combinator([&](auto rec, int pos) -> void {
    if (pos == k + 1) {
      ++ans;
      return;
    }
    for (int i = 0; i < pos; ++i) {
      bool bad = false;
      int ch = 10 * pos + i;
      if (cannot[ch]) continue;
      for (int j = 1; j < pos; ++j) {
        if (mat[10 * j + stk[j]][ch]) {
          bad = true;
          break;
        }
        pp(j, 10 * j + stk[j]);
      }
      if (bad) continue;
      pp(pos, i, 10 * pos + i);
      stk[pos] = i;
      rec(pos + 1);
    }
  });
  rec(1);
  cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases