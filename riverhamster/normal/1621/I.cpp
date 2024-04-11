#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;

int a[7][N];
int n;

void transform(const int *s, int *t) {
  static int slen[N], srep[N];
  static bool single[N];
  slen[0] = 1; srep[0] = 1;
  for (int i = 0; i < n; ) {
    slen[i] = 1; srep[i] = 1;
    int j = i, k = i + 1;
    for (; s[j] <= s[k]; ++k) {
      if (s[j] < s[k]) j = i;
      else ++j;
      int len = k - j + 1;
      div_t d = div(k - i + 1, len);
      if (d.rem == 0) {
        slen[k] = len;
        if (d.rem == 0) srep[k] = d.quot;
        else srep[k] = 1;
      }
      else {
        slen[k] = slen[k - len];
        srep[k] = srep[k - len];
      }
    }
    while (i <= j) i += k - j;
  }
  int *dst = t, *rb = t + n;
  if (slen[n - 1] == 1) single[n - 1] = true;
  for (int i = n - 2; i >= 0; --i) {
    if (slen[i] == 1 && srep[i] == 1) single[i] = true;
    else if (single[i + 1] && slen[i] == 1) single[i] = true;
    else single[i] = false;
  }
  for (int i = 0; i < n && dst != rb; ++i) {
    int cnt = (i == n - 1 || single[i + 1] ? 1 : srep[i]);
    for (int _t = 0; _t < cnt; ++_t)
      for (int j = i - slen[i] + 1; j <= i && dst != rb; ++j)
        *(dst++) = s[j];
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n);
  for (int i = 0; i < n; ++i)
    read(a[0][i]);
  for (int i = 0; i < 6; ++i)
    transform(a[i], a[i + 1]);
  int qc;
  read(qc);
  while (qc--) {
    int i, j;
    read(i, j);
    i = min(i, 6); --j;
    printf("%d\n", a[i][j]);
  }
  return 0;
}