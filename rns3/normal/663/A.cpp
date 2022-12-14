#include <bits/stdc++.h>

using namespace std;

#define N 100005

char s[N];

main() {
  gets(s);
  int len = strlen(s), cur = 1, n = 0, sub = 0, cnt = 0;
  for (int i = 0; i < len; i ++) {
    if (s[i] == '+') cur = 1;
    else if (s[i] == '-') cur = -1;
    else if (s[i] == '?') {
      if (cur > 0) cnt ++;
      else sub ++;
    } else if ('0' <= s[i] && s[i] <= '9') n = n * 10 + s[i] - '0';
  }

  if (!cnt) return puts("Impossible");
  int q = (n + sub) / cnt, r = (n + sub) % cnt;
  if (r && q + 1 > n) return puts("Impossible");
  else if (r == 0 && q > n) return puts("Impossible");
  else if (q) {
    puts("Possible");
    cnt = 0, cur = 1;
    for (int i = 0; i < len; i ++) {
      if (s[i] == '?') {
        if (cur > 0) {
          cnt ++;
          if (cnt <= r) printf("%d", q + 1);
          else printf("%d", q);
        } else putchar('1');
      } else if (s[i] == '+') cur = 1, putchar('+');
      else if (s[i] == '-') cur = -1, putchar('-');
      else putchar(s[i]);
    }
  } else {
    if (!sub) return puts("Impossible");
    else {
      int rem = cnt - n;
      int q = rem / sub, r = rem % sub;
      if (r && q + 1 > n) return puts("Impossible");
      else if (r == 0 && q > n) return puts("Impossible");
      sub = 0, cur = 1;
      puts("Possible");
      for (int i = 0; i < len; i ++) {
        if (s[i] == '?') {
          if (cur > 0) putchar('1');
          else {
            sub ++;
            if (sub <= r) printf("%d", q + 1);
            else printf("%d", q);
          }
        } else if (s[i] == '+') cur = 1, putchar('+');
        else if (s[i] == '-') cur = -1, putchar('-');
        else putchar(s[i]);
      }
    }
  }
}