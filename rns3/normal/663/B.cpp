#include <bits/stdc++.h>

using namespace std;

#define N 100005

char s[N];

main() {
  int n;
  for (scanf("%d", &n); n --; ) {
    scanf("%s", s);
    __int64 rlt = 0, pw = 0;
    for (int i = 0; s[i]; i ++) {
      if ('0' <= s[i] && s[i] <= '9') rlt = rlt * 10 + s[i] - '0', pw ++;
    }
    if (pw == 1) {
      if (rlt == 9) puts("1989");
      else printf("199%I64d\n", rlt);
    } else if (pw == 2) {
      if (rlt == 99) puts("1999");
      else printf("%I64d\n", 2000 + rlt);
    } else if (pw == 3) {
      if (99 <= rlt) printf("%I64d\n", 2000 + rlt);
      else printf("%I64d\n", 3000 + rlt);
    } else if (pw == 4) {
      if (3099 <= rlt) printf("%I64d\n", rlt);
      else printf("%I64d\n", 10000 + rlt);
    } else if (pw == 5) {
      if (13099 <= rlt) printf("%I64d\n", rlt);
      else printf("%I64d\n", 100000 + rlt);
    } else if (pw == 6) {
      if (113099 <= rlt) printf("%I64d\n", rlt);
      else printf("%I64d\n", 1000000 + rlt);
    } else if (pw == 7) {
      if (1113099 <= rlt) printf("%I64d\n", rlt);
      else printf("%I64d\n", 10000000 + rlt);
    } else if (pw == 8) {
      if (11113099 <= rlt) printf("%I64d\n", rlt);
      else printf("%I64d\n", 100000000 + rlt);
    } else {
      if (111113099 <= rlt) printf("%I64d\n", rlt);
      else printf("%I64d\n", 1000000000 + rlt);
    }
  }
}