#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

long long a[N], sum[N], minsuf[N];
char type[N];
int n;

inline int get(char c) {
  return c == 'L' ? 2 : c == 'G';
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  scanf("%s", type + 1);
  int pref = 0;
  type[0] = 'L';
  for (int i = 1; i <= n; ++i) {
    if (type[i] == 'L') {
      sum[i] = sum[i - 1] - a[i];
      if (sum[i] < 0) {
        a[pref] -= sum[i];
        sum[i] = 0;
      }
    } else {
      sum[i] = sum[i - 1] + a[i];
    }
    if (get(type[i]) < get(type[pref])) {
      pref = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (type[i] == 'L') {
      sum[i] = sum[i - 1] - a[i];
    } else {
      sum[i] = sum[i - 1] + a[i];
    }
  }
  long long answer = 0;
  for (int i = 1; i <= n; ++i) {
    if (type[i] == 'L') {
      answer += a[i];
    } else if (type[i] == 'W') {
      answer += 3 * a[i];
    } else {
      answer += 5 * a[i];
    }
  }
  minsuf[n + 1] = LLONG_MAX;
  for (int i = n; i; --i) {
    minsuf[i] = min(minsuf[i + 1], sum[i]);
  }
  long long current = 0;
  for (int i = 1; i <= n; ++i) {
    if (type[i] == 'G') {
      long long used = min(minsuf[i] - current, a[i] * 2);
      a[i] -= used;
      current += used;
      answer -= used * 2;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (type[i] == 'L') {
      sum[i] = sum[i - 1] - a[i];
    } else {
      sum[i] = sum[i - 1] + a[i];
    }
  }
  minsuf[n + 1] = LLONG_MAX;
  for (int i = n; i; --i) {
    minsuf[i] = min(minsuf[i + 1], sum[i]);
  }
  current = 0;
  for (int i = 1; i <= n; ++i) {
    if (type[i] == 'W') {
      long long used = min(minsuf[i] - current, a[i] * 2);
      a[i] -= used;
      current += used;
      answer -= used;
    }
  }
  printf("%lld\n", answer);
  return 0;
}