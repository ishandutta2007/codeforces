#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

using ll = long long;

const int N = 200005;
vector<pair<int, int>> G[N];

int sz[N], fa[N], rk[N];
int res = 0;
int find(int x) { return !fa[x] ? x : fa[x] = find(fa[x]); }
void combine(int x, int y) {
  x = find(x), y = find(y);
  if (rk[x] < rk[y]) swap(x, y);
  fa[y] = x; rk[x] += rk[x] == rk[y]; sz[x] += sz[y];
  res = max(res, sz[x]);
}

ll d[N];

pair<ll, int> farthest(int x, int fa) {
  pair<ll, int> res = {0, x};
  for (auto [v, w] : G[x])
    if (v != fa) {
      auto ret = farthest(v, x);
      res = max(res, make_pair(ret.first + w, ret.second));
    }
  return res;
}
void push(int x, int fa, ll dis) {
  d[x] = max(d[x], dis);
  for (auto [v, w] : G[x])
    if (v != fa) push(v, x, dis + w);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].emplace_back(v, w); G[v].emplace_back(u, w);
  }
  int A = farthest(1, 1).second;
  int B = farthest(A, A).second;
  push(A, A, 0);
  push(B, B, 0);

  vector<int> nodes(n);
  iota(nodes.begin(), nodes.end(), 1);
  sort(nodes.begin(), nodes.end(), [&](int x, int y) {
    return d[x] > d[y];
  });

  int q;
  scanf("%d", &q);
  while (q--) {
    ll lim;
    scanf("%lld", &lim);
    fill(fa + 1, fa + 1 + n, 0);
    fill(rk + 1, rk + 1 + n, 0);
    fill(sz + 1, sz + 1 + n, 0);
    auto lt = nodes.begin();
    res = 1;
    for (int x : nodes) {
      sz[x] = 1;
      while (lt != nodes.end() && d[*lt] - d[x] > lim) {
        --sz[find(*lt)];
        ++lt;
      }
      for (auto [v, w] : G[x])
        if (sz[v] != 0) combine(x, v);
    }
    printf("%d\n", res);
  }
  return 0;
}