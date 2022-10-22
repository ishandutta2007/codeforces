#include <bits/stdc++.h>
const int N = 1005;
char s[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int res = 10;
    for (int i = 0; i < 1 << 10; ++i) {
      int ra = 5, rb = 5, ca = 0, cb = 0;
      for (int j = 0; j < 10; ++j) {
        int c = s[j] == '?' ? (i >> j & 1) : s[j] - '0';
        if (j & 1) {
          ca += c;
          --ra;
        } else {
          cb += c;
          --rb;
        }
        if (ra + ca < cb || rb + cb < ca) {
          res = std::min(res, j + 1);
          break;
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}