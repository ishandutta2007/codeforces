#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  map<int, int> f;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++f[x];
  }
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 1) {
      if (y != 1e9) {
        --f[y];
      }
      ++sum;
    }
  }
  int answer = sum;
  for (auto p : f) {
    sum += p.second;
    answer = min(answer, sum);
  }
  printf("%d\n", answer);
  return 0;
}