#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  int min_x = *min_element(x.begin(), x.end());
  int max_x = *max_element(x.begin(), x.end());
  int min_y = *min_element(y.begin(), y.end());
  int max_y = *max_element(y.begin(), y.end());
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    answer = max(answer, x[i] - min_x + y[i] - min_y);
    answer = max(answer, x[i] - min_x + max_y - y[i]);
    answer = max(answer, max_x - x[i] + y[i] - min_y);
    answer = max(answer, max_x - x[i] + max_y - y[i]);
  }
  printf("%d", answer << 1);
  for (int i = 4; i <= n; ++i) {
    printf(" %d", max_x - min_x + max_y - min_y << 1);
  }
  putchar(10);
  return 0;
}