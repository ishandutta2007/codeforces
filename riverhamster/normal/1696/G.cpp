#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <array>
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

const int N = 200005;
const int len = 1 << 18;

using V = array<ll, 3>;
using mat = array<V, 3>;

int n, qc, X, Y;
int b[N];

mat operator*(const mat &a, const mat &b) {
  mat c;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j)
      c[i][j] = max({a[i][0] + b[2][j], a[i][1] + b[1][j], a[i][2] + b[0][j]});
  }
  return c;
}

mat t[1 << 19];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, qc, X, Y);
  if (X > Y) swap(X, Y);
  X += Y;
  for (int i = 0; i < n; ++i) {
    int val;
    read(val);
    t[len + i] = {V{0, 0, 0}, V{0, (ll)Y * val, (ll)Y * val}, V{0, (ll)Y * val, (ll)X * val}};
  }
  for (int i = len - 1; i; --i)
    t[i] = t[i << 1] * t[i << 1 | 1];

  double den = (double)1 / X / Y;

  while (qc--) {
    int opt, x, y;
    read(opt, x, y);
    if (opt == 1) {
      x += len - 1;
      t[x] = {V{0, 0, 0}, V{0, (ll)Y * y, (ll)Y * y}, V{0, (ll)Y * y, (ll)X * y}};
      for (x >>= 1; x; x >>= 1)
        t[x] = t[x << 1] * t[x << 1 | 1];
    }
    else {
      V L = {0, 0, 0}, L1, R = {0, 0, 0}, R1;
      for (x += len - 1, y += len; x != y; x >>= 1, y >>= 1) {
        if (x & 1) {
          for (int i = 0; i < 3; ++i)
            L1[i] = max({L[0] + t[x][2][i], L[1] + t[x][1][i], L[2] + t[x][0][i]});
          L = L1;
          ++x;
        }
        if (y & 1) {
          --y;
          for (int i = 0; i < 3; ++i)
            R1[i] = max({t[y][i][0] + R[2], t[y][i][1] + R[1], t[y][i][2] + R[0]});
          R = R1;
        }
      }
      ll ans = max({L[0] + R[2], L[1] + R[1], L[2] + R[0]});
      printf("%.10lg\n", ans * den);
    }
  }
  return 0;
}