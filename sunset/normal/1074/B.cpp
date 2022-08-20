#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
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
    vector<bool> a(n), b(n);
    int foo, bar, index = -1;
    scanf("%d", &foo);
    while (foo--) {
      int x;
      scanf("%d", &x);
      a[x - 1] = true;
    }
    scanf("%d", &bar);
    while (bar--) {
      int x;
      scanf("%d", &x);
      b[x - 1] = true;
    }
    for (int i = 0; i < n; ++i) {
      if (b[i]) {
        index = i;
      }
    }
    printf("B %d\n", index + 1);
    fflush(stdout);
    scanf("%d", &index);
    --index;
    int result = -1;
    function<void(int, int)> dfs = [&](int x, int parent) {
      if (a[x]) {
        result = x;
      } else {
        for (auto y : adj[x]) {
          if (y != parent) {
            dfs(y, x);
          }
        }
      }
    };
    dfs(index, -1);
    printf("A %d\n", result + 1);
    fflush(stdout);
    scanf("%d", &index);
    --index;
    printf("C %d\n", b[index] ? result + 1 : -1);
    fflush(stdout);
  }
  return 0;
}