#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<vector<int>> adj(n), son(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> order, f(n), g(n), answer(n + 1, -1);

  function<void(int, int)> dfs = [&](int x, int parent) {
    for (auto y : adj[x]) {
      if (y != parent) {
        son[x].push_back(y);
        dfs(y, x);
      }
    }
    order.push_back(x);
  };

  auto get = [&](int need) {
    if (~answer[need]) {
      return answer[need];
    }
    for (auto x : order) {
      f[x] = 0;
      int best = 0, another = 0;
      for (auto y : son[x]) {
        f[x] += f[y];
        another = max(another, g[y]);
        if (best < another) {
          swap(best, another);
        }
      }
      if (best + another + 1 >= need) {
        ++f[x];
        g[x] = 0;
      } else {
        g[x] = best + 1;
      }
    }
    return answer[need] = f[0];
  };

  function<void(int, int)> solve = [&](int l, int r) {
    if (get(l) == get(r)) {
      for (int i = l; i <= r; ++i) {
        answer[i] = answer[l];
      }
    } else {
      int mid = l + r >> 1;
      solve(l, mid);
      solve(mid + 1, r);
    }
  };

  dfs(0, -1);
  solve(1, n);
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", answer[i]);
  }
  return 0;
}