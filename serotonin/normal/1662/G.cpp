#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000010;

int n, p[N];
vector <int> g[N], h[N];
ll sub[N], down[N], up[N], ans;

void dfsDown (int u = 1) {
  sub[u] = 1;
  for (int v : g[u]) {
    dfsDown(v);
    sub[u] += sub[v];
    down[u] += down[v];
  }
  down[u] += sub[u];
}

void dfsUp (int u = 1) {
  ll total = 0;
  for (int v : g[u]) total += down[v];
  for (int v : g[u]) {
    up[v] = total - down[v] + up[u] + n - sub[v];
    dfsUp(v);
  }
}

int getCentroid (int u = 1) {
  for (int v : g[u]) if (sub[v] > n / 2) return getCentroid(v);
  return u;
}

ll subset (map <int, int> &f) {
  vector <int> weights;
  while (!f.empty()) {
    auto [key, val] = *f.begin();
    f.erase(f.begin());
    if (val & 1) {
      if (val > 1) f[key << 1] += (val - 1) / 2;
      weights.emplace_back(key);
    } else {
      if (val > 2) f[key << 1] += (val - 2) / 2;
      weights.emplace_back(key);
      weights.emplace_back(key);
    }
  }
  bitset <N> dp; dp[0] = 1;
  for (int x : weights) dp |= dp << x;
  int half = (n - 1) / 2;
  while (!dp[half]) --half;
  return (ll) half * (n - 1 - half);
}

void relax (int i) {
  ll cur = up[i] + n;
  for (int j : g[i]) cur += down[j];
  map <int, int> f;
  for (int j : g[i]) ++f[sub[j]];
  ++f[n - sub[i]];
  cur += subset(f);
  ans = max(ans, cur);
}

int main() {
  clock_t st = clock();
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    scanf("%d", p + i);
    g[p[i]].emplace_back(i);
  }
  dfsDown(); dfsUp();
  queue <int> q;
  int root = getCentroid();
  for (int i = 2; i <= n; ++i) {
    h[p[i]].emplace_back(i);
    h[i].emplace_back(p[i]);
  }
  vector <bool> vis(n + 1, false);
  q.emplace(root), vis[root] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if ((clock() - st) / (1.0 * CLOCKS_PER_SEC) > 1.0) break;
    relax(u);
    for (int v : h[u]) if (!vis[v]) vis[v] = 1, q.emplace(v);
  }
  cout << ans << '\n';
  return 0;
}