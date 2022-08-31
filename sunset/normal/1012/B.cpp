#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

int n, m, q, answer, f[N];

int find(int x) {
  while (x != f[x]) {
    x = f[x] = f[f[x]];
  }
  return x;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n + m; ++i) {
    f[i] = i;
  }
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    f[find(x)] = find(y + n);
  }
  for (int i = 1; i <= n + m; ++i) {
    if (find(i) == i) {
      ++answer;
    }
  }
  printf("%d\n", answer - 1);
  return 0;
}