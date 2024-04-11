#include <bits/stdc++.h>
using int64 = long long;
const int N = 1 << 15;
const int M = 1 << 22;
template <typename F, typename C, bool WithNegativeCost = false,
          int maxN = 1 << 15, int maxM = 1 << 22>
struct CostFlow {
  int source, sink, pre[maxN], cur[maxN], mcnt;
  C d[maxN], h[maxN];
  bool vis[maxN];
  struct arc {
    int x;
    F f;
    C c;
    int next;
  } e[maxM];
  void init() {
    memset(pre, -1, sizeof(pre));
    mcnt = 0;
  }
  void addarc(int x, int y, F z, C c) {
    e[mcnt] = (arc){y, z, c, pre[x]}, pre[x] = mcnt++;
    e[mcnt] = (arc){x, 0, -c, pre[y]}, pre[y] = mcnt++;
  }
  bool BellmanFord() {
    std::queue<int> q;
    memset(h, 0x3f, sizeof(h));
    h[sink] = 0;
    vis[sink] = 1;
    q.push(sink);
    bool found = false;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      vis[x] = false;
      found |= (x == source);
      for (int i = pre[x]; ~i; i = e[i].next) {
        int y = e[i].x;
        C z = e[i ^ 1].c;
        if (e[i ^ 1].f && h[y] > h[x] + z) {
          h[y] = h[x] + z;
          cur[y] = i ^ 1;
          if (!vis[y]) {
            q.push(y);
            vis[y] = true;
          }
        }
      }
    }
    return found;
  }
  bool Dijkstra() {
    std::priority_queue<std::pair<C, int>> pq;
    memset(d, 0x3f, sizeof(d));
    pq.push(std::make_pair(-(d[sink] = 0), sink));
    bool found = false;
    std::vector<int> que;
    while (!pq.empty()) {
      auto [w, x] = pq.top();
      pq.pop();
      if (-w > d[x]) {
        continue;
      }
      que.push_back(x);
      found |= (x == source);
      for (int i = pre[x]; ~i; i = e[i].next) {
        int y = e[i].x;
        C z = e[i ^ 1].c + h[x] - h[y];
        if (e[i ^ 1].f && d[x] + z < d[y]) {
          d[y] = d[x] + z;
          pq.push(std::make_pair(-d[y], y));
        }
      }
    }
    if (!found) {
      return false;
    }
    for (auto &x : que) {
      h[x] += d[x];
    }
    return true;
  }
  F augment(int x, F flow) {
    if (x == sink) {
      return flow;
    }
    vis[x] = 1;
    F sum = 0;
    for (int &i = cur[x]; ~i; i = e[i].next) {
      int y = e[i].x;
      if (e[i].f && !vis[y] && h[x] == e[i].c + h[y]) {
        F u = augment(y, std::min(flow, e[i].f));
        e[i].f -= u;
        e[i ^ 1].f += u;
        flow -= u;
        sum += u;
        if (!flow) {
          break;
        }
      }
    }
    vis[x] = 0;
    return sum;
  }
  std::pair<F, C> MincostMaxflow(F limit = std::numeric_limits<F>::max()) {
    memset(vis, 0, sizeof(vis));
    F maxflow = 0;
    C ans = 0;
    while (maxflow < limit && BellmanFord()) {
      int x = source;
      while (x != sink) {
        int i = cur[x];
        e[i].f--;
        e[i ^ 1].f++;
        ans += e[i].c;
        x = e[i].x;
      }
      ++maxflow;
    }
    return {maxflow, ans};
  }
};

CostFlow<int, int, false> G;
int n, K, a[1 << 20];

void work() {
  scanf("%d%d", &n, &K);
  K = std::min(K, (1 << n) / 2);
  int max_a = 0;
  for (int i = 0; i < 1 << n; ++i) {
    scanf("%d", &a[i]);
    max_a = std::max(max_a, a[i]);
  }
  std::vector<std::tuple<int, int, int>> v;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < 1 << n; ++i) {
      if (i >> j & 1) {
        int k = i ^ (1 << j);
        v.emplace_back(-(a[i] + a[k]), i, k);
      }
    }
    int num = std::min<size_t>(v.size(), 2 * n * K);
    std::nth_element(v.begin(), v.begin() + num, v.end());
    v.resize(num);
  }
  std::vector<int> id;
  for (auto &[w, x, y] : v) {
    id.emplace_back(x);
    id.emplace_back(y);
  }
  std::sort(id.begin(), id.end());
  id.erase(std::unique(id.begin(), id.end()), id.end());

  G.source = id.size();
  G.sink = id.size() + 1;
  G.init();
  for (int i = 0; i < id.size(); ++i) {
    int x = id[i];
    if (__builtin_parity(x)) {
      G.addarc(G.source, i, 1, max_a - a[x]);
    } else {
      G.addarc(i, G.sink, 1, max_a - a[x]);
    }
  }
  for (auto &[w, x, y] : v) {
    int i = std::lower_bound(id.begin(), id.end(), x) - id.begin();
    int j = std::lower_bound(id.begin(), id.end(), y) - id.begin();
    if (__builtin_parity(y)) {
      std::swap(i, j);
    }
    G.addarc(i, j, 1, 0);
  }
  printf("%d\n", 2 * K * max_a - G.MincostMaxflow(K).second);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}