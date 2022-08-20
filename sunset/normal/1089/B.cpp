#include <bits/stdc++.h>

using namespace std;

class dsu_t {
 public:
  vector<int> p;
  int n;

  dsu_t(int n): n(n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  inline int find(int x) {
    while (x != p[x]) {
      x = p[x] = p[p[x]];
    }
    return x;
  }

  inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    } else {
      p[x] = y;
      return true;
    }
  }
};

pair<int, vector<int>> max_matching(int n, vector<vector<int>> adj) {
  vector<int> match(n, -1);
  int answer = 0;
  auto find_matching = [&](int start) {
    vector<int> color(n, -1);
    vector<int> prev(n, -1);
    vector<int> visit(n);
    queue<int> q;
    int tt = 0;
    dsu_t dsu(n);
    q.push(start);
    color[start] = 0;
    auto lca = [&](int x, int y) {
      ++tt;
      x = dsu.find(x);
      y = dsu.find(y);
      while (true) {
        if (~x) {
          if (visit[x] == tt) {
            return x;
          }
          visit[x] = tt;
          if (~match[x]) {
            x = dsu.find(prev[match[x]]);
          } else {
            x = -1;
          }
        }
        swap(x, y);
      }
    };
    auto blossom = [&](int x, int y, int z) {
      while (dsu.find(x) != z) {
        prev[x] = y;
        if (color[match[x]] == 1) {
          q.push(match[x]);
          color[match[x]] = 0;
        }
        if (dsu.find(x) == x) {
          dsu.unite(x, z);
        }
        if (dsu.find(match[x]) == match[x]) {
          dsu.unite(match[x], z);
        }
        y = match[x];
        x = prev[y];
      }
    };
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto y : adj[x]) {
        if (!~color[y]) {
          color[y] = 1;
          prev[y] = x;
          if (!~match[y]) {
            while (~x) {
              int last = match[x];
              match[x] = y;
              match[y] = x;
              if (~last) {
                y = last;
                x = prev[y];
              } else {
                break;
              }
            }
            return true;
          } else {
            q.push(match[y]);
            color[match[y]] = 0;
          }
        } else if (!color[y] && dsu.find(x) != dsu.find(y)) {
          int z = lca(x, y);
          blossom(x, y, z);
          blossom(y, x, z);
        }
      }
    }
    return false;
  };
  for (int i = 0; i < n; ++i) {
    if (!~match[i] && find_matching(i)) {
      ++answer;
    }
  }
  return make_pair(answer, match);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n * 2 + m);
    for (int i = 0; i < n; ++i) {
      adj[i].push_back(i + n);
      adj[i + n].push_back(i);
      string s;
      cin >> s;
      for (int j = 0; j < m; ++j) {
        if (s[j] == '1') {
          adj[i].push_back(j + n * 2);
          adj[j + n * 2].push_back(i);
          adj[i + n].push_back(j + n * 2);
          adj[j + n * 2].push_back(i + n);
        }
      }
    }
    printf("%d\n", max_matching(n * 2 + m, adj).first - n);
  }
  return 0;
}