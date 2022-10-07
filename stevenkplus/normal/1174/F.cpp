// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
// int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { string sep = "{"; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
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

// =========== Book ============ //

// =========== Solution ============= //

const int MAXN = 200100;
vector<int> ed[MAXN];
int sz[MAXN];
int fav[MAXN];

void dfs(int cur, int prv = -1) {
  int &f = fav[cur];
  int ff = 0;
  sz[cur] = 1;
  for (int nxt: ed[cur]) {
    if (nxt == prv) continue;
    dfs(nxt, cur);
    if (sz[nxt] > ff) {
      ff = sz[nxt];
      f = nxt;
    }
    sz[cur] += sz[nxt];
  }
}

int askdist(int cur) {
  cout << "d " << cur << endl;
  int ans;
  cin >> ans;
  return ans;
}

int asknext(int cur) {
  cout << "s " << cur << endl;
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  dfs(1);
  pp("help");

  int cur = 1;
  int dst = askdist(cur);
  while (dst > 0) {
    pp(cur);
    cur = asknext(cur);
    --dst;
    if (sz[cur] == 1) break;
    pp(cur, dst);
    int nxt = cur;
    vector<int> path;
    path.push_back(nxt);
    while (sz[nxt] > sz[cur] / 2) {
      nxt = fav[nxt];
      path.push_back(nxt);
    }
    int ndst = askdist(nxt);
    int overlap = ((dst + path.size() - 1) - ndst) / 2;
    pp(overlap, path);
    cur = path[overlap];
    dst -= overlap;
  }

  cout << "! " << cur << endl;
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