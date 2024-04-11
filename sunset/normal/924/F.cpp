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

const int N = 165;
const int M = 100005;

unordered_map <bitset <N>, int> f;
int tot, nxt[M][10];
LL s[10][20][M];
bitset <N> q[M];
bool g[M][10];

inline int Extend(bitset <N> &b) {
  if (f.find(b) == f.end()) {
    q[f[b] = ++tot] = b;
  }
  return f[b];
}

int Init() {
  bitset <N> cur;
  cur[0] = true, Extend(cur);
  for (int i = 1; i <= tot; ++i) {
    bitset <N> b = q[i];
    for (int j = 0; j < 10; ++j) {
      bitset <N> c = b >> j | b << j;
      for (int k = 0; k < j; ++k) {
        if (b[k]) {
          c[j - k] = true;
        }
      }
      nxt[i][j] = Extend(c);
    }
  }
  g[1][0] = true;
  for (int i = 1; i <= tot; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (g[i][j]) {
        for (int k = 0; k < 10; ++k) {
          g[nxt[i][k]][abs(j - k)] = true;
        }
      }
    }
  }
  for (int i = 1; i <= tot; ++i) {
    for (int j = 1; j < 10; ++j) {
      g[i][j] |= g[i][j - 1];
    }
    for (int j = 0; j < 10; ++j) {
      s[j][0][i] = g[i][j];
    }
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 1; j < 20; ++j) {
      for (int k = 1; k <= tot; ++k) {
        for (int l = 0; l < 10; ++l) {
          s[i][j][k] += s[i][j - 1][nxt[k][l]];
        }
      }
    }
  }
}

inline LL Solve(LL x, int k) {
  int top = 0, dig[20];
  LL ans = 0;
  for (; x; dig[++top] = x % 10, x /= 10);
  for (int i = top, cur = 1; i; --i) {
    for (int j = 0; j < dig[i]; ++j) {
      ans += s[k][i - 1][nxt[cur][j]];
    }
    cur = nxt[cur][dig[i]];
  }
  return ans;
}

int Main() {
  LL l, r;
  int k;
  Read(l), Read(r), Read(k);
  printf("%lld\n", Solve(r + 1, k) - Solve(l, k));
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Init();
  int T;
  for (Read(T); T; --T) {
    Main();
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}