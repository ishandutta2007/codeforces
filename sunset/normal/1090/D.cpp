#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<set<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    if (x < y) {
      swap(x, y);
    }
    adj[x].insert(y);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (adj[i].find(j) == adj[i].end()) {
        vector<int> a(n), b(n);
        int ptr = 0;
        for (int k = 0; k < n; ++k) {
          if (k != i && k != j) {
            a[k] = b[k] = ptr++;
          }
        }
        a[i] = b[i] = b[j] = ptr++;
        a[j] = ptr++;
        puts("YES");
        for (int k = 0; k < n; ++k) {
          printf("%d%c", a[k] + 1, k == n - 1 ? '\n' : ' ');
        }
        for (int k = 0; k < n; ++k) {
          printf("%d%c", b[k] + 1, k == n - 1 ? '\n' : ' ');
        }
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}