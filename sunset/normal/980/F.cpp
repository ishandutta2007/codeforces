#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, m, cycle, f[N], g[N], h[N], up[N], down[N], depth[N], belong[N], parent[N];
vector<int> adj[N], tree[N];

void dfs(int x) {
  for (int i = 0; i < adj[x].size(); ++i) {
    int y = adj[x][i];
    if (!depth[y]) {
      depth[y] = depth[x] + 1;
      parent[y] = x;
      tree[x].push_back(y);
      dfs(y);
    }
  }
}

void push_up(int x) {
  for (int i = 0; i < tree[x].size(); ++i) {
    int y = tree[x][i];
    push_up(y);
    if (!belong[x] || belong[x] != belong[y]) {
      f[x] = max(f[x], max(f[y], g[y]) + 1);
    }
  }
  if (belong[x]) {
    g[up[belong[x]]] = max(g[up[belong[x]]], f[x] + min(depth[x] - depth[up[belong[x]]], depth[down[belong[x]]] - depth[x] + 1));
  }
}

void make_cycle(int id) {
  vector<int> nodes;
  for (int i = down[id]; depth[i] >= depth[up[id]]; i = parent[i]) {
    nodes.push_back(i);
  }
  int length = nodes.size();
  for (int i = 0; i < length; ++i) {
    nodes.push_back(nodes[i]);
  }
  deque<int> q;
  for (int i = 0; i < length << 1; ++i) {
    while (!q.empty() && i - q.front() > length >> 1) {
      q.pop_front();
    }
    if (!q.empty()) {
      h[nodes[i]] = max(h[nodes[i]], f[nodes[q.front()]] + i - q.front());
    }
    while (!q.empty() && f[nodes[q.back()]] - q.back() <= f[nodes[i]] - i) {
      q.pop_back();
    }
    q.push_back(i);
  }
  while (!q.empty()) {
    q.pop_back();
  }
  for (int i = (length << 1) - 1; ~i; --i) {
    while (!q.empty() && q.front() - i > length >> 1) {
      q.pop_front();
    }
    if (!q.empty()) {
      h[nodes[i]] = max(h[nodes[i]], f[nodes[q.front()]] + q.front() - i);
    }
    while (!q.empty() && f[nodes[q.back()]] + q.back() <= f[nodes[i]] + i) {
      q.pop_back();
    }
    q.push_back(i);
  }
}

void push_down(int x) {
  if (belong[x] && x == up[belong[x]]) {
    f[x] = max(f[x], h[x]);
    make_cycle(belong[x]);
  }
  vector<int> value, prefix, suffix;
  for (int i = 0; i < tree[x].size(); ++i) {
    int y = tree[x][i];
    if (belong[x] && belong[x] == belong[y]) {
      value.push_back(h[x]);
    } else {
      value.push_back(max(f[y], g[y]) + 1);
    }
  }
  prefix = suffix = value;
  for (int i = 1; i < prefix.size(); ++i) {
    prefix[i] = max(prefix[i], prefix[i - 1]);
  }
  for (int i = suffix.size() - 2; i >= 0; --i) {
    suffix[i] = max(suffix[i], suffix[i + 1]);
  }
  for (int i = 0; i < tree[x].size(); ++i) {
    int y = tree[x][i];
    if (belong[x] && belong[x] == belong[y]) {
      push_down(y);
    } else {
      int value = h[x];
      if (i) {
        value = max(value, prefix[i - 1]);
      }
      if (i < tree[x].size() - 1) {
        value = max(value, suffix[i + 1]);
      }
      h[y] = value + 1;
      push_down(y);
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  depth[1] = 1;
  dfs(1);
  for (int x = 1; x <= n; ++x) {
    for (int i = 0; i < adj[x].size(); ++i) {
      int y = adj[x][i];
      if (depth[y] > depth[x] + 1) {
        ++cycle;
        up[cycle] = x;
        down[cycle] = y;
        while (depth[y] >= depth[x]) {
          belong[y] = cycle;
          y = parent[y];
        }
      }
    }
  }
  push_up(1);
  push_down(1);
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", max(f[i], h[i]), i == n ? '\n' : ' ');
  }
  return 0;
}