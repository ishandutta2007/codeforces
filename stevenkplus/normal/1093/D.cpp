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

typedef priority_queue<pll, vector<pll>, greater<pll> > PQ;

// =========== Solution ============= //

const int MOD = 998244353;
const int MAXN = 300100;

vector<int> ed[MAXN];
int color[MAXN];
int counts[2 * MAXN];
ll pows[MAXN];

bool dfs(int cur, int c) {
  if (color[cur]) return color[cur] == c;
  color[cur] = c;
  ++counts[c];
  for (int nxt: ed[cur]) {
    if (!dfs(nxt, c ^ 1)) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  pows[0] = 1;
  for (int i = 0; i + 1 < MAXN; ++i) {
    pows[i + 1] = pows[i] * 2 % MOD;
  }
  for (int t = 1; t <= T; ++t) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      ed[i].clear();
      color[i] = 0;
      counts[i * 2] = 0;
      counts[i * 2 + 1] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      ed[a].push_back(b);
      ed[b].push_back(a);
    }

    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
      if (color[i]) continue;
      if (!dfs(i, 2 * i)) {
        ans = 0;
        continue;
      }
      ans = ans * (pows[counts[i * 2]] + pows[counts[i * 2 + 1]]) % MOD;
    }
    cout << ans << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (iterating to MAXN? indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases