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

vector<vector<edge>> g;
vector<int> ptr, dist;
int n, src, snk;
cap_t ans;

void init(int v, int s, int t) {
  n = v;
  ans = 0;
  src = s;
  snk = t;
  g.clear();
  g.resize(n);
  ptr.resize(n);
  dist.resize(n);
}

void add(int v, int u, cap_t c, cap_t rev_c = 0) {
  g[v].emplace_back(u, c, g[u].size());
  g[u].emplace_back(v, rev_c, g[v].size() - 1);
}

bool bfs() {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    dist[i] = -1;
  }
  dist[src] = 0;
  q.push(src);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (edge e : g[v]) {
      if (e.cap && !~dist[e.to]) {
        dist[e.to] = dist[v] + 1;
        q.push(e.to);
        if (e.to == snk) {
          return true;
        }
      }
    }
  }
  return false;
}

cap_t dfs(int v, cap_t f) {
  if (v == snk) {
    return f;
  }
  for (int& i = ptr[v]; ~i; --i) {
    edge& e = g[v][i];
    if (e.cap && dist[e.to] == dist[v] + 1) {
      cap_t w = dfs(e.to, min(e.cap, f));
      if (w) {
        e.cap -= w;
        g[e.to][e.rev].cap += w;
        return w;
      }
    }
  }
  return 0;
}

cap_t max_flow() {
  while (bfs()) {
    for (int i = 0; i < n; ++i) {
      ptr[i] = g[i].size() - 1;
    }
    while (true) {
      cap_t flow = dfs(src, cap_inf);
      if (!flow) {
        break;
      }
      ans += flow;
    }
  }
  return ans;
}

vector<bool> min_cut() {
  max_flow();
  vector<bool> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = !~dist[i];
  }
  return res;
}
}

using flow::src;
using flow::snk;
using flow::add;
using flow::init;
using flow::min_cut;
using flow::max_flow;

int count_digits(int n) {
  int res = 0;
  while (n) {
    n /= 10;
    ++res;
  }
  return res;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int m = count_digits(n);
  if (m == 1) {
    for (int i = 2; i <= n; ++i) {
      cout << 1 << " " << i << "\n";
    }
    return 0;
  }
  vector<vector<int>> ed(m, vector<int>(m));
  for (int i = 0; i < n - 1; ++i) {
    string s, t;
    cin >> s >> t;
    ++ed[min(s.size(), t.size()) - 1][max(s.size(), t.size()) - 1];
  }
  vector<int> power(m);
  power[0] = 1;
  for (int i = 1; i < m; ++i) {
    power[i] = power[i - 1] * 10;
  }
  vector<int> cnt(m);
  for (int i = 0; i < m - 1; ++i) {
    cnt[i] = power[i + 1] - power[i];
  }
  cnt[m - 1] = n - power[m - 1] + 1;
  vector<int> prufer(m - 2);
  auto check = [&]() {
    vector<pair<int, int>> edges;
    vector<int> deg(m, 1);
    for (int v : prufer) {
      ++deg[v];
    }
    for (int v : prufer) {
      int u = -1;
      for (int i = 0; i < m; ++i) {
        if (deg[i] == 1) {
          u = i;
          break;
        }
      }
      --deg[v]; --deg[u];
      edges.emplace_back(min(v, u), max(v, u));
    }
    {
      int v = -1, u = -1;
      for (int i = 0; i < m; ++i) {
        if (deg[i] == 1) {
          if (v == -1) {
            v = i;
          } else {
            u = i;
          }
        }
      }
      --deg[v]; --deg[u];
      edges.emplace_back(min(v, u), max(v, u));
    }
    for (auto e : edges) {
      --ed[e.first][e.second];
    }
    bool valid = true;
    for (int i = 0; i < m; ++i) {
      for (int j = i; j < m; ++j) {
        if (ed[i][j] < 0) {
          valid = false;
          break;
        }
      }
    }
    if (valid) {
      init(m * (m + 3) / 2 + 2, m * (m + 3) / 2, m * (m + 3) / 2 + 1);
      int who = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
          add(src, who, ed[i][j]);
          add(who, m * (m + 1) / 2 + i, n);
          add(who, m * (m + 1) / 2 + j, n);
          ++who;
        }
      }
      for (int i = 0; i < m; ++i) {
        add(m * (m + 1) / 2 + i, snk, cnt[i] - 1);
      }
      if (max_flow() == n - m) {
        for (auto e : edges) {
          cout << power[e.first] << " " << power[e.second] << "\n";
        }
        vector<int> ptr(m);
        for (int i = 0; i < m; ++i) {
          ptr[i] = power[i] + 1;
        }
        int who = 0;
        for (int i = 0; i < m; ++i) {
          for (int j = i; j < m; ++j) {
            for (auto e : flow::g[who]) {
              if (e.to != src) {
                int cnt = n - e.cap;
                int small = e.to - m * (m + 1) / 2;
                int large = i + j - small;
                while (cnt--) {
                  cout << power[large] << " " << ptr[small]++ << "\n";
                }
              }
            }
            ++who;
          }
        }
        exit(0);
      }
    }
    for (auto e : edges) {
      ++ed[e.first][e.second];
    }
  };
  function<void(int)> dfs = [&](int who) {
    if (who == m - 2) {
      check();
    } else {
      for (prufer[who] = 0; prufer[who] < m; ++prufer[who]) {
        dfs(who + 1);
      }
    }
  };
  dfs(0);
  cout << -1 << "\n";
  return 0;
}