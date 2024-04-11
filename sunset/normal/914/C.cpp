#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 1005;
const int mod = 1e9 + 7;

int n, m, ans, f[N], c[N][N];
char s[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  scanf("%s", s), n = strlen(s), Read(m);
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  for (int i = 2; i <= n; ++i) {
    f[i] = f[__builtin_popcount(i)] + 1;
  }
  if (!m) {
    puts("1");
  } else if (m == 1) {
    printf("%d\n", n - 1);
  } else {
    --m;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        for (int j = 0; j + cur <= n; ++j) {
          if (f[j + cur] == m) {
            ans = (ans + c[n - i - 1][j]) % mod;
          }
        }
        ++cur;
      }
    }
    if (f[cur] == m) {
      ans = (ans + 1) % mod;
    }
    printf("%d\n", ans);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}