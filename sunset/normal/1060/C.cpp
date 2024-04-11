#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n + 1), b(m + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i + 1]);
    a[i + 1] += a[i];
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i + 1]);
    b[i + 1] += b[i];
  }
  int x;
  scanf("%d", &x);
  int answer = 0;
  vector<int> row(n + 1, x + 1), column(m + 1, x + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      row[i - j] = min(row[i - j], a[i] - a[j]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < i; ++j) {
      column[i - j] = min(column[i - j], b[i] - b[j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if ((long long)row[i] * column[j] <= x) {
        answer = max(answer, i * j);
      }
    }
  }
  printf("%d\n", answer);
  return 0;
}