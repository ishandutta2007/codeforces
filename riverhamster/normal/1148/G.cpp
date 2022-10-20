#pragma GCC optimize(3)
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <random>
#include <unistd.h>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

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
const int V = 1e7 + 5;

int a[N];
int d[V];
bool np[V];
bool vis[N];
int ans[N];

mt19937 rng;
int R(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

void suffix_sum(int n) {
  for (int i = 2; i <= 1000000; ++i) {
    if (!np[i]) {
      for (int j = i * 2; j <= n; j += i)
        np[j] = true;
      for (int j = n / i; j >= 1; --j)
        d[j] += d[j * i];
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, k;
  read(n, k);
  for (int i = 1; i <= n; ++i)
    read(a[i]), ++d[a[i]];
  suffix_sum(1e7);
  for (int i = 2; i <= 10000000; ++i)
    if (d[i] >= k) {
      for (int j = 1, cnt = 0; j <= n && cnt < k; ++j)
        if (a[j] % i == 0)
          printf("%d ", j), ++cnt;
      putchar('\n');
      return 0;
    }
  int cnt = 0, failure = 0;
  while (cnt < k) {
    int x = R(1, n);
    if (vis[x]) continue;
    if (cnt) {
      bool ok = false;
      for (int i = 1; i <= n; ++i)
        if (vis[i] && gcd(a[i], a[x]) == 1) {
          ok = true;
          break;
        }
      if (!ok) {
        ++failure;
        if (failure > 8) {
          cnt = 0;
          failure = 0;
          memset(vis, 0, sizeof(vis));
          continue;
        }
        continue;
      }
    }
    ans[++cnt] = x;
    vis[x] = true;
    for (int i = 1; i <= n; ++i)
      if (!vis[i] && gcd(a[i], a[x]) == 1)
        vis[i] = true, ans[++cnt] = i;
  }
  for (int i = 1; i <= k; ++i)
    printf("%d ", ans[i]);
  putchar('\n');
  return 0;
}