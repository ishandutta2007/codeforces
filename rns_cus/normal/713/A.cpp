#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int cnt[1111111];

char type[10];
int a[20];

int convert(LL x) {
  for (int i = 0; i < 18; i++) {
    a[i] = x % 10; a[i] %= 2;
    x /= 10;
  }
  int rlt = 0;
  for (int i = 17; i >= 0; i--) {
    rlt = 2 * rlt + a[i];
  }
  return rlt;
}

char s[20];

int main() {
  //freopen("in.txt", "r", stdin);
  int Q;
  scanf("%d", &Q);
  LL x;
  while (Q--) {
    scanf("%s", type);
    if (type[0] == '+') {
      scanf("%I64d", &x);
      int t = convert(x);
      cnt[t]++;
    }
    else if (type[0] == '-') {
      scanf("%I64d", &x);
      int t = convert(x);
      cnt[t]--;
    }
    else {
      scanf("%s", s);
      int m = strlen(s);
      reverse(s, s + m);
      for (int i = m; i < 18; i++) s[i] = '0';
      int t = 0;
      for (int i = 17; i >= 0; i--) t = 2 * t + s[i] - '0';
      printf("%d\n", cnt[t]);
      fflush(stdout);
    }
  }
}