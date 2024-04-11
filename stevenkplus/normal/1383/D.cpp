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

class DSU {
  vector<int> par;
  public:
  DSU(int size) {
    par = vector<int>(size);
    for (int i = 0; i < size; ++i) {
      par[i] = i;
    }
  }

  int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
  }

  // set a to point to b
  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      par[a] = b;
      return true;
    }
    return false;
  }
};

// ============= Solution ============= //
int main() {
  int T = 1;
  for (int t = 1; t <= T; ++t) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row: grid) for (int &c: row) cin >> c;
    vector<bool> rmx(n * m + 1), cmx(n * m + 1);
    for (int i = 0; i < n; ++i) {
      int mx = 0;
      for (int j = 0; j < m; ++j) {
        mx = max(mx, grid[i][j]);
      }
      rmx[mx] = true;
    }
    int pos = 0;
    for (int i = 0; i < m; ++i) {
      int mx = 0;
      for (int j = 0; j < n; ++j) {
        mx = max(mx, grid[j][i]);
      }
      cmx[mx] = true;
      if (rmx[mx]) ++pos;
    }
    vector<vector<int>> ans(n, vector<int>(m));
    vector<vector<int>> deg(n, vector<int>(m));
    vector<pii> q;

    pp(rmx);
    pp(cmx);
    auto chk = [&](int r, int c) -> void {
      if (r < 0 || c < 0 || r >= n || c >= m) return;
      ++deg[r][c];
      if (deg[r][c] == 2 && !ans[r][c]) {
        pp(pii(r, c));
        q.push_back(pii(r, c));
      }
    };

    int rpos = pos, cpos = pos;
    int dpos = pos - 1;
    for (int i = n * m; i > 0; --i) {
      pp(i);
      int r, c;
      if (rmx[i] && cmx[i]) {
        r = c = dpos;
        --dpos;
      } else if (rmx[i]) {
        r = rpos;
        ++rpos;
        c = pos - 1;
      } else if (cmx[i]) {
        r = pos - 1;
        c = cpos;
        ++cpos;
      } else {
        r = q.back().fi;
        c = q.back().se;
        q.pop_back();
      }
      pp(i, r, c);
      ans[r][c] = i;
      chk(r + 1, c);
      chk(r - 1, c);
      chk(r, c + 1);
      chk(r, c - 1);
    }
    for (auto v: ans) {
      for (int c: v) {
        cout << c << " ";
      }
      cout << "\n";
    }
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases