#include <bits/stdc++.h>

void work() {
  int n, m;
  scanf("%d%d", &n, &m);
  bool f0 = true, f1 = true;
  for (int i = 0; i < n; ++i) {
    static char str[105];
    scanf("%s", str);
    for (int j = 0; j < m; ++j) {
      if (str[j] != '.') {
        char c = (i + j) % 2 == 0 ? 'R' : 'W';
        if (str[j] != c) {
          f0 = false;
        }
        char d = (i + j) % 2 == 1 ? 'R' : 'W';
        if (str[j] != d) {
          f1 = false;
        }
      }
    }
  }
  if (!f0 && !f1) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (f0) {
          putchar((i + j) % 2 == 0 ? 'R' : 'W');
        } else {
          putchar((i + j) % 2 == 1 ? 'R' : 'W');
        }
      }
      puts("");
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}