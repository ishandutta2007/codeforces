#include <bits/stdc++.h>

using namespace std;

using cap_t = int;

const cap_t cap_inf = 0x3f3f3f3f;

namespace flow {
struct edge {
  int to, rev;
  cap_t cap;

  edge(int t, cap_t c, int r) {
    to = t;
    cap = c;
    rev = r;
  }
};

vector<vector<edge>> adj;
vector<int> cur, dist;
int n, source, sink;
cap_t ans;

void init(int v, int s, int t) {
  n = v;
  ans = 0;
  source = s;
  sink = t;
  adj.clear();
  adj.resize(n);
  cur.resize(n);
  dist.resize(n);
}

void add(int x, int y, cap_t c) {
  adj[x].emplace_back(y, c, adj[y].size());
  adj[y].emplace_back(x, 0, adj[x].size() - 1);
}

bool bfs() {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    dist[i] = -1;
  }
  dist[source] = 0;
  q.push(source);
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

cap_t dfs(int x, cap_t f) {
  if (x == sink) {
    return f;
  }
  for (int &i = cur[x]; ~i; --i) {
    edge &e = adj[x][i];
    if (e.cap && dist[e.to] == dist[x] + 1) {
      cap_t w = dfs(e.to, min(e.cap, f));
      if (w) {
        e.cap -= w;
        adj[e.to][e.rev].cap += w;
        return w;
      }
    }
  }
  return 0;
}

cap_t max_flow() {
  while (bfs()) {
    for (int i = 0; i < n; ++i) {
      cur[i] = adj[i].size() - 1;
    }
    while (true) {
      cap_t flow = dfs(source, cap_inf);
      if (!flow) {
        break;
      }
      ans += flow;
    }
  }
  return ans;
}
}

using flow::source;
using flow::sink;
using flow::init;
using flow::add;
using flow::max_flow;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, h, m;
  cin >> n >> h >> m;
  init(n * h + m + 2, n * h + m, n * h + m + 1);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int last = source;
    ans += h * h;
    for (int j = 0; j < h; ++j) {
      add(last, i * h + j, h * h - j * j);
      last = i * h + j;
    }
  }
  for (int i = 0; i < m; ++i) {
    int l, r, x, c;
    cin >> l >> r >> x >> c;
    --l;
    --r;
    if (x == h) {
      continue;
    }
    for (int j = l; j <= r; ++j) {
      add(j * h + x, n * h + i, cap_inf);
    }
    add(n * h + i, sink, c);
  }
  cout << ans - max_flow() << "\n";
  return 0;
}