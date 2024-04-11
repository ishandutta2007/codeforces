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

const int N = 1000005;

int n, m, q, lst[2][N], cnt[2][N];
char s[N], t[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  scanf("%s%s", s + 1, t + 1), n = strlen(s + 1), m = strlen(t + 1);
  for (int i = 1; i <= n; ++i) {
    cnt[0][i] = cnt[0][i - 1] + (s[i] != 'A');
    lst[0][i] = s[i] == 'A' ? lst[0][i - 1] : i;
  }
  for (int i = 1; i <= m; ++i) {
    cnt[1][i] = cnt[1][i - 1] + (t[i] != 'A');
    lst[1][i] = t[i] == 'A' ? lst[1][i - 1] : i;
  }
  for (Read(q); q; --q) {
    int a, b, c, d, l, r, L, R;
    Read(l), Read(r), Read(L), Read(R), --l, --L;
    a = r - max(l, lst[0][r]), b = R - max(L, lst[1][R]), c = cnt[0][r] - cnt[0][l], d = cnt[1][R] - cnt[1][L];
    if (a < b) {
      putchar('0');
    } else {
      if ((a - b) % 3) {
        c += 2;
      }
      if (c <= d && !(d - c & 1) && (a != b || c || !d)) {
        putchar('1');
      } else {
        putchar('0');
      }
    }
  }
  putchar(10);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}