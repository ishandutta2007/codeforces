#include <bits/stdc++.h>

using namespace std;

bool query(int a, int b, int c, int d, int n) {
  if (a < 1 || b < 1 || c > n || d > n) {
    return false;
  }
  printf("? %d %d %d %d\n", a, b, c, d);
  fflush(stdout);
  char result[10];
  scanf("%s", result);
  return result[0] == 'Y';
}

int main() {
  int n;
  scanf("%d", &n);
  int x, y, index;
  vector<pair<int, int>> answer((n << 1) - 1);
  index = 0;
  answer[index++] = make_pair(1, 1);
  x = y = 1;
  while (x + y < n + 1) {
    if (query(x + 1, y, n, n, n)) {
      answer[index++] = make_pair(++x, y);
    } else {
      answer[index++] = make_pair(x, ++y);
    }
  }
  index = n - 1 << 1;
  answer[index--] = make_pair(n, n);
  x = y = n;
  while (x + y > n + 1) {
    if (query(1, 1, x, y - 1, n)) {
      answer[index--] = make_pair(x, --y);
    } else {
      answer[index--] = make_pair(--x, y);
    }
  }
  printf("! ");
  for (int i = 1; i < answer.size(); ++i) {
    if (answer[i].first == answer[i - 1].first) {
      putchar('R');
    } else {
      putchar('D');
    }
  }
  putchar(10);
  fflush(stdout);
  return 0;
}