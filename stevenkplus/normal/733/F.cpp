// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
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

typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef pair<piiii, int> piiiii;

// =========== Solution ============= //

const int MAXN = 200100;
const int MAXH = 18;
vector<piii> ed[MAXN];
piii jumppar[MAXN][MAXH]; // jumppar[i][h] = piii(p, pii(maxcoste, maxcost(i...p)))
int depth[MAXN];

void dfs(int cur, piii prv = piii(), int d = 0) {
  jumppar[cur][0] = prv;
  depth[cur] = d;
  for (auto p: ed[cur]) {
    if (p.fi == prv.fi) continue;
    dfs(p.fi, piii(cur, p.se), d + 1);
  }
}

// returns max cost along path a--b
pii maxpath(int a, int b) {
  pii ret;
  if (depth[a] > depth[b]) swap(a, b);
  int diff = depth[b] - depth[a];
  for (int i = 0; i < MAXH; ++i) {
    if ((diff >> i) & 1) {
      ret = max(ret, jumppar[b][i].se);
      b = jumppar[b][i].fi;
    }
  }

  for (int i = MAXH - 1; i >= 0; --i) {
    if (jumppar[a][i].fi != jumppar[b][i].fi) {
      ret = max(ret, jumppar[b][i].se);
      b = jumppar[b][i].fi;
      ret = max(ret, jumppar[a][i].se);
      a = jumppar[a][i].fi;
    }
  }
  if (a != b) {
    ret = max(ret, jumppar[b][0].se);
    b = jumppar[b][0].fi;
    ret = max(ret, jumppar[a][0].se);
    a = jumppar[a][0].fi;
  }

  // assert a == b
  return ret;
}

bool inmst[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  vector<piiiii> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].fi.fi.fi;
  }
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].fi.fi.se;
  }
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].fi.se.fi >> edges[i].fi.se.se;
    edges[i].se = i + 1;
  }

  int S;
  cin >> S;

  sort(edges.begin(), edges.end());

  DSU dsu(n + 1);
  ll mstcost = 0;
  for (int i = 0; i < m; ++i) {
    int a = edges[i].fi.se.fi;
    int b = edges[i].fi.se.se;
    int w = edges[i].fi.fi.fi;
    if (dsu.join(a, b)) {
      pp(a, b);
      mstcost += w;
      ed[a].push_back(piii(b, pii(w, i)));
      ed[b].push_back(piii(a, pii(w, i)));
      inmst[i] = true;
    }
  }

  dfs(1);
  for (int h = 0; h + 1 < MAXH; ++h) {
    for (int i = 1; i <= n; ++i) {
      jumppar[i][h + 1] = piii(jumppar[jumppar[i][h].fi][h].fi, max(jumppar[i][h].se, jumppar[jumppar[i][h].fi][h].se));
    }
  }

  pp(mstcost);
  ll ans = mstcost + 1;
  int ansi = -1;
  for (int i = 0; i < m; ++i) {
    int a = edges[i].fi.se.fi;
    int b = edges[i].fi.se.se;
    pii maxp = maxpath(a, b);
    ll curcost = edges[i].fi.fi.fi - (S / edges[i].fi.fi.se);
    ll cand = mstcost - maxp.fi + curcost;
    if (cand < ans) {
      ans = cand;
      ansi = i;
    }
  }
  cout << ans << "\n";
  int a = edges[ansi].fi.se.fi;
  int b = edges[ansi].fi.se.se;
  pii maxp = maxpath(a, b);
  for (int i = 0; i < m; ++i) {
    if (i == ansi) {
      cout << edges[i].se << " " << edges[i].fi.fi.fi - (S / edges[i].fi.fi.se) << "\n";
    } else if (inmst[i]) {
      if (maxp.se == i) continue;
      cout << edges[i].se << " " << edges[i].fi.fi.fi << "\n";
    }
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