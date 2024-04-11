#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector ch(n, vector(26, -1));
  for (int i = 0; i < n - 1; ++i) {
    int v, to;
    char c;
    cin >> v >> to >> c;
    --v, --to;
    ch[v][c - 'a'] = to;
  }
  vector<int> dep(n), sz(n);
  auto dfs = [&](auto&& self, int v) -> void {
    sz[v] = 1;
    for (int i = 0; i < 26; ++i) {
      int to = ch[v][i];
      if (to == -1) continue;
      dep[to] = dep[v] + 1;
      self(self, to);
      sz[v] += sz[to];
    }
  };
  dfs(dfs, 0);
  vector<pair<int, int>> mem;
  auto f = [&](auto&& self, int x, int y) -> int {
    int res = 1;
    for (int i = 0; i < 26; ++i) {
      if (ch[x][i] == -1) continue;
      if (ch[y][i] == -1) {
        ch[y][i] = ch[x][i];
        mem.emplace_back(y, i);
        continue;
      }
      res += self(self, ch[x][i], ch[y][i]);
    }
    return res;
  };
  vector<int> a(n);
  for (int v = 0; v < n; ++v) {
    int mi = -1;
    for (int i = 0; i < 26; ++i) {
      if (ch[v][i] == -1) continue;
      if (mi == -1 or sz[ch[v][i]] > sz[ch[v][mi]]) {
        mi = i;
      }
    }
    if (mi == -1) continue;
    ++a[dep[v]];
    for (int i = 0; i < 26; ++i) {
      if (ch[v][i] == -1 or i == mi) continue;
      a[dep[v]] += f(f, ch[v][i], ch[v][mi]);
    }
    while (not empty(mem)) {
      auto [y, i] = mem.back();
      ch[y][i] = -1;
      mem.pop_back();
    }
  }
  int p = max_element(begin(a), end(a)) - begin(a);
  cout << n - a[p] << '\n';
  cout << p + 1 << '\n';
}