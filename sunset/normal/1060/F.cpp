#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<vector<ld>> f(n, vector<ld> (n));
  vector<vector<ld>> binom(n + 1, vector<ld> (n + 1));
  vector<int> size(n);

  for (int i = 0; i <= n; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
  }

  function<void(int, int)> dfs = [&](int x, int parent) {
    size[x] = 0;
    f[x][0] = 1;
    for (auto y : adj[x]) {
      if (y != parent) {
        dfs(y, x);
        vector<ld> temp(size[y] + 1);
        for (int i = 0; i <= size[y]; ++i) {
          for (int j = 1; j <= size[y]; ++j) {
            if (j <= i) {
              temp[i] += f[y][min(i, j - 1)] / 2;
            } else {
              temp[i] += f[y][min(i, j - 1)];
            }
          }
        }
        vector<ld> result(size[x] + size[y] + 1);
        for (int i = 0; i <= size[x]; ++i) {
          for (int j = 0; j <= size[y]; ++j) {
            result[i + j] += f[x][i] * temp[j] * binom[i + j][i] * binom[size[x] + size[y] - i - j][size[x] - i];
          }
        }
        for (int i = 0; i <= size[x] + size[y]; ++i) {
          f[x][i] = result[i];
        }
        size[x] += size[y];
      }
    }
    ++size[x];
  };

  ld fact = 1;
  for (int i = 1; i < n; ++i) {
    fact *= i;
  }
  for (int i = 0; i < n; ++i) {
    dfs(i, -1);
    printf("%.9lf\n", (double)(f[i][n - 1] / fact));
  }
  return 0;
}