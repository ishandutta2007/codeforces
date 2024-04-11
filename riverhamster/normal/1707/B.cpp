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
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;

int a[N];

void single() {
  int n;
  read(n);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  a[n + 1] = 0;
  int lb = 1;
  for (int i = n; i > 1; --i) {
    lb = max(lb, 1);
    for (int j = lb; j < i; ++j)
      a[j] = a[j + 1] - a[j];
    --lb;
    while (lb + 1 < i && !a[lb + 1]) ++lb;
    sort(a + lb, a + i);
  }
  printf("%d\n", a[1]);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T = 1;
  read(T);
  while (T--) single();
  return 0;
}