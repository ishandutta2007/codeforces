#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, s;
  scanf("%d %d", &n, &s);
  vector<int> degree(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    ++degree[x - 1];
    ++degree[y - 1];
  }
  int leaf = 0;
  for (int i = 0; i < n; ++i) {
    if (degree[i] == 1) {
      ++leaf;
    }
  }
  printf("%.10lf\n", (double)s * 2 / leaf);
  return 0;
}