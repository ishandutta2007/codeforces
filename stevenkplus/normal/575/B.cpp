// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

typedef pair<int, pii> piii;
// =========== Solution ============= //

const int MAXN = 1001000;
const int MAXH = 20;


bool vis[MAXN];
int par[MAXN];
pii parcost[MAXN];
int depth[MAXN];
pii dp[MAXN]; // dp[i][cur] number of times cur->root is traversed in direction i
vector<piii> ed[MAXN]; // ed[i] = pii(j, cost)

void dfs(int cur, int prv = 0, pii cost = pii(), int d = 0) {
  if (vis[cur]) return;
  vis[cur] = true;
  depth[cur] = d;
  par[cur] = prv;
  parcost[cur] = cost;
  for (auto p: ed[cur]) {
    dfs(p.fi, cur, p.se, d + 1);
  }
}

int jumppar[MAXN][MAXH];
int lca(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  int diff = depth[b] - depth[a];
  for(int i = 0; i < MAXH; ++i) {
    if (diff & (1 << i)) {
      b = jumppar[b][i];
    }
  }
  if (a == b) return a;
  for(int i = MAXH - 1; i >= 0; --i) {
    if (jumppar[a][i] != jumppar[b][i]) {
      a = jumppar[a][i];
      b = jumppar[b][i];
    }
  }
  return par[a];
}

const int MOD = 1E9 + 7;
ll costs[MAXN];
ll ans = 0;
pii dfs2(int cur) {
  pii cnt = dp[cur];
  for (auto p: ed[cur]) {
    if (p.fi == par[cur]) continue;
    pii q = dfs2(p.fi);
    cnt.fi += q.fi;
    cnt.se += q.se;
  }
  ans += parcost[cur].fi * costs[cnt.fi] % MOD;
  ans += parcost[cur].se * costs[cnt.se] % MOD;
  ans %= MOD;
  return cnt;
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 1) {
      ed[a].push_back(piii(b, pii(0, 1)));
      ed[b].push_back(piii(a, pii(1, 0)));
    } else {
      ed[a].push_back(piii(b, pii(0, 0)));
      ed[b].push_back(piii(a, pii(0, 0)));
    }
  }
  dfs(1);

  for (int i = 1; i <= n; ++i) {
    jumppar[i][0] = par[i];
  }
  for (int h = 0; h + 1 < MAXH; ++h) {
    for (int i = 1; i <= n; ++i) {
      jumppar[i][h + 1] = jumppar[jumppar[i][h]][h];
    }
  }
  int k;
  cin >> k;
  int cur = 1;
  for(int i = 0; i < k; ++i) {
    int nxt;
    cin >> nxt;
    int l = lca(cur, nxt);
    ++dp[cur].se;
    --dp[l].se;
    ++dp[nxt].fi;
    --dp[l].fi;
    cur = nxt;
  }

  for (int i = 0; i + 1 < MAXN; ++i) {
    costs[i + 1] = (costs[i] * 2 + 1) % MOD;
  }
  dfs2(1);
  cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases