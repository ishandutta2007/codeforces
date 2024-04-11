// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "{"; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define pp(...)
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

const int MAXN = 1010;
vector<int> ed[MAXN];
bool vis[MAXN];
pii farthest;
int par[MAXN];

void dfs(int cur, int prv = -1, int d = 0) {
  par[cur] = prv;
  vis[cur] = 1;
  farthest = max(farthest, pii(d, cur));
  for (auto nxt: ed[cur]) {
    if (nxt == prv) continue;
    dfs(nxt, cur, d + 1);
  }
}

pii go(int cur) {
  farthest = pii();
  dfs(cur);
  cur = farthest.se;
  farthest = pii();
  dfs(cur);
  cur = farthest.se;
  for (int i = 0; i < farthest.fi / 2; ++i) {
    cur = par[cur];
  }
  return pii(farthest.fi, cur);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  vector<pii> diameters;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      diameters.push_back(go(i));
    }
  }

  sort(diameters.begin(), diameters.end());
  reverse(diameters.begin(), diameters.end());
  int ans = diameters[0].fi;
  if (sz(diameters) > 1) {
    ans = max(ans, (diameters[0].fi + 1) / 2 + (diameters[1].fi + 1) / 2 + 1);
  }
  if (sz(diameters) > 2) {
    ans = max(ans, (diameters[1].fi + 1) / 2 + (diameters[2].fi + 1) / 2 + 2);
  }
  cout << ans << "\n";
  for (int i = 1; i < sz(diameters); ++i) {
    cout << diameters[0].se << " " << diameters[i].se << "\n";
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