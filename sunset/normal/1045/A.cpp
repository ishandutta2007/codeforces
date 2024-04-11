#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

namespace flow {
struct edge_t {
  int to, cap, rev;

  edge_t(int t, int c, int r) {
    to = t;
    cap = c;
    rev = r;
  }
};

int n, source, sink, answer;
vector<vector<edge_t>> adj;
vector<int> dist, current;

void init(int v, int s, int t) {
  n = v;
  source = s;
  sink = t;
  answer = 0;
  adj.clear();
  adj.resize(n);
  dist.resize(n);
  current.resize(n);
}

void add(int x, int y, int c) {
  adj[x].emplace_back(y, c, adj[y].size());
  adj[y].emplace_back(x, 0, adj[x].size() - 1);
}

bool bfs() {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    dist[i] = -1;
  }
  dist[source] = 0, q.push(source);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto e : adj[x]) {
      if (e.cap && !~dist[e.to]) {
        dist[e.to] = dist[x] + 1;
        if (e.to == sink) {
          return true;
        }
        q.push(e.to);
      }
    }
  }
  return false;
}

int dfs(int x, int f) {
  if (x == sink) {
    return f;
  }
  for (int &i = current[x]; ~i; --i) {
    edge_t &e = adj[x][i];
    if (e.cap && dist[e.to] == dist[x] + 1) {
      int w = dfs(e.to, min(e.cap, f));
      if (w) {
        e.cap -= w;
        adj[e.to][e.rev].cap += w;
        return w;
      }
    }
  }
  return 0;
}

int max_flow() {
  while (bfs()) {
    for (int i = 0; i < n; ++i) {
      current[i] = adj[i].size() - 1;
    }
    while (true) {
      int flow = dfs(source, inf);
      if (!flow) {
        break;
      }
      answer += flow;
    }
  }
  return answer;
}
}

using flow::source;
using flow::sink;
using flow::init;
using flow::add;
using flow::max_flow;
using flow::adj;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  init((m << 1) - 1 + n + 2, (m << 1) - 1 + n, (m << 1) - 1 + n + 1);
  vector<int> id(m);
  vector<int> related((m << 1) - 1);

  function<void(int, int, int)> build = [&](int x, int l, int r) {
    if (l == r) {
      id[l] = x;
      related[x] = l;
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      build(x + 1, l, y);
      build(z, y + 1, r);
      add(x, x + 1, inf);
      add(x, z, inf);
    }
  };

  function<void(int, int, int, int, int, int)> query = [&](int x, int l, int r, int ql, int qr, int from) {
    if (l == ql && r == qr) {
      add(from, x, 1);
    } else {
      int y = l + r >> 1, z = x + (y - l + 1 << 1);
      if (qr <= y) {
        query(x + 1, l, y, ql, qr, from);
      } else if (ql > y) {
        query(z, y + 1, r, ql, qr, from);
      } else {
        query(x + 1, l, y, ql, y, from);
        query(z, y + 1, r, y + 1, qr, from);
      }
    }
  };

  build(0, 0, m - 1);
  for (int i = 0; i < m; ++i) {
    add(id[i], sink, 1);
  }
  vector<int> type(n), a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &type[i]);
    if (!type[i]) {
      add(source, i + (m << 1) - 1, 1);
      int size;
      scanf("%d", &size);
      while (size--) {
        int x;
        scanf("%d", &x);
        --x;
        add(i + (m << 1) - 1, id[x], 1);
      }
    } else if (type[i] == 1) {
      scanf("%d %d", &a[i], &b[i]);
      --a[i];
      --b[i];
      add(source, i + (m << 1) - 1, 1);
      query(0, 0, m - 1, a[i], b[i], i + (m << 1) - 1);
    } else {
      scanf("%d %d %d", &a[i], &b[i], &c[i]);
      --a[i];
      --b[i];
      --c[i];
      add(source, i + (m << 1) - 1, 2);
      add(i + (m << 1) - 1, id[a[i]], 1);
      add(i + (m << 1) - 1, id[b[i]], 1);
      add(i + (m << 1) - 1, id[c[i]], 1);
    }
  }
  printf("%d\n", max_flow());
  vector<bool> use(m);
  for (int i = 0; i < m; ++i) {
    for (auto e : adj[id[i]]) {
      if (e.to == sink && !e.cap) {
        use[i] = true;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (type[i] == 2) {
      bool found = false;
      for (auto e : adj[i + (m << 1) - 1]) {
        if (e.to == source && e.cap) {
          found = true;
          break;
        }
      }
      if (found) {
        int remain = 2;
        for (auto e : adj[i + (m << 1) - 1]) {
          if (e.to != source && !e.cap) {
            printf("%d %d\n", i + 1, related[e.to] + 1);
            --remain;
            use[related[e.to]] = false;
          }
        }
        if (remain && use[a[i]]) {
          printf("%d %d\n", i + 1, a[i] + 1);
          --remain;
          use[a[i]] = false;
        }
        if (remain && use[b[i]]) {
          printf("%d %d\n", i + 1, b[i] + 1);
          --remain;
          use[b[i]] = false;
        }
        if (remain && use[c[i]]) {
          printf("%d %d\n", i + 1, c[i] + 1);
          --remain;
          use[c[i]] = false;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!type[i]) {
      for (auto e : adj[i + (m << 1) - 1]) {
        if (e.to != source && !e.cap && use[related[e.to]]) {
          printf("%d %d\n", i + 1, related[e.to] + 1);
          use[related[e.to]] = false;
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (use[i]) {
      int p = -1;
      for (int j = 0; j < n; ++j) {
        if (type[j] == 1 && a[j] <= i && b[j] >= i && (!~p || b[j] < b[p])) {
          p = j;
        }
      }
      type[p] = -1;
      printf("%d %d\n", p + 1, i + 1);
    }
  }
  return 0;
}