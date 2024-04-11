#include <bits/stdc++.h>

constexpr int max_N = 100000 + 21;

int n, m, k, deg[max_N], vis[max_N], vis_cnt;

std::vector<int> vec[max_N], clique[max_N];

std::vector<int> check[max_N];

int clique_cnt;

bool valid[max_N], clique_check[max_N];

void solve() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    valid[i] = true;
    deg[i] = 0;
    vis[i] = 0;
    vec[i].clear();
    check[i].clear();
  }
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  if (1LL * k * (k - 1) > 2 * m) {
    puts("-1");
    return;
  }
  std::priority_queue<std::pair<int, int>> pq;
  for (int i = 1; i <= n; ++i) {
    deg[i] = vec[i].size();
    pq.emplace(-deg[i], i);
  }
  clique_cnt = 0;
  vis_cnt = 0;
  while (!pq.empty()) {
    auto item = pq.top();
    pq.pop();
    int u = item.second;
    if (!valid[u] || item.first + deg[u] != 0) {
      continue;
    }
    if (deg[u] >= k) {
      std::vector<int> ans;
      for (int i = 1; i <= n; ++i) {
        if (valid[i]) {
          ans.push_back(i);
        }
      }
      int size = static_cast<int>(ans.size());
      printf("1 %d\n", size);
      for (int i = 1; i <= size; ++i) {
        printf("%d%c", ans[i - 1], " \n"[i == size]);
      }
      return;
    }
    if (deg[u] == k - 1) {
      ++clique_cnt;
      clique_check[clique_cnt] = true;
      clique[clique_cnt].clear();
      clique[clique_cnt].reserve(k);
      clique[clique_cnt].push_back(u);
      for (auto v : vec[u]) {
        if (valid[v]) {
          clique[clique_cnt].push_back(v);
        }
      }
      for (auto v : clique[clique_cnt]) {
        check[v].push_back(clique_cnt);
      }
    }
    valid[u] = false;
    ++vis_cnt;
    for (auto v : vec[u]) {
      if (valid[v]) {
        --deg[v];
        pq.emplace(-deg[v], v);
        vis[v] = vis_cnt;
      }
    }
    for (auto idx : check[u]) {
      for (auto v : clique[idx]) {
        if (valid[v] && vis[v] != vis_cnt) {
          clique_check[idx] = false;
        }
      }
    }
  }
  for (int i = 1; i <= clique_cnt; ++i) {
    if (clique_check[i]) {
      puts("2");
      for (int j = 0; j < clique[i].size(); ++j) {
        printf("%d%c", clique[i][j], " \n"[j + 1 == clique[i].size()]);
      }
      return;
    }
  }
  puts("-1");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}