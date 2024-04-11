#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

void work() {
  int n , m;
  scanf("%d%d" , &n, &m);
  static char str[N];
  scanf("%s" , str);
  int cnt[26] = {};
  for (int i = 0 ; i < n; ++ i) {
    cnt[str[i] - 'a'] ++;
  }
  for (int i = 0 ; i < m ; ++ i) {
    int x = n / m;
    for (int j = 0 ; j < n / m ; ++ j) {
      if (!cnt[j]) {
        printf("%c" , 'a' + j);
        break;
      } else {
        -- x;
        -- cnt[j];
      }
    }
    if (x == 0) {
      printf("%c", 'a' + n/ m);
    }
  }
  puts("");
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T --) {
    // static int ca = 0;
    // printf("Case #%d: ", ++ ca);
    work();
  }
  return 0;
}