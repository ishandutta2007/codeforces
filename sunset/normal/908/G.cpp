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

const int N = 705;
const int mod = 1e9 + 7;

int n, ans, f[N][N][2];
char s[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  scanf("%s", s), n = strlen(s);
  for (int d = 1; d < 10; ++d) {
    memset(f, 0, sizeof f);
    f[0][0][1] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        for (int k = 0; k < 2; ++k) {
          for (int l = 0; l <= (k ? s[i] - '0' : 9); ++l) {
            (f[i + 1][j + (l >= d)][k && l == s[i] - '0'] += f[i][j][k]) %= mod;
          }
        }
      }
    }
    for (int i = 1, j = 1; i <= n; ++i, j = (10LL * j + 1) % mod) {
      ans = (1LL * (f[n][i][0] + f[n][i][1]) * j + ans) % mod;
    }
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}