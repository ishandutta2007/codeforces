#include <bits/stdc++.h>
using namespace std;

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1) {}
  int root(int v) const {
    while (p[v] != -1) v = p[v];
    return v;
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> x(n, vector<int>(n));
  vector<vector<int>> y(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> x[i][j] >> y[i][j];
      if (x[i][j] != -1) {
        --x[i][j], --y[i][j];
      }
    }
  }
  auto in = [&](int i, int j) {
    return 0 <= i and i < n and 0 <= j and j < n;
  };
  auto $ = [&](int i, int j) {
    return i * n + j;
  };
  dsu d(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + 1 < n and x[i][j] == x[i + 1][j] and y[i][j] == y[i + 1][j]) {
        d.unite($(i, j), $(i + 1, j));
      }
      if (j + 1 < n and x[i][j] == x[i][j + 1] and y[i][j] == y[i][j + 1]) {
        d.unite($(i, j), $(i, j + 1));
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (x[i][j] == -1) {
        if (d.size($(i, j)) == 1) {
          cout << "INVALID\n";
          exit(0);
        }
      } else {
        if (not d.same($(i, j), $(x[i][j], y[i][j]))) {
          cout << "INVALID\n";
          exit(0);
        }
      }
    }
  }
  cout << "VALID\n";
  vector<string> s(n, string(n, '?'));
  queue<pair<int, int>> que;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (x[i][j] == i and y[i][j] == j) {
        s[i][j] = 'X';
        que.emplace(i, j);
      }
    }
  }
  while (not que.empty()) {
    int i, j;
    tie(i, j) = que.front();
    que.pop();
    for (int di = -1; di <= 1; ++di) {
      for (int dj = -1; dj <= 1; ++dj) {
        if (abs(di) + abs(dj) != 1 or not in(i + di, j + dj)) {
          continue;
        }
        int ni = i + di, nj = j + dj;
        if (not d.same($(i, j), $(ni, nj)) or s[ni][nj] != '?') {
          continue;
        }
        if (di == 0) {
          s[ni][nj] = dj == 1 ? 'L' : 'R';
        } else {
          s[ni][nj] = di == 1 ? 'U' : 'D';
        }
        que.emplace(ni, nj);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '?') {
        [&] {
          for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
              if (abs(di) + abs(dj) != 1 or not in(i + di, j + dj)) {
                continue;
              }
              int ni = i + di, nj = j + dj;
              if (d.same($(i, j), $(ni, nj))) {
                if (di == 0) {
                  s[i][j] = dj == 1 ? 'R' : 'L';
                  s[ni][nj] = dj == 1 ? 'L' : 'R';
                } else {
                  s[i][j] = di == 1 ? 'D' : 'U';
                  s[ni][nj] = di == 1 ? 'U' : 'D';
                }
                que.emplace(i, j);
                return;
              }
            }
          }
        }();
        while (not que.empty()) {
          int i, j;
          tie(i, j) = que.front();
          que.pop();
          for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
              if (abs(di) + abs(dj) != 1 or not in(i + di, j + dj)) {
                continue;
              }
              int ni = i + di, nj = j + dj;
              if (not d.same($(i, j), $(ni, nj)) or s[ni][nj] != '?') {
                continue;
              }
              if (di == 0) {
                s[ni][nj] = dj == 1 ? 'L' : 'R';
              } else {
                s[ni][nj] = di == 1 ? 'U' : 'D';
              }
              que.emplace(ni, nj);
            }
          }
        }
      }
    }
  }
  for (auto e : s) {
    cout << e << '\n';
  }
}