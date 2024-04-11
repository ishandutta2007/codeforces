// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

// =========== Solution ============= //

const int MAXN = 300100;
int cyc[MAXN];
int counts[MAXN];
int cycIdx = 0;
vector<int> ed[MAXN];
int edges[MAXN];
vector<int> stk;
int vis[MAXN];
int evis[MAXN];
void dfs(int cur, int d = 1) {
  if (vis[cur]) {
    pp(cur, stk, d);
    ++cycIdx;
    for (int i = 0; i < d - vis[cur]; ++i) {
      cyc[stk[sz(stk) - 1 - i]] = cycIdx;
      ++counts[cycIdx];
    }
    return;
  }
  ppp("enter");
  vis[cur] = d;
  for (auto i: ed[cur]) {
    int nxt = edges[i] - cur;
    if (evis[i]) continue;
    evis[i] = 1;
    stk.push_back(cur);
    pp(cur, d + 1);
    dfs(nxt, d + 1);
    stk.pop_back();
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b; --a, --b;
    edges[i] = a + b;
    ed[a].push_back(i);
    ed[b].push_back(i);
  }
  counts[0] = n + 1;
  for (int i = 0; i < n; ++i) {
    pp(i, vis[i]);
    if (!vis[i]) dfs(i);
  }
  int l = 0, r = 0;
  vector<int> len(n);
  vector<int> left(n + 1);
  for (int i = 0; i <= n; ++i) left[i] = i;
  while (l < n) {
    left[r] = min(left[r], l);
    len[l] = max(len[l], r - l);
    if (r < n && counts[cyc[r]] > 1) {
      --counts[cyc[r]];
      ++r;
    } else {
      ++counts[cyc[l]];
      ++l;
    }
  }
  pp(left);
  pp(len);
  vector<ll> lenpref(n + 1);
  for (int i = 0; i < n; ++i) lenpref[i + 1] = lenpref[i] + len[i];

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y, --x;
    int mid = max(x, left[y]);
    ll ans = lenpref[mid] - lenpref[x];
    ll ym = y - mid;
    ans += ym * (ym + 1) / 2;
    cout << ans << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - initialize & re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 forgot to initialize set with dummy node (n) [cf 1136e]
// - 3/28/20 array bounds (map was size MAXN instead of MAXK) [cf 1210b]
// - 3/29/20 array bounds ([MAXN][MAXN][4] -> [MAXN][MAXN * 2][4]) [cf 1051d]
// - 3/29/20 special cases (answer cannot be empty string) [cf 848a]
// - 3/29/20 special case / bad initialization of (ans, ansi) when backtracking [cf 733f]
// - 3/30/20 special case / "0" has length 0 in binary [cf 748b]
// - 4/2/20 fakesolve -- setup of dp states missed possible transitions / solutions [cf 771D]
// - 4/2/20 fakesolve -- cant count inversions in linear time, misunderstand structure of problem [cf 771D]
// - 4/3/20 (TLE) re-initialization was too slow [cf 1329 D]
// - 4/3/20 (WA) bottom-up segtree query didn't handle [0, n) correctly
// - 4/5/20 array bounds -- two different array sizes needed [cf 18d]
// - 4/5/20 fakesolve -- greedy sol was wrong,  needed dp [cf 18d]
// - 4/6/20 fakesolve -- tried to do LIS backtracking incorrectly w/ greedy approach, needed true backtracking [cf 650d]
// - 4/6/20 array bounds -- indexing with count into vector of size n; needs to be n + 1
// - 4/7/20 typo -- forgot to change i -> j when copying var declarations x -> y (4 copies) [cf 690b1]
// - 4/8/20 implementation error -- forgot to iterate in sorted order of x [cf 1045g]
// - 4/8/20 plane sweep implementation error -- insertion & removal orders are distinct (x_i & x_i + r_i) [cf 1045g]
// - 4/8/20 inf not big enough -- 1000 << 20 vs 1 billion + 1 billion [cf 1045g]
// - 4/8/20 n ffts wayyy too slow (nlog^2n, n = 2^20, time limit = 1s) [cf 1227f2]
// - 4/8/20 int overflow (multiplied j * count[j] without LL, when adding to ll) [cf 804d]
// - 4/8/20 implementation error -- forgot to dfs again (a 3rd time) after finding both ends of diameter [cf 804d]
// - 4/8/20 typo -- cur.fi < n && cur.se < n <-- should be m
// - 4/10/20 implementation error -- need to erase before inserting into pdbs::tree [1093e]
// - 4/10/20 typo -- forgot to change n + 1 to m + 1 when fixing sliding window to be over edges instead of nodes [cf 901c]
// - 4/10/20 typo -- implementation error -- messed up dfs cycle detection; need to mark edges as vis instead of nodes / use a real algo [cf 901c]
// - 4/10/20 turns out i misread the problem and it's actually querying nodes, not edges
// - 4/10/20 typo -- s/m/n again in if (r < m && ...)