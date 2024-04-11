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

const int MAXN = 300100;

vector<int> ed[MAXN];
int nodeval[MAXN];
int dp[MAXN];
bool vis[MAXN];

int dfs(int cur) {
  if (vis[cur]) return dp[cur];
  dp[cur] = -1;
  vis[cur] = 1;

  int val = 0;
  for (int e: ed[cur]) {
    int v = dfs(e);
    if (v == -1) {
      return -1;
    }
    val = max(val, v);
  }

  dp[cur] = val + nodeval[cur];

  return dp[cur];
}

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i) {
    if (dfs(i) == -1) {
      cout << "-1\n";
      return 0;
    }
  }

  int ans = 0;
  for (char c = 'a'; c <= 'z'; ++c) {
    for (int i = 1; i <= n; ++i) {
      nodeval[i] = s[i - 1] == c;
      vis[i] = false;
      dp[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      ans = max(ans, dfs(i));
    }
  }
  cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases